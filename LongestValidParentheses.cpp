#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
		stack<int> stemp;
		int remax=0;
		int lastleft=-1;
		for(int i=0;i<s.size();++i){
			if(s[i]=='(') stemp.push(i);
			else{
				if(stemp.size()>0){
					stemp.pop();
					if(stemp.size()>0) remax=(remax>i-stemp.top())?remax:i-stemp.top();
					else remax=(remax>i-lastleft)?remax:i-lastleft;
				}
				else{
					lastleft=i;
				}
			}
		}
		return remax;
    }
};
int main(){
	string s="()";
	Solution a;
	cout<<a.longestValidParentheses(s);
}

