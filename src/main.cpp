// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 06 Feb 2022
//

#include <sstream>
#include <string>

#include "adsbcore.hpp"

int main(int argc, char** argv)
{   
    std::string data = "";
    if(argc < 2)
    {
        data = "8d3b756b251811b4c39e6082017d";
    }else
    {
        data = argv[1];
    }

    aviware::adsb::AdsbCore core(data.c_str());

    core.printMessage();

    return 0;
}