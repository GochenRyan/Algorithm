/*
1.判断链表中有环 -> 2.得到环中节点的数目 -> 3.找到环中的入口节点
*/

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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == nullptr)
            return nullptr;

        ListNode* pStep1 = pHead;
        ListNode* pStep2 = pHead;

        pStep1 = pStep1->next;  // 让pStep1 != pStep2
        if (pStep1 == nullptr)
            return nullptr;

        while (pStep2 != nullptr && pStep2 != pStep1)
        {
            pStep2 = pStep2->next;
            if (pStep2)
                pStep2 = pStep2->next;
            pStep1 = pStep1->next;
        }

        int loopCount = 1;
        if (pStep2 != nullptr)
        {
            while (pStep2->next != pStep1)
            {
                pStep2 = pStep2->next;
                loopCount++;
            }
            pStep1 = pHead;
            pStep2 = pHead;
            for (int i = 0; i < loopCount; i++)
            {
                pStep2 = pStep2->next;
            }
            while (pStep1 != pStep2)
            {
                pStep1 = pStep1->next;
                pStep2 = pStep2->next;
            }
            return pStep1;
        }
        return nullptr;
    }
};