//the most difficute problem for me is thinging about that 
//the middle is odd or even
//judging the boundary alsp spend my much time
//the program does not sort all the number.
//it only sorts the first half and uses a vevtor to storage temporafily.
//the overall run time complexity is O(k).the worst situation is also O(M+N).
#include<iostream>
#include<vector>
using namespace std;
int main(){
	class Solution {
	public:
   		double findMedianSortedArrays(int A[], int m, int B[], int n) {
			int middle,totle=m+n;
			int *pa=A;
			int *pb=B;
			int cura=0;
			int curb=0;
			int count=0;
			double result;
			vector<int> temp;
			middle=totle/2+1;
			while(cura!=m&&curb!=n&&count<=middle){
				if(*pa<=*pb){
					temp.push_back(*pa);
					++pa;
					++cura;
					++count;
				}
				else{
					temp.push_back(*pb);
					++pb;
					++curb;
					++count;
				}
			}
			if(cura==m&&count<=middle){
				do{
					temp.push_back(*pb);
				++pb;
				++count;
				}while(count<=middle);
			}
			if(curb==n&&count<=middle){
				do{
					temp.push_back(*pa);
				++pa;
				++count;
				}while(count<=middle);
			}
			if(totle%2!=0)
				return temp[totle/2];
			else
				return (temp[totle/2-1]+temp[totle/2])/2.0;     
   		}
	};
	int a[]={2};
	int b[]={};
	int n=1;
	int m=0;
	Solution c;
	double d;
	d=c.findMedianSortedArrays(a,n,b,m);
	cout<<d<<endl;
	cin>>n;
}


	
