#include<iostream>
#include<string>
using namespace std;
int main(){
	class Solution {
		public:
		    void reverseWords(string &s) {
		        string r="";
				string temp;
		        int index=0;
		        while(s[index]!='\0'){
        			while(s[index]==' ') ++index;
        			for(int i=0;s[index]!=' '&&s[index]!='\0';++i,++index){
			        	temp+=s[index];
			        }
			        while(s[index]==' ') ++index;
			        if(s[index]=='\0') r=temp+r;
			        else r=" "+temp+r;
			        temp.clear();
        		}
				s=t;
		    }
	};
	string s="  ";
	Solution b;
	string c;
	c=b.reverseWords(s);
	cout<<"b"<<c<<"c"<<endl;
	int e;
	cin>>e;
	return 0;
} 
