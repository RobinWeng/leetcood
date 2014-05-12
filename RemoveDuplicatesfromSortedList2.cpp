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
    ListNode *deleteDuplicates(ListNode *head) {
		ListNode reNext(INT_MAX);
		reNext.next=head;
		ListNode *pre,*cur;
		pre=&reNext;cur=reNext.next;
		while(cur!=NULL){
			bool isduplicate=false;
			while(cur->next!=NULL&&cur->val==cur->next->val){
				isduplicate=true;
				pre->next=cur->next;
				delete cur;
				cur=cur->next;
			}
			if(isduplicate){
				pre->next=cur->next;
				delete cur;
				cur=cur->next;
				continue;
			}
			pre=pre->next;
			cur=cur->next;
		}
		return reNext.next;
    }
};

