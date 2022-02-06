// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 06 Feb 2022
//

#include <string>
#include <tuple>

namespace aviware
{
    namespace adsb
    {
        struct AdsbMessage;

        class AdsbDecoder
        {
        public:
            AdsbDecoder();

            ~AdsbDecoder();

            void setMessage(AdsbMessage* message) { m_message = message; }

            void callsign(char* callsign);

            void downlinkFormat(int &format);

            std::tuple<int, std::string> typeCode();

            std::tuple<int, std::string> emitterCategory();

        private:

            AdsbMessage* m_message;

        }; // class AdsbDecoder;
    } // namespace adsb
    
} // namespace aviware
