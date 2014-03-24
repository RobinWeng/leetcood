#include<iostream>
using namespace std;
int main(){
	class Solution{
		public:
			double findMedianSortdArrays(int A[],int m,int B[],int n){
				int total=m+n;
				if(total%2==1) return findk(A,m,B,n,total/2+1);
				else return (findk(A,m,B,n,total/2)+findk(A,m,B,n,total/2+1))/2.0;
			}
		private:
			double findk(int A[],int m,int B[],int n,int k){
				if(m>n) findk(B,n,A,m,k);
				if(m==0) return B[k-1];
				if(k==1) return min(A[0],B[0]);

				int parta=min(k/2,m);
				int partb=k-parta;
				if(A[parta-1]<B[partb-1]) findk(A+parta,m-parta,B,n,k-parta);
				if(A[parta-1]>B[partb-1]) findk(A,m,B+partb,n-partb,k-partb);
				else return B[partb-1];
			}
	};
	int a[]={
		3,4,5,6,7,8
	};
	int b[]={
		
	};
	int m=6,n=0;
	Solution d;
	cout<<d.findMedianSortdArrays(a,m,b,n)<<endl;
	cin>>m;
}
