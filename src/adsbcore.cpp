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
    fillMessage();
    m_decoder->setMessage(&m_message);
}

void AdsbCore::update()
{
    fillMessage();
    m_decoder->setMessage(&m_message);
}

void AdsbCore::fillMessage()
{
    constexpr size_t count = 112;
    constexpr size_t offset = 4;
    std::bitset<count> data;
    std::bitset<4> tempData;

    for (size_t i = 0; i < 28; i++)
    {
        int value;

        std::stringstream ss;
        ss << std::hex << m_data.at(i);
        ss >> value;

        tempData = value;
        
        for (size_t j = 0; j < offset; j++)
        {
            data[j + i * offset] = tempData[3 - j];
        }
    }

    for (size_t i = 0; i < 5; i++)
    {
        m_message.format.data[i] = data[i];
    }
    for (size_t i = 0; i < 3; i++)
    {
        m_message.capability.data[i] = data[i + 5];
    }
    for (size_t i = 0; i < 24; i++)
    {
        m_message.address.data[i] = data[i + 8];
    }
    for (size_t i = 0; i < 56; i++)
    {
        m_message.data.data[i] = data[i + 32];
    }

    int cOffset = 8;
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 6; j++)
        {
            m_message.data.content.at(i)[5 - j] = m_message.data.data[j + cOffset];
        }
        cOffset += 6;
    }
    

    for (size_t i = 0; i < 5; i++)
    {
        m_message.data.tc[i] = m_message.data.data[i];
    }
    
    for (size_t i = 0; i < 3; i++)
    {
        m_message.data.ec[i] = m_message.data.data[i + 5];
    }
    
    for (size_t i = 0; i < 24; i++)
    {
        m_message.parity.data[i] = data[i + 88];
    }
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