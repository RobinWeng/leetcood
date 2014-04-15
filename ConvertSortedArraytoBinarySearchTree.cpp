struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
		return sortedArrayToBST(num.begin(),num.end());
    }
	TreeNode *sortedArrayToBST(vector<int>::iterator begin,vector<int>::iterator end){
		int length=end-begin;
		if(length==0) return NULL;
		if(length==1) return new TreeNode(*begin);
		vector<int>::iterator mid=begin+length/2;
		TreeNode*root=new TreeNode(*mid);
		root->left=sortedArrayToBST(begin,mid);
		root->right=sortedArrayToBST(mid+1,end);
		return root;
	}
};

