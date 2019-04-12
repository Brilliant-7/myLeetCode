struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *p1 = l1;
		ListNode *p2 = l2;

		// 若某一个链表为空，则返回另一个链表
		if (p1 == NULL) {
			return l2;
		}
		else if (p2 == NULL) {
			return l1;
		}

		// 初始化头结点
		ListNode *curPtr = new ListNode(0);
		ListNode *result = curPtr;

		while (p1 != NULL && p2 != NULL) {
			if (p1->val < p2->val) {
				curPtr->next = p1;
				p1 = p1->next;
				curPtr = curPtr->next;
			}
			else {
				curPtr->next = p2;
				p2 = p2->next;
				curPtr = curPtr->next;
			}
		}

		// 若某个链表不为空，则需要将其链接在尾部
		if (p1 != NULL) {
			curPtr->next = p1;
		}
		else if (p2 != NULL) {
			curPtr->next = p2;
		}
		return result->next;
	}
};