// 双指针
class Solution {
public:
    string reverseVowels(string s) {
        if(s.empty())
            return "";
        string vowel = "aeiouAEIOU";
        int i = 0, j = s.size() - 1;
        while(i < j){
            while((vowel.find(s[i]) == string::npos)&&(i<j)){
                i++;
            }
            while((vowel.find(s[j]) == string::npos)&&(i<j)){
                j--;
            }
            if(i < j)
                swap(s[i++], s[j--]);
        }
        return s;
    }
};