// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 06 Feb 2022
//

#include "adsbmessage.hpp"

using namespace aviware::adsb;

void AdsbMessage::compute()
{
    data.compute();
}

void AdsbMessage::setRawMessage(std::bitset<112> message)
{
    for (size_t i = 0; i < 5; i++)
    {
        format.data[i] = message[i];
    }

    for (size_t i = 0; i < 3; i++)
    {
        capability.data[i] = message[i + 5];
    }
    for (size_t i = 0; i < 24; i++)
    {
        address.data[i] = message[i + 8];
    }
    for (size_t i = 0; i < 56; i++)
    {
        data.data[i] = message[i + 32];
    }
    
    for (size_t i = 0; i < 24; i++)
    {
        parity.data[i] = message[i + 88];
    }

    compute();
}

void AdsbData::compute()
{
    int offset = 8;
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 6; j++)
        {
            content.at(i)[5 - j] = data[j + offset];
        }
        offset += 6;
    }

    for (size_t i = 0; i < 5; i++)
    {
        tc[i] = data[i];
    }
    
    for (size_t i = 0; i < 3; i++)
    {
        ec[i] = data[i + 5];
    }
}