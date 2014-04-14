class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
       int max=0;
	   for(int i=0;i<height.size();++i){
		   int tempmax
		   for(int j=i-1;j>-1;++j){
			   if(height[j]>=height[i]) tempmax+=height[i];
			   else break;
		   }
		   for(int k=i+1;k<height.size();++k){
			   if(height[k]>=height[i]) tempmax+=height[i];
			   else break;
		   }
		   max=(max>=tempmax)?max:tempmax;
	   }
	   return max;
    }
};

