//no using atoi s.c_str()
//int atoi(const char*nptr)
//const char*c_str()
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
						int c=0;
						c=atoi(tokens[i].c_str());
						numbers.push_back(c);
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
