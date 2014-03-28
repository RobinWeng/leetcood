//i make a mistake p=p->next ,not p++
#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
       ListNode headnode(-1);
	   ListNode *p,*prep,*temp;
	   while(head!=NULL){
		   prep=&headnode;p=prep->next;temp=head->next;
		   while(p!=NULL&&head->val>p->val){
			   prep=prep->next;
			   p=p->next;
		   }
		   head->next=p;
		   prep->next=head;
		   head=temp;
	   }
	   	for(ListNode *pp=&headnode;pp!=NULL;pp=pp->next)
			cout<<pp->val<<endl;	
	   return headnode.next;
    }
};
int main(){
	ListNode diyi(1);
	ListNode diye(2);
	ListNode diyr(4);
//	ListNode diyi(1);
	diyi.next=&diye;
	diye.next=&diyr;
//	diyr.next=&diyo;
	Solution a; 
	ListNode *result=a.insertionSortList(&diyi);
	for(ListNode *p=result;p!=NULL;p=p->next){
		cout<<p->val<<endl;		
	}
	int response;
	cin>>response;
}
