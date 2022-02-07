// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 07 Feb 2022
//

#include <iostream>
#include <sstream>

#include "adsbdecoder.hpp"
#include "adsbhandler.hpp"
#include "adsbmessage.hpp"

using namespace aviware::adsb;

AdsbHandler::AdsbHandler() :
    m_decoder(std::make_shared<AdsbDecoder>()),
    m_message(std::make_shared<AdsbMessage>())
{

}

AdsbHandler::~AdsbHandler()
{

}

void AdsbHandler::setData(const std::string& data)
{
    m_data = data;
    createRawMessage();
    setDecoderData();
    newData = true;
}

void AdsbHandler::update()
{
    // Only Print Data if new Message is received
    if (newData)
    {
        printMessage();
        newData = false;
    }else
    {
        return;
    }
}

void AdsbHandler::setDecoderData()
{
    m_decoder->setMessage(m_message.get());
}

void AdsbHandler::createRawMessage()
{   
    constexpr size_t offset = 4;
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
            m_rawMessage[j + i * offset] = tempData[3 - j];
        }
        tempData.reset();
    }

    m_message->setRawMessage(m_rawMessage);
    
    m_rawMessage.reset();
}

void AdsbHandler::printMessage()
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