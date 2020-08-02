#include <iostream>

using namespace std;

bool isEqual(int* pPermu)
{
    bool bEqual1 = (*pPermu + *(pPermu + 1) + *(pPermu + 2) + *(pPermu + 3) == *(pPermu + 4) + *(pPermu + 5) + *(pPermu + 6) + *(pPermu + 7));
    bool bEqual2 = (*pPermu + *(pPermu + 1) + *(pPermu + 4) + *(pPermu + 5) == *(pPermu + 2) + *(pPermu + 3) + *(pPermu + 6) + *(pPermu + 7));
    bool bEqual3 = (*pPermu + *(pPermu + 3) + *(pPermu + 4) + *(pPermu + 7) == *(pPermu + 1) + *(pPermu + 2) + *(pPermu + 5) + *(pPermu + 6));
    if (bEqual1 && bEqual2 && bEqual3)
    {
        for (int i = 0; i < 8; ++i)
        {
            cout << *(pPermu + i);
        }
        cout << endl;
    }
}

void permutation(int* pWeight, int iLeft)
{
    if (!iLeft)
    {
        isEqual(pWeight);
    }
    for (int i = 8 - iLeft; i < 8; ++i)
    {
        // 先处理首个
        int temp = *(pWeight + i);
        *(pWeight + i) = *(pWeight + 8 - iLeft);
        *(pWeight + 8 - iLeft) = temp;

        // 再处理后面的
        permutation(pWeight, iLeft - 1);


        temp = *(pWeight + i);
        *(pWeight + i) = *(pWeight + 8 - iLeft);
        *(pWeight + 8 - iLeft) = temp;
    }

}

int main()
{
    int weight[8];
    int input;
    int i = 0;
    while(cin >> input)
    {
        weight[i] = input;
        if (++i == 8)
        {
            break;
        }
    }
    permutation(weight, 8);
    return 0;
}
