/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == nullptr)
            return pHead;
        ListNode* pPreNode = nullptr;
        ListNode* pCurNode = pHead;
        while (pCurNode)
        {
            ListNode* pNextNode = pCurNode->next;
            bool bSame = pNextNode && (pNextNode->val == pCurNode->val);
            if (!bSame)
            {
                pPreNode = pCurNode;
                pCurNode = pNextNode;
            }
            else
            {
                int temp = pCurNode->val;
                while (pCurNode && pCurNode->val == temp)
                {
                    ListNode* pTemp = pCurNode;
                    pCurNode = pCurNode->next;
                    delete pTemp;
                    pTemp = nullptr;
                }
                // 将第一个不重复的节点给pHead
                if (!pPreNode)
                {
                    pHead = pCurNode;
                }
                else  // 不要断链，考虑最后一个node->next
                {
                    pPreNode->next = pCurNode;
                }
            }
        }

        return pHead;
    }
};