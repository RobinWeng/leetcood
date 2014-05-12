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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode reNext(INT_MAX);// I ignore the status that delete element is the head element
		reNext.next=head;
		ListNode *last,*nlast;
		last=nlast=&reNext;
		while(n--){
			last=last->next;
		}
		while(last->next!=NULL){
			nlast=nlast->next;
			last=last->next;
		}
		last=nlast->next;
		nlast->next=last->next;
		delete last;
		return reNext.next;
    }
};

