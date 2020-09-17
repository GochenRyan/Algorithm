/*
    用 P(i,j)表示字符串 s 的第 i 到 j 个字母组成的串状态转移方程：
        p(i,j) = p(i+1, j-1) && (s[i] == s[j])
    边界条件：
        p(i,i) = true
        p(i,i+1) = (s[i] == s[i + 1])
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size == 0)
            return "";

        int maxLen = 1;
        string palindrome = s.substr(0, 1);

        bool dp[size][size];
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                dp[i][j] = false;
            }
        }

        for (int l = 0; l < size; ++l)
        {
            for (int i = 0; i + l < size; ++i)
            {
                int j = i + l;
                if (i == j)
                {
                    dp[i][j] = true;
                }
                else if (j == i + 1 && s[i] == s[j])
                {
                    dp[i][j] = true;
                    maxLen = 2;
                    palindrome = s.substr(i, 2);
                }
                else if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    int length = j - i + 1;
                    if (length > maxLen)
                    {
                        maxLen = length;
                        palindrome = s.substr(i, maxLen);
                    }
                }
            }
        }

        return palindrome;
    }
};