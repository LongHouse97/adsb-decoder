// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 06 Feb 2022
//

#include <string>

#include "adsbhandlerfwd.hpp"

namespace aviware
{
    namespace adsb
    {
        class AdsbCore
        {
        public:
            AdsbCore();

            ~AdsbCore();

            void setData(const std::string &data);

            void setData();

            void update();

        private:

            AdsbHandlerPtr m_handler = nullptr;

            std::string m_data;

        }; // class AdsbCore
    } // namespace adsb
    
} // namespace aviware
