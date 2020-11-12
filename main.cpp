#include <iostream>
#include "dynamicstring.h"

using namespace std;

/**
 * @todo
 * 1. Написать на С++ 11 без сторонних библиотек класс динамичексих строк,
 *    без умных указателей и STL
 * 2. Класс не шаблонный. Поддерживает строки произвольного размера, с использованием стандартных операций над памятью (new/delete)
 * 3. Имеет конструктор копирования
 * 4. Поддерживает move-семантику
 * 5. Имеет внешний оператор сложения двух строк
 *
 * @todo
 * Написать прогу, которая принимает контейнер STL DynamicString-ов и возвращает их в порядке, обратном лексикографическому
 * Для этого нужен компаратор
 **/

int main()
{
    DynamicString s {"Hello world!"}, s2 = "aaa";
    cout << "String 1: " << s << endl;
    cout << "String 2: " << s2 << endl;
    DynamicString s_cpy = s;

    cout << "Copy of String 1: " << s_cpy << endl;

    DynamicString sum_str = s + s2;

    cout << "Sum of strings: " << sum_str << endl;

    cin.get();
    return 0;
}
