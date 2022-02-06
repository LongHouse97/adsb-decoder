// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 06 Feb 2022
//

#include <string>

#include "adsbdecoderfwd.hpp"
#include "adsbmessage.hpp"

namespace aviware
{
    namespace adsb
    {
        class AdsbCore
        {
        public:
            AdsbCore(const std::string& data);

            ~AdsbCore();

            void printMessage();

            void setData(const std::string& data) { m_data = data; }

            void update();
        private:
            
            void initialize();

            void fillMessage();

            void decode();

            std::string m_data;

            AdsbMessage m_message;

            AdsbDecoderPtr m_decoder = nullptr;
        }; // class AdsbCore
    } // namespace adsb
    
} // namespace aviware
