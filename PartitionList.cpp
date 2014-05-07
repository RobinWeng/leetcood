#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
		if(head==NULL||head->next==NULL) return head;
		ListNode smallhead(INT_MIN);
		ListNode bighead(INT_MAX);
		ListNode *smalllast=&smallhead;
		ListNode *biglast=&bighead;
		while(head!=NULL){
			if(head->val<x){
				smalllast->next=head;
				smalllast=smalllast->next;
			}
			else{
				biglast->next=head;
				biglast=biglast->next;
			}
			head=head->next;
		}
		biglast->next=NULL;  //ignore!!!
		smalllast->next=bighead.next;
		return smallhead.next;
    }
};
int main(){
	ListNode *head=new ListNode(1);
	head->next=new ListNode(1);
	Solution a;
	head=a.partition(head,0);
	while(head!=NULL) {cout<<head->val<<endl;head=head->next;}
}
