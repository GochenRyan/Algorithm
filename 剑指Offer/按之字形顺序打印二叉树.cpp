/*
    ˫ջʵ�֣�
        ��ǰ��ӡ�������㡱�����������ӽڵ㵽��һ��ջ
        ��ǰ��ӡ��ż���㡱�����������ӽڵ㵽�ڶ���ջ
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> vec;

        if (pRoot == nullptr)
            return vec;

        stack<TreeNode*> evenStack, oddStack;
        evenStack.push(pRoot);
        while (!evenStack.empty() || !oddStack.empty())
        {
            vector<int> vec1, vec2;
            while (!evenStack.empty())
            {
                TreeNode* pTemp = evenStack.top();
                evenStack.pop();
                vec1.push_back(pTemp->val);
                if (pTemp->left)
                    oddStack.push(pTemp->left);
                if (pTemp->right)
                    oddStack.push(pTemp->right);
            }
            if (!vec1.empty())
                vec.push_back(vec1);

            while (!oddStack.empty())
            {
                TreeNode* pTemp = oddStack.top();
                oddStack.pop();
                vec2.push_back(pTemp->val);
                if (pTemp->right)
                    evenStack.push(pTemp->right);
                if (pTemp->left)
                    evenStack.push(pTemp->left);
            }
            if (!vec2.empty())
                vec.push_back(vec2);
        }
        return vec;
    }

};