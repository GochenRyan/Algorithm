/*
解决思路
1. 采用全排列（分解子问题求排列）思路
2. 数组下标不等满足8皇后不同行
3. 数组内的值即为8皇后的列，赋值0-7，满足不同列
4. 只需找到满足不在同一对角线即可

*/

#include <iostream>

using namespace std;

void EightQueen(int* iColumnIndex, int iLeft, int& total)
{
    if (!iLeft)
    {
        bool bSatisfy = true;
        for (int i = 0; i < 8; ++i)
        {
            for (int j = i + 1; j < 8; ++j)
            {
                if ((i - j) == (*(iColumnIndex + i) - *(iColumnIndex + j))
                    || (i - j) == -(*(iColumnIndex + i) - *(iColumnIndex + j)))
                {
                    bSatisfy = false;
                }
            }
        }
        if (bSatisfy)
        {
            ++total;
        }
    }

    for (int i = 8 - iLeft; i < 8; ++i)
    {
        int temp = *(iColumnIndex + i);
        *(iColumnIndex + i) = *(iColumnIndex + 8 - iLeft);
        *(iColumnIndex + 8 - iLeft) = temp;

        EightQueen(iColumnIndex, iLeft - 1, total);

        temp = *(iColumnIndex + i);
        *(iColumnIndex + i) = *(iColumnIndex + 8 - iLeft);
        *(iColumnIndex + 8 - iLeft) = temp;
    }
}

int main()
{
    int iColumnIndex[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int total = 0;
    EightQueen(iColumnIndex, 8, total);
    cout << total << endl;
    return 0;
}
