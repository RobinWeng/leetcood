class Solution {
public:
    int trap(int A[], int n) {
		int lh,rh,min,max;
		lh=0;rh=n-1;
		int result=0;
		while(lh<rh){
			if(A[lh]<=A[rh]){
				min=A[lh];
				while(min>A[++lh]){
					result+=min-A[lh];
				}
			}
			else{
				min=A[rh];
				while(min>A[--rh]){
					result+=min-A[rh];
				}
			}
		}
		return result;
    }
};
//i didnot think about the bound at the first.
//
