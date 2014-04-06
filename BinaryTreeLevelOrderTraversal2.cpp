#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > result;
		queue<TreeNode*> current,next;
		vector<int> temp;
if(root==NULL) return result;   //forget
		current.push(root);
		while(1){
			while(current.size()>0){
				root=current.front();
				current.pop();
				temp.push_back(root->val);
				if(root->left!=NULL) next.push(root->left);
				if(root->right!=NULL) next.push(root->right);
			}
			result.insert(result.begin(),temp);
//			cout<<endl;   because this line leed the leetcode show wrong
			if(next.size()==0)  return result;
//			current.swap(next);
			swap(current,next);
			temp.clear();
		}
    }
};
void createTree(TreeNode** root,char *btnum){
	static int count=0;
	if(btnum[count++]=='#') return;
	else{
		*root=new TreeNode(btnum[count-1]-'0');
		cout<<(*root)->val<<" ";
		createTree(&(*root)->left,btnum);
		createTree(&(*root)->right,btnum);
	}
}
int main(){
	char btnum[]={
//		'3','9','#','#','2','1','#','#','7','#','#'
		'1','#','#'
	};
	TreeNode* root;
	createTree(&root,btnum);
	Solution a;
	vector<vector<int> > show;
	show=a.levelOrderBottom(root);
	for(int i=0;i<show.size();++i){
		for(int j=0;j<show[i].size();++j){
			cout<<show[i][j]<<" ";
		}
		cout<<endl;
	}
}
