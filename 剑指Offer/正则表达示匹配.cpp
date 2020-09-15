/*
要分为几种情况：
（1）当第二个字符不为‘*’时：匹配就是将字符串和模式的指针都下移一个，不匹配就直接返回false
（2）当第二个字符为'*'时：
        匹配：
                a.字符串下移一个，模式不动
                b.字符串不动，模式下移两个
                c.字符串下移一个，模式下移两个 （可以由a、b组合）
        不匹配：字符串下移不动，模式下移两个
*/

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (str == nullptr || pattern == nullptr)
            return true;
        return matchCore(str, pattern);
    }

    bool matchCore(char* str, char* pattern)
    {
        if (*str == '\0' && *pattern == '\0')
            return true;

        if (*str != '\0' && *pattern == '\0')
            return false;

        if (*(pattern + 1) == '*')
        {
            if (*pattern == *str || (*pattern == '.' && *str != '\0'))
                return matchCore(str, pattern + 2) ||
                matchCore(str + 1, pattern);
            else
                return matchCore(str, pattern + 2);
        }
        else if (*pattern == *str || (*pattern == '.' && *str != '\0'))
            return matchCore(str + 1, pattern + 1);
        else
            return false;
    }
};