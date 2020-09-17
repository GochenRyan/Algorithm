/*
A[.[B]][e|EC]
特殊情况：
    1. A.
    2. .B

如果不传入str的地址，函数内无法改变str中的内容，ch中存的是str指向的内存的地址
*/
class Solution {
public:
    bool isNumeric(const char* str)
    {
        if (str == nullptr)
            return false;

        bool bNumeric = isInteger(&str);

        if (*str == '.')
        {
            ++str;
            bNumeric = isUnsignedInteger(&str) || bNumeric;
        }

        if (*str == 'e' || *str == 'E')
        {
            ++str;
            bNumeric = bNumeric && isInteger(&str);
        }

        if (*str != '\0')
            bNumeric = false;

        return bNumeric;
    }

    bool isInteger(const char** ch)
    {
        if (**ch == '+' || **ch == '-')
            ++(*ch);
        return isUnsignedInteger(ch);
    }

    bool isUnsignedInteger(const char** ch)
    {
        const char* before = *ch;
        while (**ch >= '0' && **ch <= '9')
        {
            ++(*ch);
        }
        return before < *ch;
    }
};

/*
测试代码：

#include <iostream>

using namespace std;

bool isUnsignedInteger(const char* ch)
{
    const char* before = ch;
    while (*ch >= '0' && *ch <= '9')
    {
        cout << "-----isUnsignedInteger: " << *ch << endl;
        ++ch;
    }
    return before < ch;
}

bool isInteger(const char* ch)
{
    cout << "------the addr in ch, ch: " << (int)ch << ", " << (int)&ch << endl;
    if (*ch == '+' || *ch == '-')
        ++(ch);
    return isUnsignedInteger(ch);
}

bool isNumeric(const char* str)
{
    if (str == nullptr)
        return false;


    cout << "------the addr in str, str: " << (int)str << ", " << (int)&str << endl;
    bool bNumeric = isInteger(str);

    if (*str == '.')
    {
        ++str;
        bNumeric = isUnsignedInteger(str) || bNumeric;
    }

    if (*str == 'e' || *str == 'E')
    {
        ++str;
        bNumeric = bNumeric && isInteger(str);
    }

    cout << "------isNumeric: " << bNumeric << endl;
    if (*str != '\0')
        cout << "-------not end" << endl;
    bNumeric = false;

    return bNumeric;
}


int main()
{
    cout << "------main: " << isNumeric("100") << endl;
    return 0;
}
*/