// 题目： 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
// 链接： https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8
// ===========================================================
// 思考： 
// 1. 排序后再查找重复值，时间复杂度O(nlogn)；
// 2. 利用哈希表，时间复杂度O(n)，空间复杂度O(n)；
// 3. 从头到尾扫描数组，比较下标为i的数字m是否等于i。如果是，则扫描下一个；如果不是，则比较数字m与下标为m的数字。如果相等，则找到；不相等则交换。重复此过程，直到发现一个重复的数字。
// ps: 一开始打算采用二分查找的思路，忽略了前提条件：一定包含重复数字。



class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (length < 1 || numbers == nullptr) return false;
        for (int i = 0; i < length; ++i){
            if (numbers[i] >= length || numbers[i] < 0) return false;
            while(numbers[i] != i){
                if (numbers[i] == numbers[numbers[i]]){
                    duplication[0] = numbers[i];
                    return true;
                }
                int temp = numbers[i];
                numbers[i] = numbers[numbers[i]];
                numbers[temp] = temp;
            }
        }
        return false;
    }
};