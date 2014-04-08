#include<iostream>
#include<vector>
using namespace std;
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
		queue<TreeLinkNode*> current,next;
		if(root==NULL) return;  //always forget
		current.push(root);
		while(1){
			while(current.size()>0){
				TreeLinkNode*node=current.front();
				current.pop();
				if(!current.empty())
					node->next=current.front();
				else
					node->next=NULL;
				if(node->left!=NULL)
					next.push(node->left);
				if(node->right!=NULL)
					next.push(node->right);
			}
			if(next.size()>0)
				swap(current,next);
			else return;
		}
    }
};

