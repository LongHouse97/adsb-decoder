// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 07 Feb 2022
//

#include <bitset>
#include <string>

#include "adsbdecoderfwd.hpp"
#include "adsbmessagefwd.hpp"

namespace aviware
{
    namespace adsb
    {

        class AdsbHandler
        {
        public:
            AdsbHandler();

            ~AdsbHandler();

            void setData(const std::string& data);

            void update();

        private:

            void createRawMessage();

            void setDecoderData();

            void printMessage();

            AdsbDecoderPtr m_decoder = nullptr;

            AdsbMessagePtr m_message = nullptr;

            std::string m_data;

            std::bitset<112> m_rawMessage;

            bool newData = false;
        }; // class AdsbHandler
    } // namespace adsb
    
} // namespace aviware
