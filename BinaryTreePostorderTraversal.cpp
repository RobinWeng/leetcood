#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
       vector<TreeNode*> stack;
	   vector<int> result; 
	   TreeNode *pre;
	   pre=NULL;
	   while(root!=NULL||stack.size()>0){
		   if(root){
			   stack.push_back(root);
			   root=root->left;
		   }
		   else{
			   root=stack.back();
			   stack.pop_back();
			   if(root->right!=NULL&&root->right!=pre){
				   stack.push_back(root);
				   root=root->right;
			   }
			   else{
				   result.push_back(root->val);
				   pre=root;
				   root=NULL;
			   }
		   }
	   }
		showtheresult(result);
	   return result;
    }
	vector<int> preorderTraversal(TreeNode *root) {
		vector<TreeNode*> stack;
		vector<int> result;
		while(root!=NULL||stack.size()>0){
			if(root){
				result.push_back(root->val);
				stack.push_back(root);
				root=root->left;
			}
			else{
				root=stack.back();
				stack.pop_back();
				root=root->right;
			}
		}
		showtheresult(result);
		return result;
	}
	vector<int> inorderTraversal(TreeNode *root){
		vector<TreeNode*> stack;
		vector<int> result;
		while(root!=NULL||stack.size()>0){
			if(root){
				stack.push_back(root);
				root=root->left;
			}
			else{
				root=stack.back();
				result.push_back(root->val);
				stack.pop_back();
				root=root->right;
			}
		}
		showtheresult(result);
		return result;
	}
	void showtheresult(vector<int> &result) const{
		for(int i=0;i<result.size();++i){
			cout<<result[i]<<" ";
		}
	}
};
void createTree(TreeNode **root,string &poststr){
	static int count=0;
	while(poststr[count]==' ') ++count;
	if(poststr[count]=='\0') return;
	if(poststr[count++]!='#'){
		*root=new TreeNode((poststr[count-1]-'0'));
		cout<<(*root)->val<<" ";
//		cout<<count-1<<":"<<poststr[count-1]<<endl;
		createTree(&(*root)->left,poststr);
		createTree(&(*root)->right,poststr);
	}
}
void traverse(TreeNode *root){
	if(root==NULL) return;
	cout<<root->val<<" ";
	traverse(root->left);
	traverse(root->right);
}
void post_tra(TreeNode *root){
	if(root==NULL) return;
	post_tra(root->left);
	post_tra(root->right);
	cout<<root->val<<" ";
}
void mid_tra(TreeNode *root){
	if(root==NULL) return;
	mid_tra(root->left);
	cout<<root->val<<" ";
	mid_tra(root->right);
}
void Traversal(TreeNode *root){
	vector<TreeNode *> stack;
	TreeNode *temp;
	vector<int> result;
	if(root==NULL) return;
	stack.push_back(root);
	while(stack.size()>0){
		root=stack.back();
		result.push_back(root->val);
		cout<<root->val<<endl;
		stack.pop_back();
		if(root->right!=NULL) stack.push_back(root->right);
		if(root->left!=NULL) stack.push_back(root->left);
	}
	for(int i=0;i<result.size();++i){
		cout<<result[i]<<" ";
	}
	
}
int main(){
	string str="1 # 2 9 4 # # 5";
	TreeNode *root;
	createTree(&root,str);
	traverse(root);
	Traversal(root);
	cout<<"traverse_end()"<<endl;
	post_tra(root);
	cout<<"posttraverse_end()"<<endl;
	mid_tra(root);
	cout<<"midtra_end()"<<endl;
	vector<int> show;
	Solution a;
	a.postorderTraversal(root);
	cout<<"posttraverse_end()"<<endl;
	a.inorderTraversal(root);
	cout<<"midtra_end()"<<endl;
	a.preorderTraversal(root);
	cout<<"traverse_end()"<<endl;
}
