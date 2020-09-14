/*
回溯法：
    非常适合由多个步骤组成的问题，并且每个步骤都有多个选项
    通常物体或人在二维方格运动这类问题都可以用回溯法解决
visited[row][col]===>visited[row * cols + col]
*/

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold <= 0 || rows <= 0 || cols <= 0)
            return 0;
        bool *visited = new bool[rows * cols];
        for (int i = 0; i < rows * cols; ++i)
            visited[i] = false;
        
        int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
        delete[] visited;
        return count;
    }

    int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
    {
        int count = 0;
        if (isCanArrive(threshold, rows, cols, row, col, visited))
        {
            visited[row * cols + col] = true;
            count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
                + movingCountCore(threshold, rows, cols, row, col - 1, visited)
                + movingCountCore(threshold, rows, cols, row + 1, col, visited)
                + movingCountCore(threshold, rows, cols, row, col + 1, visited);
        }
        return count;
    }

    bool isCanArrive(int threshold, int rows, int cols, int row, int col, bool* visited)
    {
        if (col >= 0 && col < cols && row >= 0 && row < rows && 
            (getSumOfDigits(col) + getSumOfDigits(row) <= threshold)&&
           !visited[row * cols + col])
            return true;
        return false;
    }

    int getSumOfDigits(int num)
    {
        int sum = 0;
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};