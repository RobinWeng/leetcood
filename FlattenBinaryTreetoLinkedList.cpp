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
    void flatten(TreeNode *root) {
		vector<TreeNode*> temp;
		if(root==NULL) return;
		traversal(temp,root);
		for(int i=0;i<temp.size()-1;++i){
			temp[i]->left=NULL;
			temp[i]->right=temp[i+1];
		}
    }
	void traversal(vector<TreeNode*> &v,TreeNode* root){
		if(root==NULL) return;
		v.push_back(root);
		traversal(v,root->left);
		traversal(v,root->right);
	}
};
void createTree(TreeNode**root,int *num){
	static int count;
	if(num[count++]==INT_MAX) return;
	*root=new TreeNode(num[count-1]);
	createTree(&(*root)->left,num);
	createTree(&(*root)->right,num);
}
void preorder(TreeNode* root){
	if(root==NULL) return;
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}
int main(){
	int treeNumb[]={
		1,2,3,INT_MAX,INT_MAX,4,INT_MAX,INT_MAX,2,4,INT_MAX,INT_MAX,3,INT_MAX,INT_MAX};
	TreeNode*root;
	createTree(&root,treeNumb);
	preorder(root);
	cout<<endl;
	Solution a;
	a.flatten(root);
	preorder(root);
	cout<<endl;
}

