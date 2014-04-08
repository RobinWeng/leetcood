#include<iostream>
#include<stack>`
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
//		if(p==NULL&&q=NULL) return true;
//		if(!p||!q) return false;
//		return (p->val==q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
		
		stack<TreeNode*> sthis;
		sthis.push(p);
		sthis.push(q);
		while(sthis.size()>0){
			p=sthis.top();sthis.pop();
			q=sthis.top();sthis.pop();
			if(!p&&!q) continue;
			if(!p||!q) rturn false;
			sthis.push(p->left);
			sthis.push(q->left);
			sthis.push(p->right);
			sthis.push(q->right);
		}
		return true;
	}
};

