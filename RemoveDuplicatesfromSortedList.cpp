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
		ListNode *cur=head->next;
		ListNode *pre=head;
		if(head==NULL||head->next==NULL) return head;
		while(cur!=NULL){
		if(cur->val==pre->val){
			pre->next=cur->next;
			free(cur);
			cur=pre->next;
		}
		else{
			cur=cur->next;
			pre=pre->next;
		}
		}
		return head;
    }
};

