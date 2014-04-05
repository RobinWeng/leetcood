#include<iostream>
#include<vector>
#include<list>
using namespace std;
struct TreeNode {
     int val;
	 TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
		vector<list<TreeNode*> > vqueue;
		vector<vector<int> > result;
		vector<int> vtemp;
		list<TreeNode*> ltemp;
		int count=0;
		if(root==NULL) return result;
		ltemp.push_back(root);
		vqueue.push_back(ltemp);
		while(1){
			vtemp.clear();
			ltemp.clear();
			while(vqueue[count].size()>0){
				root=vqueue[count].front();
				vtemp.push_back(root->val);
				vqueue[count].pop_front();
				if(root->left!=NULL) ltemp.push_back(root->left);
				if(root->right!=NULL) ltemp.push_back(root->right);
			}
			result.push_back(vtemp);
			if(ltemp.size()>0){
				vqueue.push_back(ltemp);
				++count;
			}
			else break;
		}
		return result;
    }
/*
    vector<vector<int> > levelOrder(TreeNode *root) {
		vector<int> vtemp;
		list<TreeNode*> queue;
		vector<vector<int>> result;
		int count,current;
		count=0;
		current=1;
		if(root==NULL) return result;
		queue.push_back(root);
		while(current>count){
			while(queue.size()>0){
				vtemp.push_back(queue.front());
				
			}
		}
	}
	*/
	vector<int> commomlevel(TreeNode *root){
		list<TreeNode*> queue;
		vector<int> temp;
		if(root==NULL) return temp;
		queue.push_back(root);
		while(queue.size()>0){
			temp.push_back(queue.front()->val);
//it is wrong because root always point to the same TreeNode 
			root=queue.front();    //add
			temp.push_back(root->val);//add
			queue.pop_front();
			if(root->left!=NULL)
				queue.push_back(root->left);
			if(root->right!=NULL)
				queue.push_back(root->right);
		}
		for(int i=0;i<temp.size();++i){
			cout<<temp[i]<<" ";
		}
		return temp;
	}
};
//There have been too many unpleasant when I crate the tree
//first,root is a point to a point
//second,i ignored the else,i would hope it work that
//if i find the treenum[x] is # then only do the root and do nothing
char treenum[]={'3','9','#','#','2','1','#','#','7','#','#'};
void createTree(TreeNode **root){
	static int count=0;
	if(treenum[count++]=='#') root=NULL;
	else{
	*root=new TreeNode(treenum[count-1]-'0');
	createTree(&(*root)->left);
	createTree(&(*root)->right);	
	}
}
int main(){
	TreeNode *root;
	createTree(&root);
	Solution a;
	vector<vector<int> > show;
	show=a.levelOrder(root);
	for(int i=0;i<show.size();++i){
		for(int j=0;j<show[i].size();++j){
			cout<<show[i][j]<<" ";
		}
	cout<<endl;
	}
	a.commomlevel(root);
	return 0;
}
