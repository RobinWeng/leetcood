#include<iostream>
#include<stack>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSymmetric2(TreeNode *root) {
		if(root==NULL) return true;
		stack<TreeNode*> s;
		TreeNode *p,*q;
		s.push(root->left);
		s.push(root->right);
		while(s.size()>0){
			q=s.top();s.pop();
			p=s.top();s.pop();
			if(!p&&!q) continue;
			if(!q||!p) return false;
			if(p->val!=q->val) return false;
			s.push(q->left);s.push(p->right);
			s.push(q->right);s.push(p->left);
		}
		return true;
    }
    bool isSymmetric(TreeNode *root) {
		if(root==NULL) return true;
		TreeNode*p,*q;
		p=root->left;q=root->right;
		return isSymmetricOfTwo(p,q);
	}
	bool isSymmetricOfTwo(TreeNode* p,TreeNode* q){
		if(!p&&!q) return true;
		if(!p||!q) return false;
		if(p->val!=q->val) return false;
		return isSymmetricOfTwo(p->left,q->right)&&isSymmetricOfTwo(p->right,q->left);
	}
};
void createTree(TreeNode**root,int *treeNumb){
	static int count=0;
	if(treeNumb[count++]==INT_MAX) return;
	*root=new TreeNode(treeNumb[count-1]);
	createTree(&(*root)->left,treeNumb);
	createTree(&(*root)->right,treeNumb);
}
int main(){
	int treeNumb[]={
		1,2,3,INT_MAX,INT_MAX,4,INT_MAX,INT_MAX,2,4,INT_MAX,INT_MAX,3,INT_MAX,INT_MAX};
	TreeNode*root;
	createTree(&root,treeNumb);
	Solution a;
	if(a.isSymmetric(root)) cout<<"yes"<<endl;
	if(a.isSymmetric2(root)) cout<<"yes"<<endl;
	return 0;
}
