#pragma once

#include "Components.hpp"

class Player{

    public:
    
        Player() = delete;
        Player(const Vec2D<int> &t_Cord, unsigned int t_BoxSize);
        void initPhysical();
        void initCurrency();

    private:

        PhysicalStatus m_PhysicalStatus;
        CurrencyStatus m_CurrencyStatus;
        Vec2D<int>     m_Cord;
        unsigned int   m_BoxSize;

};