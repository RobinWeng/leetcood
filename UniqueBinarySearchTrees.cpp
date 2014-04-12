#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	    int numTrees1(int n) {
		static vector<int> storage(n+1,0);
		if(storage[n]!=0) return storage[n];
		if(n==0){
			storage[0]=1;
			return 1;
		}
		if(n==1){
			storage[1]=1;
			return 1;
		}
		for(int i=0;i<n;++i){
			storage[n]+=numTrees(i)*numTrees(n-i-1);
//			cout<<"storage"<<n<<"="<<storage[n]<<"\n";
		}
		cout<<"storage"<<n<<"="<<storage[n]<<"\n";
		return storage[n];
    }
	int numTrees(int n){
		vector<int> storage(n+1,0);
		if(n==0) return 1;
		if(n==1) return 1;
		storage[0]=1;
		storage[1]=1;
		for(int i=2;i< n+1;++i)
			for(int j=0;j<i;++j){
				storage[i]+=storage[j]*storage[i-j-1];
			}
		cout<<"storage"<<n<<"="<<storage[n]<<"\n";
		return storage[n];
	}
};
int main(){
	Solution a;
	cout<<a.numTrees(6);
	cout<<a.numTrees1(6);
	return 0;
}

