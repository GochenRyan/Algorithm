/* 
动态规划求解问题的四个特征： 
①求一个问题的最优解； 
②整体的问题的最优解是依赖于各个子问题的最优解； 
③子问题之间还有相互重叠的更小的子问题； 
④从上往下分析问题，从下往上求解问题

子问题的最优解，存在array数组里
*/

class Solution {
public:
    int cutRope(int number) {
        if (number < 2)
            return 0;
        else if (number == 2)
            return 1;
        else if (number == 3)
            return 2;
        int *array = new int[number + 1];
        array[0] = 0;
        array[1] = 1;
        array[2] = 2;
        array[3] = 3;
        
        int max = 0;
        for (int i = 4; i <= number; ++i)
        {
            for (int j = 1; j <= i / 2; ++j){
                int temp = array[j] * array[i - j];
                if (temp > max)
                    max = temp;
            }
            array[i] = max;
        }
        delete[] array;
        return max;
    }
};