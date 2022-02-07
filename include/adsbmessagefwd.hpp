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
        struct AdsbMessage;

        using AdsbMessagePtr = std::shared_ptr<AdsbMessage>;
    } // namespace adsb
    
} // namespace aviware