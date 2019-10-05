struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return head;
            
        ListNode *pNode = head;
        ListNode *pNext = nullptr;
        ListNode *pTemp = nullptr;

        while (pNode != nullptr)
        {
            pTemp = pNode->next;
            pNode->next = pNext;
            pNext = pNode;
            pNode = pTemp;
        }

        return pNext;
    }
};