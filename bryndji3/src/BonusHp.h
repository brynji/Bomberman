#include "PowerUp.h"

class BonusHp : public PowerUp {
    std::string pickUp(Character & pl) override;
};