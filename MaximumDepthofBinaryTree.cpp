struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxDepth1(TreeNode *root) {
		if(root==NULL) return 0;
		return (maxDepth(root->left)>maxDepth(root->right))?maxDepth(root->left)+1:maxDepth(root->right)+1;
	}
// it is wrong because the compared two nums using recursion.
// it cause 3 timse recursion.
// so time limit exceeded;
//
    int maxDepth(TreeNode *root) {
		if(root==NULL) return 0;
		int lmax=maxDepth(root->left);
		int rmax=maxDepth(root->right);
		return (lmax>=rmax)?lmax+1:rmax+1;
    }
};

