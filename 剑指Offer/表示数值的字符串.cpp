/*
A[.[B]][e|EC]
���������
    1. A.
    2. .B

���������str�ĵ�ַ���������޷��ı�str�е����ݣ�ch�д����strָ����ڴ�ĵ�ַ
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
���Դ��룺

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