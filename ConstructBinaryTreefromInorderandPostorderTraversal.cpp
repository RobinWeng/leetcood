#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return buildOfTree(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
    }
	typedef vector<int>::iterator it;
	TreeNode *buildOfTree(it inbegin,it inend,it postbegin,it postend){
		if(inbegin==inend) return NULL;
		if(postbegin==postend) return NULL;
		TreeNode* root=new TreeNode(*(postend-1));
		it itleftsize=find(inbegin,inend,*(postend-1));
		int leftsize=itleftsize-inbegin;
		root->left=buildOfTree(inbegin,inbegin+leftsize,postbegin,postbegin+leftsize);
		root->right=buildOfTree(inbegin+leftsize+1,inend,postbegin+leftsize,postend-1);
		return root;
	}
};
void preordetraversal(TreeNode*root){
	if(root==NULL) return;
	cout<<root->val<<" ";
	preordetraversal(root->left);
	preordetraversal(root->right);
}
int main(){
	int postnum[]={
		3,4,2,6,7,5,1
	};
	int innum[]={
		3,2,4,1,6,5,7
	};
	int count=sizeof(innum)/sizeof(int);
	vector<int> post(postnum,postnum+count);
	vector<int> inorder(innum,innum+count);
	Solution a;
	TreeNode*root=a.buildTree(inorder,post);//forget again
	preordetraversal(root);
	return 0;
}
