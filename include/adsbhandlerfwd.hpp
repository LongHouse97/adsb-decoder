// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 07 Feb 2022
//

#include <memory>

namespace aviware
{
    namespace adsb
    {
        class AdsbHandler;

        using AdsbHandlerPtr = std::shared_ptr<AdsbHandler>;
    } // namespace adsb
    
} // namespace aviware