/*
1. 有右子树的，那么下个结点就是右子树最左边的点
2. 没有右子树的，也可以分成两类
    1. 是父节点左孩子，那么父节点就是下一个节点
    2. 是父节点的右孩子找他的父节点的父节点的父节点...直到当前结点是其父节点的左孩子位置。如果没有，那么他就是尾节点
*/

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (!pNode)
            return nullptr;

        if (pNode->right)
        {
            pNode = pNode->right;
            while (pNode->left)
                pNode = pNode->left;
            return pNode;
        }
        while (pNode->next)
        {
            TreeLinkNode* pParent = pNode->next;
            if (pParent->left == pNode)  // 该节点是其父节点的左孩子，则返回父节点
                return pParent;
            pNode = pNode->next;  // 继续向上遍历其父节点的父节点
        }
        return nullptr;
    }
};