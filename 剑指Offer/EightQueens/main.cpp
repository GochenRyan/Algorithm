/*
���˼·
1. ����ȫ���У��ֽ������������У�˼·
2. �����±겻������8�ʺ�ͬ��
3. �����ڵ�ֵ��Ϊ8�ʺ���У���ֵ0-7�����㲻ͬ��
4. ֻ���ҵ����㲻��ͬһ�Խ��߼���

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
