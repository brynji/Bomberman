#include "PowerUp.h"

class BonusHp : public PowerUp {
    /**
     * Called when player steps on powerUp and powerUpHandler chooses to pick this powerUp
     * @param pl player which should receive powerUp
     * @return name of this powerUp for UI to print
     */
    std::string pickUp(Character & pl) override;
};