#include "TimeEvents.h"


//After some changes, this class may not be used at all and these methods will be deleted!!


void TimeEvents::add(unsigned int time, std::function<void()> fn){
        uint64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        if(events.insert({now+time,fn}).second==false) add(time,fn);
    }

void TimeEvents::check(){
    uint64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    while(events.begin()->first<now){
        events.begin()->second();
        events.erase(events.begin());
    }
}