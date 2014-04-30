#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
		int m=matrix.size();
		int n=matrix[0].size();
		bool first_row_have_zero=false;
		bool first_cor_have_zero=false;
		for(int i=0;i<n;++i){
			if(matrix[0][i]==0) {
				first_row_have_zero=true;
				break;
			}
		}
		for(int i=0;i<m;++i){
			//if(matrix[m][0]==0) {        this error let timerun out
			if(matrix[i][0]==0) {
				first_cor_have_zero=true;
				break;
			}
		}
		for(int i=1;i<m;++i){
			for(int j=1;j<n;++j){
				if(matrix[i][j]==0){
					matrix[i][0]=0;
					matrix[0][j]=0;
				}
			}
		}
		for(int i=1;i<m;++i){
			for(int j=1;j<n;++j){
				if(matrix[0][j]==0||matrix[i][0]==0){
					matrix[i][j]=0;
				}
			}
		}
		if(first_row_have_zero){
			for(int i=0;i<n;++i) matrix[0][i]=0;
		}
		if(first_cor_have_zero){
			for(int i=0;i<m;++i) matrix[i][0]=0;
		}
    }
};
int main(){
	vector<int> row(1,0);
	vector<vector<int> > matrix;
	matrix.push_back(row);
	int n=matrix[0].size();
	Solution a;
	a.setZeroes(matrix);
}

