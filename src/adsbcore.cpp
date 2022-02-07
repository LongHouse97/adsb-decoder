// 
// (C) aviware 2022
// Author: Arian Ghoddousi
// Contact: arian.ghoddousi@aviware.net 
// Date: 06 Feb 2022
//

#include <iostream>
#include <thread>

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

void AdsbCore::run()
{
    //std::thread handlerThread(&AdsbHandler::run, m_handler.get());
    while(true)
    {
        std::string data = "";
        std::cout << "\n\nEnter ADS-B Message: ";
        std::cin >> data;
        std::cout << "\n";
        setData(data);
        update();
    }
    //handlerThread.join();
}

void AdsbCore::cycleOnce()
{
    update();
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