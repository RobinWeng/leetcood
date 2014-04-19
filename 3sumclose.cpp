#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if(num.size()==3) return num[0]+num[1]+num[2];
		int length=num.size();
//		int min=INT_MAX;
		int min=num[0]+num[1]+num[2];
		sort(num.begin(),num.end());
		for(int i=0;i<length-1;++i){
			int addsum=target-num[i];
			int j=i+1;int k=length-1;
			while(j<k){
				int sum=num[j]+num[k];
				if(sum>addsum){
					min=abs(min-target)<=abs(sum-addsum)?min:(sum+num[i]);
					--k;
				}
				else if(sum<addsum){
					min=abs(min-target)<=abs(sum-addsum)?min:(sum+num[i]);
					++j;
				}
				else
					return target;
			}
		}
		return min;
    }
};
int main(){
	int nums[]={
		-3,-2,-5,3,-4
	};
	vector<int> n(nums,nums+5);
	Solution a;
	cout<<a.threeSumClosest(n,-1);
}

