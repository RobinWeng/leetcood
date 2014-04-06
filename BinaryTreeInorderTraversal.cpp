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
    vector<int> inorderTraversal(TreeNode *root) {
		inorder(root);
		return temp;
    }
	void inorder(TreeNode *root){
		if(root==NULL) return;
		inorderTraversal(root->left);
		temp.push_back(root->val);
		inorderTraversal(root->right);
	}
private:
	vector<int> temp;
};
void createTree(TreeNode**root,char *array){
	static int count;
	if(array[count++]=='#') return;
	*root=new TreeNode(array[count-1]-'0');
	createTree(&(*root)->left,array);
	createTree(&(*root)->right,array);
}
int main(){
	char array[]={
		'3','9','#','#','2','1','#','#','7','#','#'
	};
	TreeNode* root;
	createTree(&root,array);
	vector<int> show;
	Solution a;
	show=a.inorderTraversal(root);
	for(int i=0;i<show.size();++i){
		cout<<show[i]<<" ";
	}
}
