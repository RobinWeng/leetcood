#include<iostream>
#include<vector>
using namespace std;
int main(){
	class Solution {
	public:
	    vector<int> twoSum(vector<int> &numbers, int target) {
	        vector<int> temp=numbers;
			sort(temp.begin(),temp.end());
	        vector<int> result;
	        int length=temp.size();
			for(int i=0;i<length;++i)
				for(int j=i+1;j<length;++j){
					if(temp[i]+temp[j]==target){
						for(int k=0;k<length;++k){ 
							if(numbers[k]==temp[i]) result.push_back(k+1);
							if(numbers[k]==temp[j]) result.push_back(k+1);	
							}
						return result; 						
					}
					if(temp[i]+temp[j]>target) break;
				}			 
	    }
	};
	Solution twosum;
	vector<int> show;
	int a[100]=
	{
	230,863,916,585,981,404,316,785,88,12,
	70,435,384,778,887,755,740,337,86,92,
	325,422,815,650,920,125,277,336,221,847,
	168,23,677,61,400,136,874,363,394,199,
	863,997,794,587,124,321,212,957,764,173,
	314,422,927,783,930,282,306,506,44,926,
	691,568,68,730,933,737,531,180,414,751,
	28,546,60,371,493,370,527,387,43,541,
	13,457,328,227,652,365,430,803,59,858,
	538,427,583,368,375,173,809,896,370,789	
	};

	vector<int> numbers(a,a+100);
	int target=542;
	show=twosum.twoSum(numbers,target);	
	cout<<show[0]<<show[1]<<endl;
}
//result.push_back(find(numbers.begin(),numbers.end(),temp[i])+1);
//[Error] C:\Users\Administrator\Desktop\leetcood\TwoSum.cpp:15: error: no matching function for call to `std::vector<int, std::allocator<int> >::push_back(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >)'