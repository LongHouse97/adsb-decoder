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

            void setData(const std::string& data);

            void compute();
        private:
            
            void initialize();

            void createRawMessage();

            std::string m_data;

            AdsbMessage m_message;

            AdsbDecoderPtr m_decoder = nullptr;
        }; // class AdsbCore
    } // namespace adsb
    
} // namespace aviware
