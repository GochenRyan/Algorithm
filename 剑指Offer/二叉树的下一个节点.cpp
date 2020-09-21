/*
1. ���������ģ���ô�¸�����������������ߵĵ�
2. û���������ģ�Ҳ���Էֳ�����
    1. �Ǹ��ڵ����ӣ���ô���ڵ������һ���ڵ�
    2. �Ǹ��ڵ���Һ��������ĸ��ڵ�ĸ��ڵ�ĸ��ڵ�...ֱ����ǰ������丸�ڵ������λ�á����û�У���ô������β�ڵ�
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
            if (pParent->left == pNode)  // �ýڵ����丸�ڵ�����ӣ��򷵻ظ��ڵ�
                return pParent;
            pNode = pNode->next;  // �������ϱ����丸�ڵ�ĸ��ڵ�
        }
        return nullptr;
    }
};