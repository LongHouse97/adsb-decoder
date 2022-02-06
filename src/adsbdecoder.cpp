// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 06 Feb 2022
//

#include "adsbdecoder.hpp"

using namespace aviware::adsb;

AdsbDecoder& AdsbDecoder::get()
{
    static AdsbDecoder instance;

    return instance;
}