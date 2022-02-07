// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 06 Feb 2022
//

#include <iostream>

#include "adsbdecoder.hpp"
#include "adsbmessage.hpp"

using namespace aviware::adsb;

AdsbDecoder::AdsbDecoder()
{

}

AdsbDecoder::~AdsbDecoder()
{

}

std::string AdsbDecoder::dataContent()
{
    char msg[9];

    msg[8] = '\0';

    if (!m_message)
    {
        std::cout << "Error: Message not Set!\n";
        return "Error";
    }

    for (size_t i = 0; i < 8; i++)
    {
        m_message->data.content.at(i).to_ulong() < 27 ?
            msg[i] = char(m_message->data.content.at(i).to_ulong() + 64) :
            msg[i] = char(m_message->data.content.at(i).to_ulong());
    }
    return msg;
}

void AdsbDecoder::downlinkFormat(int &format)
{
    if (!m_message)
    {
        std::cout << "Error: Message not Set!\n";
        return;
    }
    format = m_message->format.data.to_ulong();
}

std::tuple<int, std::string> AdsbDecoder::emitterCategory()
{
    if (!m_message)
    {
        std::cout << "Error: Message not Set!\n";
        return std::make_tuple(-1, "Error");
    }
    int code = 0;
    std::string category = "";

    code = m_message->data.ec.to_ulong();

    switch (code)
    {
    case 0:
        category = "No ADS-B Emitter Category Information\0";
        break;
    case 1:
        category = "Light ( < 7030kg)\0";
        break;
    case 2:
        category = "Small (7030kg to 34019kg)\0";
        break; 
    case 3:
        category = "Large (34020kg to 136077kg)\0";
        break;
    case 4:
        category = "High-Vortex Large\0";
        break;
    case 5:
        category = "Heavy ( > 136078kg)\0";
        break;
    case 6:
        category = "High Performance ( > 5g accel | > 400kts)\0";
        break;
    case 7:
        category = "Rotorcraft\0";
        break;
    default:
        break;
    }

    return std::make_tuple(code, category);
}

std::tuple<int, std::string> AdsbDecoder::typeCode()
{
    if (!m_message)
    {
        std::cout << "Error: Message not Set!\n";
        return std::make_tuple(-1, "Error");
    }
    int code = 0;
    std::string content = "";
    code = m_message->data.tc.to_ulong();

    switch (code)
    {
    case 1: case 2: case 3:
    case 4:
        content = "Aircraft identification\0";
        break;
    case 5: case 6: case 7:
    case 8:
        content = "Surface position\0";
        break;
    case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17:
    case 18:
        content = "Airborne position (w/ Baro Altitude)\0";
        break;
    case 19:
        content = "Airborne velocities\0";
        break;
    case 20: case 21:
    case 22:
        content = "Airborne position (w/ GNSS Height)\0";
        break;
    case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30:
    case 31:
        content = "Reserved for other uses\0";
        break;
    default:
        content = "No valid type code!\0";
        break;
    }

    return std::make_tuple(code, content);
}