class Solution {
public:
    int removeDuplicates(int A[], int n) {
		if(n<3) return n;
		int count=2;
		for(int i=2;i<n;++i){
			if(A[i]==MAX_INT) break;
			if(A[i]==A[i-1]&&A[i-1]==A[i-2]){
				for(int j=i;j<n-1;++j){
					A[j]=A[j+1];
				}
				A[n-1]=MAX_INT;
			}
			else count++;
		}
		return count;
    }
};

