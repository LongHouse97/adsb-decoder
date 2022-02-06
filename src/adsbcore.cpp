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

    for (size_t i = 0; i < 6; i++)
    {
        m_message.data.c1[5 - i] = m_message.data.data[i + 8];
        m_message.data.c2[5 - i] = m_message.data.data[i + 14];
        m_message.data.c3[5 - i] = m_message.data.data[i + 20];
        m_message.data.c4[5 - i] = m_message.data.data[i + 26];
        m_message.data.c5[5 - i] = m_message.data.data[i + 32];
        m_message.data.c6[5 - i] = m_message.data.data[i + 38];
        m_message.data.c7[5 - i] = m_message.data.data[i + 44];
        m_message.data.c8[5 - i] = m_message.data.data[i + 50]; 
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
    
    int typeCode = 0;
    std::string tcContent = "";
    m_decoder->typeCode(typeCode, tcContent);
    std::cout << "TypeCode: " << typeCode << " | " << tcContent << std::endl;

    char callsign[9];
    m_decoder->callsign(callsign);
    std::cout << "Callsign: " << callsign << std::endl;

    int emitterCode = 0;
    std::string ecContent = "";
    m_decoder->emitterCategory(emitterCode, ecContent);
    std::cout << "Emitter Code: " << emitterCode << " | " << ecContent << std::endl;

}