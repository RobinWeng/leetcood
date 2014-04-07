#include<iostream>
#include<vector>
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
    vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<TreeNode*> sp;
		if(root==NULL) return result;
		while(root!=NULL||sp.size()>0){
			if(root!=NULL){
				sp.push(root);
				root=root->left;
			}
			else{
				root=sp.top();
				result.push_back(root->val);
				sp.pop();
				root=root->right;
			}
		}
		return result;
    }
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
	return 0;
}

