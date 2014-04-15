struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isValidBST(TreeNode *root) {
		if(root==NULL) return true;
		return boundIsValideBDST(root,INT_MIN,INT_MAX);        
    }
	bool boundIsValideBDST(TreeNode*root,int lower,int upper){
		if(root==NULL) return true;
		if(root->x>=upper||root->x<=lower) return false;
		return boundIsValideBDST(root->left,lower,root->x)&&
			boundIsValideBDST(root->right,root->x,upper);
	}
};

