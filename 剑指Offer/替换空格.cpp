/*
从后往前插入
length为容量，不是字符串长度
*/
class Solution {
public:
    void replaceSpace(char* str, int length) {
        if (str == nullptr || length <= 0)
            return;
        int spaceNum = 0;
        int oldLength = 0;
        for (int i = 0; str[i] != '\0'; ++i)
        {
            ++oldLength;
            if (str[i] == ' ')
                ++spaceNum;
        }
        int newLength = oldLength + spaceNum * 2;
        if (newLength > length)
            return;
        int j = newLength;
        for (int i = oldLength; i >= 0; --i)
        {
            if (str[i] == ' ')
            {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            }
            else
            {
                str[j--] = str[i];
            }
        }
    }
};