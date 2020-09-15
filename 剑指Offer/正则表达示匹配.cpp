/*
Ҫ��Ϊ���������
��1�����ڶ����ַ���Ϊ��*��ʱ��ƥ����ǽ��ַ�����ģʽ��ָ�붼����һ������ƥ���ֱ�ӷ���false
��2�����ڶ����ַ�Ϊ'*'ʱ��
        ƥ�䣺
                a.�ַ�������һ����ģʽ����
                b.�ַ���������ģʽ��������
                c.�ַ�������һ����ģʽ�������� ��������a��b��ϣ�
        ��ƥ�䣺�ַ������Ʋ�����ģʽ��������
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