#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
		int w=sizeof(int)*8;
		int count[w];
		int result=0;
		memset(count,0,sizeof(int)*w);//initial wrong
		for(int i=0;i<w;i++){
			cout<<count[i]<<" ";
			count[i]=0;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<w;j++){
				cout<<A[i]<<endl;
				count[j]+=((A[i]>>j)&1);
				count[j]=count[j]%3;
				cout<<"j="<<j<<"+"<<count[j]<<endl;
			}
		}
		for(int i=0;i<w;i++){
			result+=(count[i]<<i);
		}
		return result;
    }
};
int main(){
	int a[1]={
	1	
	};
	Solution object;
	cout<<object.singleNumber(a,1);
}


