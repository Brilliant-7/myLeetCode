struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode *pPreNode = head;
        int preAppear = head->val;

        ListNode *pNode = head->next;
        ListNode *pTemp = nullptr;

        while (pNode != nullptr)
        {
            if (pNode->val == preAppear)
            {
                pTemp = pNode->next;
                pPreNode->next = pTemp;
                delete pNode;
                pNode = pTemp;
            }
            else
            {
                preAppear = pNode->val;
                pPreNode = pNode;
                pNode = pNode->next;
            }
        }

        return head;
    }
};