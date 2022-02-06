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
    {   // Default Message if no Message is passed in
        data = "8d3b756b251811b4c39e6082017d";
    }else
    {   // Use passed message
        data = argv[1];
    }
    // instantiate core 
    aviware::adsb::AdsbCore core;
    core.setData(data.c_str());
    core.compute();
    
    // print ADS-B Message on console
    core.printMessage();

    return 0;
}