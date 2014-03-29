#include<iostream>
#include<map>
using namespace std;
class LRUCache{
public:
    LRUCache(int capacity) {
		size=capacity;
    }
    
    int get(int key) {
		map<int,int>::iterator it;
        if((it=mvalue.find(key))!=mvalue.end())
			return it->second;
		else
			return -1;
    }
    
    void set(int key, int value) {
	   map<int,int>::iterator it;
	   for(it=mcount.begin();it!=mcount.end();++it)
 	       ++(it->second);
       if(mvalue.find(key)!=mvalue.end()||mvalue.size()<size){
		   mvalue[key]=value;
		   mcount[key]=0;
	   }
	   else{
		   map<int,int>::iterator temp;
		   int max=0;
		   for(it=mcount.begin();it!=mcount.end();++it){
				if(it->second>max){
					temp=it;max=it->second;
				}
		   }
		   mcount.erase(temp);
		   mvalue.erase(mvalue.find(temp->first));
		   mvalue[key]=value;
		   mcount[key]=0;
	   }
    }
private:
	int size;
	map<int,int> mvalue;
	map<int,int> mcount;
};
int main(){
	LRUCache a(3);
	a.set(1,1);
	a.set(2,2);
	a.set(3,3);
	a.set(2,2);	
	a.set(4,4);
	a.set(5,5);		
	cout<<a.get(1)<<endl;
	cout<<a.get(2)<<endl;
	cout<<a.get(3)<<endl;
	cout<<a.get(4)<<endl;
	a.set(1,1);
	a.set(2,2);
	a.set(3,3);
	a.set(4,4);	
	cout<<a.get(1)<<endl;
	cout<<a.get(2)<<endl;
	cout<<a.get(3)<<endl;
	cout<<a.get(4)<<endl;
	int b;
	cin>>b; 

}

