#pragma once

class PhysicalStatus{

    public:

        PhysicalStatus();
        PhysicalStatus(int &t_HealthPoint, int &t_Damage, int &t_Level, int &t_Experience, int &t_Defense, int &t_MagicPoint);

    public:

        int m_HealthPoint;
        int m_Damage;
        int m_Level;
        int m_Experience;
        int m_Defense;
        int m_MagicPoint;

};