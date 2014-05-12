/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
		ListNode reNext(0);
		reNext.next=head;
		ListNode *first,*second,*nextAdjacent;
		nextAdjacent=&reNext;
		while(nextAdjacent->next!=NULL&&nextAdjacent->next->next!=NULL){
			first=nextAdjacent->next;
			second=nextAdjacent->next->next;
			nextAdjacent->next=second;
			first->next=second->next;
			second->next=first;
			nextAdjacent=first;
		}
		return reNext.next;
	}
};

