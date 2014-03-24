#include<iostream>
#include<vector>
using namespace std;
int main(){
	class Solution{
		public:
			int evalRPN(vector<string> &tokens){
				vector<int> numbers;
				int length=tokens.size();
				for(int i=0;i<length;++i){
					if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
						int a=numbers.back();
						numbers.pop_back();
						int b=numbers.back();
						numbers.pop_back();
						if(tokens[i]=="+") numbers.push_back(a+b);
						if(tokens[i]=="-") numbers.push_back(b-a);
						if(tokens[i]=="*") numbers.push_back(a*b);
						if(tokens[i]=="/") numbers.push_back(b/a);
					}
					else{
						string temp=tokens[i];
						int isize=temp.size();
						int c=0,flag=1;
						for(int j=0;j<isize;++j){
							if(temp[j]=='-')  flag=-1; 
							else	c=c*10+(temp[j]-'0');
						}
						numbers.push_back(c*flag);
					}
				}
				return numbers.back();
			}
	};
	vector<string> test;
	test.push_back("4");
	test.push_back("3");
	test.push_back("-");
//	test.push_back("3");
//	test.push_back("*");
	Solution a;
	int show;
	show=a.evalRPN(test);
	cout<<show<<endl;
	cin>>show;
}
