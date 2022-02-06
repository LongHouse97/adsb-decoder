// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 06 Feb 2022
//

#include <bitset>
#include <iostream>
#include <sstream>
#include <string>

#include "adsbcore.hpp"
#include "adsbdecoder.hpp"

using namespace aviware::adsb;

AdsbCore::AdsbCore(const std::string& data) :
    m_data(data),
    m_decoder(std::make_shared<AdsbDecoder>())
{
    initialize();
}

AdsbCore::~AdsbCore()
{

}

void AdsbCore::initialize()
{
    compute();
}

void AdsbCore::compute()
{
    createRawMessage();
    m_decoder->setMessage(&m_message);
}

void AdsbCore::setData(const std::string& data)
{
    m_data = data;
    createRawMessage();
}

void AdsbCore::createRawMessage()
{
    constexpr size_t count = 112;
    constexpr size_t offset = 4;
    std::bitset<count> rawMessage;
    std::bitset<4> tempData;

    // Compute Bitset from Hex Data
    for (size_t i = 0; i < 28; i++)
    {
        int value;

        std::stringstream ss;
        ss << std::hex << m_data.at(i);
        ss >> value;

        tempData = value;
        
        for (size_t j = 0; j < offset; j++)
        {
            rawMessage[j + i * offset] = tempData[3 - j];
        }
    }

    m_message.setRawMessage(rawMessage);    
}

void AdsbCore::printMessage()
{
    int format = 0;
    m_decoder->downlinkFormat(format);
    if(format == 17)
    {
        std::cout << "Downlink Format: " << format << " (ADS-B Message)" << std::endl;
    }else
    {
        std::cout << "No ADS-B Message - exiting...\n";
        return;
    }
    
    auto tcResult = m_decoder->typeCode();
    std::cout << "TypeCode: " << std::get<0>(tcResult) << " | " << std::get<1>(tcResult) << std::endl;

    char callsign[9];
    m_decoder->callsign(callsign);
    std::cout << "Callsign: " << callsign << std::endl;

    auto ecResult = m_decoder->emitterCategory();
    std::cout << "Emitter Code: " << std::get<0>(ecResult) << " | " << std::get<1>(ecResult) << std::endl;

}