// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 06 Feb 2022
//

#include "adsbcore.hpp"
#include "adsbhandler.hpp"

using namespace aviware::adsb;

AdsbCore::AdsbCore() :
    m_handler(std::make_shared<AdsbHandler>())
{

}

AdsbCore::~AdsbCore()
{

}

void AdsbCore::update()
{
    m_handler->update();
}

void AdsbCore::setData(const std::string &data)
{
    m_data = data;
    setData();
}

void AdsbCore::setData()
{   
    m_handler->setData(m_data);
}