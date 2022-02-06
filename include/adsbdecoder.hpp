// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 06 Feb 2022
//

namespace aviware
{
    namespace adsb
    {
        class AdsbDecoder
        {
        public:
            static AdsbDecoder& get();

            AdsbDecoder(AdsbDecoder const&) = delete;

            void operator=(AdsbDecoder const&) = delete;
        private:
            AdsbDecoder() {}

        }; // class AdsbDecoder;
    } // namespace adsb
    
} // namespace aviware
