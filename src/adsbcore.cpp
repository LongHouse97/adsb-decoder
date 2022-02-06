// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 06 Feb 2022
//

#include <bitset>
#include <iostream>
#include <sstream>

#include "adsbcore.hpp"

using namespace aviware::adsb;

AdsbCore::AdsbCore(const std::string& data) :
    m_data(data)
{
    fillMessage();
}

AdsbCore::~AdsbCore()
{

}

void AdsbCore::fillMessage()
{
    constexpr size_t count = 112;
    constexpr size_t offset = 4;
    std::bitset<count> data;
    std::bitset<4> tempData;

    for (size_t i = 0; i < 28; i++)
    {
        int8_t value;
        std::stringstream ss;
        ss << std::hex << m_data.at(i);
        ss >> value;
        tempData = value;
        for (size_t j = 0; j < offset; j++)
        {
            data[j + i * offset] = tempData[j];
        }
    }

    std::cout << std::endl << data << std::endl;

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
    for (size_t i = 0; i < 24; i++)
    {
        m_message.parity.data[i] = data[i + 88];
    }
}

void AdsbCore::printMessage()
{
    std::cout << m_message.data.data;
}