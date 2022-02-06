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