class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c < 0) return false;
        int i = 0;
        int j = sqrt(c);
        while(i <= j){
            if (i * i == (c - j * j)){
                return true;
            }else if(i * i < (c - j * j)){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};