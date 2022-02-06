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
            AdsbDecoder();

            ~AdsbDecoder();

            void setMessage(AdsbMessage* message) { m_message = message; }

            void callsign(char* callsign);

            void downlinkFormat(int &format);

            void typeCode(int &code, std::string &content);

            void emitterCategory(int &code, std::string &category);

        private:

            AdsbMessage* m_message;

        }; // class AdsbDecoder;
    } // namespace adsb
    
} // namespace aviware
