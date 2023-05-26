#include "../PowerUp.h"

class BiggerExplosion : PowerUp {
    BiggerExplosion(Player & nPl);

    void pickUp() override;
};