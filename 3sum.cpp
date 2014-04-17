#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > result;
		if(num.size()<3) return result;
		sort(num.begin(),num.end());
		for(int i=0;i<num.size()-2;++i){
			if(num[i]==num[i-1]) continue;  //unique
			int j=i+1;
			int k=num.size()-1;
			int sum=0-num[i];
			vector<int> temp;
			while(j<k){
				if(num[j]+num[k]<sum) ++j;
				else if(num[j]+num[k]>sum) --k;
				else {
//				    result.push_back(vector<int>{num[i],num[j],num[k]});
					temp.push_back(num[i]);temp.push_back(num[j]);temp.push_back(num[k]);
				    result.push_back(temp);
				    temp.clear();
					++j;
				    while(num[j]==num[j-1]) ++j;
					
				}
			}
//			
		}
    }
};
int main(){
	int ele[]={
		-1,0,1,2,-1,-4
	};
	vector<int> elements(ele,ele+6);
	Solution a;
	vector<vector<int> > show;
	show=a.threeSum(elements);
	for(int i=0;i<show.size();++i){
		for(int j=0;j<3;++j)
			cout<<show[i][j]<<" ";
		cout<<endl;
	}
}


