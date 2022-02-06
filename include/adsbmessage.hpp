// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 06 Feb 2022
//

#include <array>
#include <bitset>
#include <cstdint>

namespace aviware
{
    namespace adsb
    {
        struct DownlinkFormat
        {
            std::bitset<5> data;
        }; // struct DownlinkFormat

        struct Capability
        {
            std::bitset<3> data;
        }; // struct Capability

        struct IcaoAircraftAddress
        {
            std::bitset<24> data;
        }; // struct IcaoAircraftAddress

        struct Data
        {
            std::bitset<56> data;
            std::bitset<5> tc;
            std::bitset<3> ec;
            std::array<std::bitset<6>, 8> content;
        }; // struct Data

        struct Parity
        {
            std::bitset<24> data;
        }; // struct Parity

        struct AdsbMessage
        {
            DownlinkFormat format;

            Capability capability;

            IcaoAircraftAddress address;

            Data data;

            Parity parity;
        }; // struct AdsbMessage

    } // namespace adsb
    
} // namespace aviware
