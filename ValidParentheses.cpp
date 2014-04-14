#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
		int i=0;
		stack<char> stemp;
		while(s[i++]!='\0'){
			if(s[i-1]=='{'||s[i-1]=='['||s[i-1]=='(')
				stemp.push(s[i-1]);
			if(s[i-1]=='}'||s[i-1]==']'||s[i-1]==')'){
				if(stemp.size()==0) return false;
				if(stemp.top()=='{'&&s[i-1]=='}') stemp.pop();
				else if(stemp.top()=='['&&s[i-1]==']') stemp.pop();
				else if(stemp.top()=='('&&s[i-1]==')') stemp.pop();
				else return false;
			}
		}
		return stemp.empty();
	//	if(stemp.size()>0) return false;
	//	else return true;
    }
};
int main(){
	string s="()";
	Solution a;
	if(a.isValid(s)) cout<<"yes";
}

