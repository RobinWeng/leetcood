#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int candy(vector<int> &ratings) {
		int n=ratings.size();
		int result=0;
		vector<int> assign(n,1);
		for(int i=0;i<n;++i){
			cout<<assign[i]<<" ";
		}
		cout<<endl;
		for(int i=1,j=1;i<n;++i){
			if(ratings[i]==ratings[i-i]) printf("yes");
			if(ratings[i] > ratings[i-1]){
			//if(ratings[i] > ratings[i-i]){  //this input error take much time to debug!!!!
				cout<<ratings[i]<<" "<<ratings[i-1]<<endl;
				assign[i]=++j;
			}
			else j=1;
		}
		for(int i=n-2,j=1;i>-1;--i){
			if(ratings[i]>ratings[i+1]){
				if(++j>assign[i]) assign[i]=j;
			}
			else j=1;
		}
			for(int i=0;i<n;++i){
			cout<<assign[i]<<" ";
		}
		for(int i=0;i<n;++i){
			result+=assign[i];
		}
		cout<<result;
		return result;
    }
};
int main(){
	vector<int> ratings;
	ratings.push_back(1);
		ratings.push_back(2);
			ratings.push_back(2);
	Solution a;
	a.candy(ratings);
	return 0;
}
