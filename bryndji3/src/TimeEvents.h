#pragma once
#include <chrono>
#include <map>
#include <functional>

//May not be used at all and deleted later
class TimeEvents{
    void add(unsigned int time, std::function<void()> fn);

    void check();

    std::map<uint64_t,std::function<void()>> events;
};