class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int numstation=gas.size();
		int sum=0;
		int total=0;
		int j=-1
		//		int j=0;   //the initial number is wrong
		for(int i=0;i<numstation;++i){
			sum+=gas[i]-cost[i];
			total+=gas[i]-cost[i];
			if(sum<0){
				j=i;
				sum=0;
			}
		}
//		return total>0?j+1:-1;  // total can equal 0
		return total>0?j+1:-1;
    }
};

