class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B;
        int productFromSta = 1;
        B.push_back(productFromSta);
        for (int i = 0; i < A.size() - 1; ++i)
        {
            productFromSta *= A[i];
            B.push_back(productFromSta);
        }
        
        int productFromEnd = 1;
        for (int i = A.size() - 1; i > 0; --i)
        {
            productFromEnd *= A[i];
            B[i - 1] *= productFromEnd;
        }
        return B;
    }
};