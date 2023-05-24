#pragma once
#include <array>
#include <string>

class GameObject{
    public:
    GameObject(int nColorPair, const std::array<std::string,3>& nIcon);
    virtual ~GameObject() noexcept = default;

    //Called when bomb hits the tile this object is on
    virtual void hit()=0;
    
    //Called when player tries to step on this gameObject, return value - false-> player can't step here. true-> player can step here
    //May be used in future for some special types of objects
    virtual bool stepOn()=0;

    int colorPair;
    std::array<std::string,3> icon;
};