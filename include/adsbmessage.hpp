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
        struct AdsbDownlinkFormat
        {
            std::bitset<5> data;
        }; // struct DownlinkFormat

        struct AdsbCapability
        {
            std::bitset<3> data;
        }; // struct Capability

        struct AdsbIcaoAircraftAddress
        {
            std::bitset<24> data;
        }; // struct IcaoAircraftAddress

        struct AdsbData
        {
            void compute();

            std::bitset<56> data;
            std::bitset<5> tc;
            std::bitset<3> ec;
            std::array<std::bitset<6>, 8> content;
        }; // struct Data

        struct AdsbParity
        {
            std::bitset<24> data;
        }; // struct Parity

        struct AdsbMessage
        {
            void compute();

            void setRawMessage(std::bitset<112> message);

            AdsbDownlinkFormat format;

            AdsbCapability capability;

            AdsbIcaoAircraftAddress address;

            AdsbData data;

            AdsbParity parity;
        }; // struct AdsbMessage

    } // namespace adsb
    
} // namespace aviware
