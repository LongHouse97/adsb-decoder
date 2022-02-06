// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 06 Feb 2022
//

#include "adsbdecoder.hpp"
#include "adsbmessage.hpp"

using namespace aviware::adsb;

AdsbDecoder& AdsbDecoder::get()
{
    static AdsbDecoder instance;

    return instance;
}

void AdsbDecoder::callsign(char* callsign, AdsbMessage* message)
{
    callsign[8] = '\0';

    message->data.c1.to_ulong() < 27 ? 
        callsign[0] = char(message->data.c1.to_ulong() + 64) :
        callsign[0] = char(message->data.c1.to_ulong());
    message->data.c2.to_ulong() < 27 ? 
        callsign[1] = char(message->data.c2.to_ulong() + 64) :
        callsign[1] = char(message->data.c2.to_ulong());
    message->data.c3.to_ulong() < 27 ? 
        callsign[2] = char(message->data.c3.to_ulong() + 64) :
        callsign[2] = char(message->data.c3.to_ulong());
    message->data.c4.to_ulong() < 27 ? 
        callsign[3] = char(message->data.c4.to_ulong() + 64) :
        callsign[3] = char(message->data.c4.to_ulong());
    message->data.c5.to_ulong() < 27 ? 
        callsign[4] = char(message->data.c5.to_ulong() + 64) :
        callsign[4] = char(message->data.c5.to_ulong());
    message->data.c6.to_ulong() < 27 ? 
        callsign[5] = char(message->data.c6.to_ulong() + 64) :
        callsign[5] = char(message->data.c6.to_ulong());
    message->data.c7.to_ulong() < 27 ? 
        callsign[6] = char(message->data.c7.to_ulong() + 64) :
        callsign[6] = char(message->data.c7.to_ulong());
    message->data.c8.to_ulong() < 27 ? 
        callsign[7] = char(message->data.c8.to_ulong() + 64) :
        callsign[7] = char(message->data.c8.to_ulong());
}

void AdsbDecoder::downlinkFormat(int &format, AdsbMessage* message)
{
    format = message->format.data.to_ulong();
}