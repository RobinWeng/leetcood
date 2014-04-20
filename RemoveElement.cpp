#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement1(vector<int> &a, int n, int elem) {
        sort(a.begin(),a.end());
        vector<int>::iterator it1,it2;
        if((it1=find(a.begin(),a.end(),elem))==a.end()) return n;
        it2=it1;
        while(*it1==*(++it2));
        a.erase(it1,it2);
        return a.size();
    }
	int removeElement(int A[],int n,int elem){
		int index=0;
		for(int i=0;i<n;++i){
			if(A[i]!=elem)
				A[index++]=A[i];
		}
		return index;
	}
};
int main(){
	int num[]={
		4,5
	};
	vector<int> show(num,num+2);
	Solution a;
	int n;
	n=a.removeElement(show,2,4);
	for(int i=0;i<n;++i){
		cout<<show[i]<<" ";
	}
}
