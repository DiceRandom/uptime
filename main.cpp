#include <iostream>
#include <sysinfoapi.h>
#include <chrono>
#include <string> 

using namespace std;

string addZero(int base){
    string stringBase = to_string(base);
    if(base < 10){
        stringBase.insert(0,"0");
    }

    return stringBase;
}


int main()
{
    

    auto uptime = std::chrono::milliseconds(GetTickCount());
    auto bootTime = std::chrono::system_clock::now() - uptime;

    float milSec = uptime.count();

    int hours = milSec / 3600000;

    int mins = (milSec / 60000);
    for (int i = 0; i < hours; i++)
    {
        mins = mins - 60;

    }

    int secs = milSec / 1000;
    for (int i = 0; i < hours; i++)
    {
        float tempmins = hours * 60;
        float mints = (milSec / 60000) - tempmins;
        float seconds = mints * 60;
        for (float y = mints; seconds > 59; y--)
        {
            seconds = seconds - 60;
        }
        secs = seconds;
    }
    


    cout 
    << "Your PC has been on for "
    << addZero(hours)
    << ":"
    << addZero(mins)
    << ":"
    << addZero(secs)
    << endl;
}
