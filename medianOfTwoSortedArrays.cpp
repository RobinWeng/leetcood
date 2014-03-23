#include<iostream>
#include<vector>
using namespace std;
int main(){
	class Solution {
	public:
   		double findMedianSortedArrays(int A[], int m, int B[], int n) {
			int middle=(m+n)/2;
			int *pa=A;
			int *pb=B;
			int count=0;
			int curn=0,curm=0;
			vector<int> c;
			double result;
			while(curn!=n&&curm!=m&&count<=middle+1){
				if(*pa<=*pb){
					c.push_back(*pa);
					++pa;
					++curn;
					++count;
				}
				else{
					c.push_back(*pb);
					++pb;
					++curm;
					++count;
				}
			}
			if(curn==n&&count<=middle+1){
				do{
				c.push_back(*pb);
				++pb;
				++count;
				}while(count<=middle);
			}
			if(curm==m&&count!=count!=middle+1){
				do{
				c.push_back(*pa);
				++pa;
				++count;
				}while(count!=middle);
			}
			if(middle%2==0)
			       result=(c[middle]+c[middle+1])/2.0;
			else	result=c[middle];
			return result;     
   		}
	};
	int a[]={};
	int b[]={9};
	int n=0;
	int m=1;
	Solution c;
	double d;
	d=c.findMedianSortedArrays(a,n,b,m);
	cout<<d<<endl;
}


	
