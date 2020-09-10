/*
利用二维数组由上到下，由左到右递增的规律，
那么选取右上角或者左下角的元素a[row][col]与target进行比较
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size() - 1;
        int col = 0;
        int colLength = array[0].size();
        while(row >= 0 && col <= colLength - 1)
        {
            if (array[row][col] == target)
            {
                return true;
            }
            else if (array[row][col] > target)
            {
                row--;
            }
            else
            {
                col++;
            }
        }
        return false;
    }
};