#include "PhysicalStatus.hpp"

PhysicalStatus::PhysicalStatus() : m_HealthPoint(0), m_Damage(0), m_Level(0), m_Experience(0), m_Defense(0), m_MagicPoint(0) {}

PhysicalStatus::PhysicalStatus(int &t_HealthPoint, int &t_Damage, int &t_Level, int &t_Experience, int &t_Defense, int &t_MagicPoint)
: m_HealthPoint(t_HealthPoint), m_Damage(t_Damage), m_Level(t_Level), m_Experience(t_Experience), m_Defense(t_Defense), m_MagicPoint(t_MagicPoint) {}

