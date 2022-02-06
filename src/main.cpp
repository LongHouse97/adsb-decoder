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
    std::string data = "8d3b756b251811b4c39e6082017d";

    aviware::adsb::AdsbCore core(data.c_str());

    core.printMessage();

    return 0;
}