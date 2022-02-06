// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 06 Feb 2022
//

#include <string>

namespace aviware
{
    namespace adsb
    {
        struct AdsbMessage;

        class AdsbDecoder
        {
        public:
            static AdsbDecoder& get();

            AdsbDecoder(AdsbDecoder const&) = delete;

            void operator=(AdsbDecoder const&) = delete;

            void callsign(char* callsign, AdsbMessage* message);

            void downlinkFormat(int &format, AdsbMessage* message);

            void typeCode(int &code, std::string &content, AdsbMessage* message);

            void emitterCategory(int &code, std::string &category, AdsbMessage* message);
        private:
            AdsbDecoder() {}

        }; // class AdsbDecoder;
    } // namespace adsb
    
} // namespace aviware
