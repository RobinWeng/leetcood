class Solution {
public:
    int removeDuplicates(int A[], int n) {
		if(n==0) return 0;
		int count=0;
		for(int i=1;i<n;i++){
			if(A[count]!=A[i])
				A[++count]=A[i];
		}
		return count+1;
    }
};

