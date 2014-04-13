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
    bool hasPathSum(TreeNode *root, int sum) {
       if(root==NULL) return false;
	   if(root->val==sum&&root->left==NULL&&root->right==NULL) return true;
	    return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }
};
void createtree(TreeNode**root,int *nums){
	static int count=0;
	if(nums[count++]==INT_MAX) return;
	*root=new TreeNode(nums[count-1]);
	createtree(&(*root)->left,nums);
	createtree(&(*root)->right,nums);
}
int main(){
	int nums[]={
		-2,INT_MAX,-3,INT_MAX,INT_MAX
	};
	TreeNode*root;
	createtree(&root,nums);
	Solution a;
	if(a.hasPathSum(root,-5)) cout<<"yse";
}

