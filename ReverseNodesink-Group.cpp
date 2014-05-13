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
    ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode reNext(-1);
		reNext.next=head;
		ListNode *prefirst,*prek;
		for(prefirst=&reNext,prek=head;prek;prek=prefirst->next){
			for(int i=1;i<k&&prek;++i){
				prek=prek->next;
			}
			if(prek==NULL) break;
				if(prek==NULL) break;
			prefirst=reverse(prefirst,prefirst->next,prek);	
			//Line 21: no matching function for call to 'reverse(ListNode*&, ListNode*&, ListNode*&)'
		}
		ListNode *reverse(ListNode *prefirst,ListNode *first,ListNode *prek){
			ListNode *temp;
			temp=prek->next->next;
			prek->next->next=first->next;
			prefirst->next=prek->next;
			prek->next=first;
			first->next=temp;
			return first
		}
};


class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
	    if(head==NULL||head->next==NULL||k<2) return head;
		ListNode reNext(-1);
		reNext.next=head;
		ListNode *prefirst,*prek;
		for(prefirst=&reNext,prek=head;prek;prek=prefirst->next){
			for(int i=1;i<k-1&&prek;++i){
				prek=prek->next;
			}
			if(prek==NULL) break;
			prefirst=reversetwo(prefirst,prefirst->next,prek);	
		}
		return reNext.next;
    }
	ListNode *reversetwo(ListNode *prefirst,ListNode *first,ListNode *prek){
			ListNode *temp;
			temp=prek->next->next;
			prek->next->next=first->next;
			prefirst->next=prek->next;
			prek->next=first;
			first->next=temp;
			return first;
    }
};


