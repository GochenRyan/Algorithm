/*
    利用快排思想（二分法）查找中位数（数组会改变）
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int length = numbers.size();
        if (length == 0)
            return 0;
        int randIndex = rand() % length;
        int begin = 0;
        int end = length - 1;
        int curIndex = partition(numbers, begin, end, randIndex);
        while (curIndex != length / 2)
        {
            if (curIndex < length / 2)
            {
                begin = curIndex + 1;
                randIndex = begin + rand() % (end - begin + 1);
                curIndex = partition(numbers, begin, end, randIndex);
            }
            else
            {
                end = curIndex - 1;
                randIndex = begin + rand() % (end - begin + 1);
                curIndex = partition(numbers, begin, end, randIndex);
            }
        }
        if (check(numbers, curIndex))
            return numbers[curIndex];
        return 0;
    }

    bool check(const vector<int>& numbers, int curIndex)
    {
        int count = 0;
        for (auto iter = numbers.begin(); iter != numbers.end(); ++iter)
        {
            if (*iter == numbers[curIndex])
            {
                ++count;
            }
        }
        if (count >= numbers.size() / 2)
        {
            return true;
        }
        return false;
    }

    int partition(vector<int>& numbers, int begin, int end, int index)
    {
        swap(numbers[index], numbers[end]);
        int i = index - 1;
        for (int j = index; j < end; ++j)
        {
            if (numbers[j] <= numbers[end])
            {
                ++i;
                if (i != j)
                {
                    swap(numbers[i], numbers[j]);
                }
            }
        }
        ++i;
        swap(numbers[i], numbers[end]);
        return i;
    }
};