#include "dynamicstring.h"

DynamicString::DynamicString(const DynamicString& other)
{
    m_str = new char[strlen(other.m_str)];
    strcpy(m_str, other.m_str);
}

DynamicString::DynamicString(DynamicString &&other) noexcept
{
    m_str = other.m_str;
    other.m_str = nullptr;
}

u_long DynamicString::length() const
{
    return strlen(m_str);
}

ostream& operator << (ostream& out, const DynamicString &str)
{
    out << str.m_str;
    return out;
}

DynamicString operator + (const DynamicString& s1, const DynamicString& s2)
{
    DynamicString res(s1);
    strcat(res.m_str, s2.m_str);
    return res;
}
