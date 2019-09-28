struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL)
			return NULL;

		ListNode* pNode1 = l1;
		ListNode* pNode2 = l2;

		ListNode* pHead = new ListNode(0);
		ListNode* pResult = pHead;

		int nodeSum = 0;
		int carry = 0;

		while (pNode1 || pNode2)
		{
			if (pNode1 == NULL) {
				nodeSum = pNode2->val;
			}
			else if (pNode2 == NULL) {
				nodeSum = pNode1->val;
			}
			else {
				nodeSum = pNode1->val + pNode2->val;
			}

			nodeSum += carry;

			pResult->next = new ListNode(nodeSum % 10);
			carry = nodeSum / 10;

			if (pNode1)
				pNode1 = pNode1->next;
			if (pNode2)
				pNode2 = pNode2->next;

			pResult = pResult->next;
		}

		if (carry)
		{
			pResult->next = new ListNode(carry);
		}

		return pHead->next;
	}
};