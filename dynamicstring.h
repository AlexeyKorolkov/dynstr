#ifndef DYNAMICSTRING_H
#define DYNAMICSTRING_H

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
typedef unsigned long long u_long;

class DynamicString
{
private:
    char* m_str;
public:
    // Конструктор (I перегрузка)
    DynamicString(char *str = nullptr) : m_str(new char[strlen(str)])
    {
        m_str = str;
        cout << "DynamicString() ctor" << endl;
    }

    // Конструктор (II перегрузка)
    DynamicString(const char *str = nullptr) : m_str(new char[strlen(str)])
    {
        strcpy(m_str, str);
        cout << "DynamicString(const char*) ctor" << endl;
    }

    // Конструктор копирования
    DynamicString(const DynamicString& other);
    // Конструктор перемещения
    DynamicString(DynamicString&& other) noexcept;

    virtual ~DynamicString() noexcept
    {
        cout << "~DynamicString() dtor" << endl;
        ofstream log("log.txt", ios::out | ios::app);
        delete [] m_str;
        log << "Object was deleted!\n";
        log.close();
    }

public:
    u_long length() const;
    DynamicString operator = (char* s1);
    friend ostream& operator << (ostream& out, const DynamicString &str);
    friend DynamicString operator + (const DynamicString& s1, const DynamicString& s2);
};

#endif // DYNAMICSTRING_H
