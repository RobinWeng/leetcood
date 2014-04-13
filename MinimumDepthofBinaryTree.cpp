#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int minDepth(TreeNode *root) {
    	if(root==NULL) return 0;
		if(root->left==NULL&&root->right==NULL) return 1;
		int leftdepth=root->left==NULL?INT_MAX:minDepth(root->left);
		int rightdepth=root->right==NULL?INT_MAX:minDepth(root->right);
		return leftdepth<=rightdepth?(leftdepth+1):(rightdepth+1);
    }
};
void createTree(TreeNode**root,int*seq){
	static int count=0;
	if(seq[count++]==INT_MAX) return;
	*root=new TreeNode(seq[count-1]);
		createTree(&(*root)->left,seq);
		createTree(&(*root)->right,seq);
}
int main(){
	int seq[]={
		1,2,3,4,INT_MAX,INT_MAX,INT_MAX,INT_MAX,5,INT_MAX,INT_MAX
//		1,2,INT_MAX,INT_MAX,INT_MAX
	};
	TreeNode*root;
	createTree(&root,seq);
	Solution a;
	cout<<a.minDepth(root);
}

