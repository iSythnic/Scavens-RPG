#pragma once
#include <iostream>


template <typename T>

class Vec2D{
    
    public:

        Vec2D();
        Vec2D(T t_X, T t_Y);
        Vec2D(const Vec2D<T> &t_Vec2D);

        Vec2D<T>& operator=(const Vec2D<T> &t_Vec2D);

        Vec2D<T>& operator+=(const Vec2D<T> &t_Vec2D);
        Vec2D<T>& operator-=(const Vec2D<T> &t_Vec2D);
        Vec2D<T>& operator*=(const Vec2D<T> &t_Vec2D);
        Vec2D<T>& operator/=(const Vec2D<T> &t_Vec2D);
        template <typename U>
        friend Vec2D<U>& operator+(Vec2D<U> &t_Vec1, const Vec2D<U> &t_Vec2);
        template <typename U>
        friend Vec2D<U>& operator-(Vec2D<U> &t_Vec1, const Vec2D<U> &t_Vec2);
        template <typename U>
        friend Vec2D<U>& operator*(Vec2D<U> &t_Vec1, const Vec2D<U> &t_Vec2);
        template <typename U>
        friend Vec2D<U>& operator/(Vec2D<U> &t_Vec1, const Vec2D<U> &t_Vec2);

        template <typename U>
        friend std::ostream& operator<<(std::ostream &t_Output, const Vec2D<U> &t_Vec2D);
        template <typename U>
        friend std::istream& operator>>(std::istream &t_Input, Vec2D<U> &t_Vec2D);

    public:

    T m_X,m_Y;
};


template <typename T>
Vec2D<T>::Vec2D() : m_X(0),m_Y(0) {}

template <typename T>
Vec2D<T>::Vec2D(T t_X, T t_Y) : m_X(t_X), m_Y(t_Y) {}

template <typename T>
Vec2D<T>::Vec2D(const Vec2D<T> &t_Vec2D) : m_X(t_Vec2D.m_X), m_Y(t_Vec2D.m_Y) {}

template <typename T>
Vec2D<T>& Vec2D<T>::operator=(const Vec2D<T> &t_Vec2D)
{
    m_X = t_Vec2D.m_X;
    m_Y = t_Vec2D.m_Y;

    return *this;
}

template <typename T>
Vec2D<T>& operator+(Vec2D<T> &t_Vec1, const Vec2D<T> &t_Vec2)
{
    t_Vec1 += t_Vec2;
    return t_Vec1;
}

template <typename T>
Vec2D<T>& operator-(Vec2D<T> &t_Vec1, const Vec2D<T> &t_Vec2)
{
    t_Vec1 -= t_Vec2;
    return t_Vec1;
}

template <typename T>
Vec2D<T>& operator*(Vec2D<T> &t_Vec1, const Vec2D<T> &t_Vec2)
{
    t_Vec1 *= t_Vec2;
    return t_Vec1;
}

template <typename T>
Vec2D<T>& operator/(Vec2D<T> &t_Vec1, const Vec2D<T> &t_Vec2)
{
    t_Vec1 /= t_Vec2;
    return t_Vec1;
}

template <typename T>
Vec2D<T>& Vec2D<T>::operator+=(const Vec2D<T> &t_Vec2D)
{
    m_X += t_Vec2D.m_X;
    m_Y += t_Vec2D.m_Y;

    return *this;
}

template <typename T>
Vec2D<T>& Vec2D<T>::operator-=(const Vec2D<T> &t_Vec2D)
{
    m_X -= t_Vec2D.m_X;
    m_Y -= t_Vec2D.m_Y;

    return *this;
}

template <typename T>
Vec2D<T>& Vec2D<T>::operator*=(const Vec2D<T> &t_Vec2D)
{
    m_X *= t_Vec2D.m_X;
    m_Y *= t_Vec2D.m_Y;

    return *this;
}

template <typename T>
Vec2D<T>& Vec2D<T>::operator/=(const Vec2D<T> &t_Vec2D)
{
    m_X /= t_Vec2D.m_X;
    m_Y /= t_Vec2D.m_Y;

    return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream &t_Output, const Vec2D<T> &t_Vec2D)
{
    t_Output << "( " << t_Vec2D.m_X << ", " << t_Vec2D.m_Y << " )";
    return t_Output;
}

template <typename T>
std::istream& operator<<(std::istream &t_Input, Vec2D<T> &t_Vec2D)
{
    t_Input >> t_Vec2D.m_X >> t_Vec2D.m_Y;
    return t_Input;
}