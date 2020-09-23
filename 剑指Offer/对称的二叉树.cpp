/*
中序遍历（左根右）与对称的中序遍历（右根左）进行比较
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
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (!pRoot)
        {
            return true;
        }
        return isSymmetrical(pRoot, pRoot);
    }

    bool isSymmetrical(TreeNode* pNode1, TreeNode* pNode2)
    {
        if ((pNode1 && !pNode2) || (!pNode1 && pNode2))
        {
            return false;
        }
        else if (!pNode1 && !pNode2)
        {
            return true;
        }
        else
        {
            bool bEqual1 = isSymmetrical(pNode1->left, pNode2->right);
            bool bEqual2 = (pNode1->val == pNode2->val);
            bool bEqual3 = isSymmetrical(pNode1->right, pNode2->left);
            return bEqual1 && bEqual2 && bEqual3;
        }
    }
};