class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		add(digits,1);
		return digits;
    }
	void add(vector<int> &digits,int digit){
		int carry=digit;
		for(vector<int>::reverse_iterator it=digits.rbegin();it<digits.rend();++it){
			*it+=carry;
			carry=*it/10;
			*it=*it%10;
		}
		if(carry==1) digits.insert(digits.begin(),1);
	}
};

