#include<iostream>
#include<string>
using namespace std;
int main(){
	class Solution {
		public:
		    string reverseWords(string &s) {
		        string r="";
				string temp;
		        int index=0;
		        while(s[index]==' ') ++index;
		        while(s[index]!='\0'){
        			while(s[index]==' ') ++index;
        			for(int i=0;s[index]!=' '&&s[index]!='\0';++i,++index){
			        	temp+=s[index];
			        	cout<<temp<<endl;
			        }
			        r=temp+' '+r;
			        cout<<r<<endl;
			        temp.clear();
        		}
        		cout<<r<<endl; 
				return r;		        
		    }
	};
	string s=" ";
	Solution b;
	string c;
	c=b.reverseWords(s);
	cout<<'a'<<c<<"b"<<endl;
	return 0;
} 
