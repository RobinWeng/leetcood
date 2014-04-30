#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
		//		ListNode *result=new ListNode(0);
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode result(-1);
		ListNode *current=&result;
		int carry=0;
		while(l1!=NULL||l2!=NULL){
			int sum=0;
			//these three if are related;it shoud be modified to if,else if,else 
			if(l1!=NULL&&l2!=NULL){
				sum=l1->val+l2->val+carry;
    			l1=l1->next;
    			l2=l2->next;				
			}
			if(l1!=NULL&&l2==NULL){
				sum=l1->val+carry;
			    l1=l1->next;
			}
			if(l1==NULL&&l2!=NULL){
				sum=l2->val+carry;
			    l2=l2->next;
			}
			carry=sum/10;
			current->next=new ListNode(sum%10);
			current=current->next;
		}
		if(carry==1){
			current->next=new ListNode(1);
		}
		return result.next;

    }
};
int main(){
	ListNode *l1,*l2;
	l1=new ListNode(1);
	l1->next=new ListNode(8);
	l2=new ListNode(0);
	Solution a;
	a.addTwoNumbers(l1,l2);
}
