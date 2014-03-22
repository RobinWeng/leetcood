#include<iostream>
#include<vector>
using namespace std;
int main(){
	class Solution {
	public:
	    vector<int> twoSum(vector<int> &numbers, int target) {
	        vector<int> temp=numbers;
			sort(temp.begin(),numbers.end());
	        vector<int> result;
	        int length=numbers.size();
			for(int i=0;i<length;++i)
				for(int j=i+1;j<length;++j){
					if(numbers[i]+numbers[j]==target){
						result.push_back(find(numbers.begin(),numbers.end(),temp[i])+1);
						result.push_back(find(numbers.begin(),numbers.end(),temp[j])+1);
						return result;
					}
					if(numbers[i]+numbers[j]>target) break;
				}			 
	    }
	};
	Solution twosum;
	vector<int> show;
	int a[]={2, 7, 11, 15};
	vector<int> numbers(a,a+4);
	int target=18;
	show=twosum.twoSum(numbers,target);	
	cout<<show[0]<<show[1]<<endl;
}
