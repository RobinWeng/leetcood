#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return buildOfTree(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
	typedef vector<int>::iterator it;
	TreeNode *buildOfTree(it prebegin,it preend,it inbegin,it inend){
		if(prebegin==preend) return NULL;
		if(inbegin==inend) return NULL;
		TreeNode*root=new TreeNode(*prebegin);
		it itleftsize=find(inbegin,inend,*prebegin);
		int leftsize=itleftsize-inbegin;
		root->left=buildOfTree(prebegin+1,prebegin+1+leftsize,inbegin,inbegin+leftsize);
		root->right=buildOfTree(prebegin+leftsize+1,preend,inbegin+leftsize+1,inend);
		return root;
	}
};
void preordertraversal(TreeNode*root){
	if(root==NULL) return;
	cout<<root->val<<" ";
	preordertraversal(root->left);
	preordertraversal(root->right);
}
int main(){
	int preordernum[]={
		1,2,4,5,6,7,3
	};
	int inordernum[]={
		4,2,6,5,7,1,3
	};
	int count=sizeof(preordernum)/sizeof(int);
	vector<int> preorder(preordernum,preordernum+count);
	vector<int> inorder(inordernum,inordernum+count);
	Solution a;
	TreeNode* root=a.buildTree(preorder,inorder);
	preordertraversal(root);
	return 0;
}

