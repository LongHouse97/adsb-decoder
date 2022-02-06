// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 06 Feb 2022
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "adsbcore.hpp"

int main(int argc, char** argv)
{
    //std::string data = "8d 3b756b 25 18 11 b4 c3 9e 60 82017d";
    std::string data = "8d3b756b251811b4c39e6082017d";
/*
    10001
    101
    001110110111010101101011
    00100 101 000110 000001 000110 110100 110000 111001 111001 100000
    100000100000000101111101
*/

    


    aviware::adsb::AdsbCore core(data.c_str());

    core.printMessage();

    return 0;
}