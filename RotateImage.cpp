class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		int n=matrix.size();
		int firstline,lastline;
		firstline=0;lastline=n-1;
		while(firstline<lastline){
			for(int i=0;i<n;++i){
				int temp;
				temp=matrix[firstline][i];
				matrix[firstline][i]=matrix[lastline][i];
				matrix[lastline][i]=temp;
			}
			++firstline;--lastline;
		}
		for(int i=0;i<n-1;++i){
			for(int j=i+1;j<n;++j){
				int temp;
				temp=matrix[i][j];
				matrix[i][j]=matrix[j][i];
				matrix[j][i]=temp;
			}
		}
    }
};

