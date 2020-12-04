#pragma once
#include "virtual method.hpp"

class Engine
{
public:
    VIRTUAL(int, getPlayerForUserID, 9, (int uid), (this, uid))
    VIRTUAL(int, getLocalPlayer, 12, (), (this))
};
