class Solution {
public:
    int climbStairs(int n) {
		if(n<2) return n;
		int i=1;
		int sum=1;
		int divide=1;
		int result=1;
		while(n-i>=i){
			int sum=1;
			divide*=i;
			for(int j=0;j<i;++j){
				sum*=(n-i-j);
			}
			result+=sum/divide;
			++i;
		}
		return result;
    }
	int climbStairs(int n){
		if(n<3) return n;
		int s2=2,s1=1;
		int sn=0;
		for(int i=3;i<n;i++){
			sn=s1+s2;
			s1=s2;
			s2=sn;
		}
		return sn;
	}
	// i didnot aware that this question can be divide into small questions
};

