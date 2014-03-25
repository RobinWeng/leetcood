//today i encounter so many problems that make me crazy
//the first question is i donot know how to use struct.
//I am puzzled about using Class.
//when the struct is globle type to solve the problem.
//at the beginnig,i consider the comparison of double,
//but it seemly donnot be considered.
//i donnot think about the boundary.
//for examples:1.the vector is empty. 2.the points are duplicate
#include<iostream>
#include<vector>
#include<map>
using namespace std;
	struct Point{
		int x;
		int y;
		Point() : x(0), y(0) {}
		Point(int a, int b) : x(a), y(b) {}
	};
int main(){
	class Solution{
		public:
			int maxPoints(vector<Point> &points){
				map<double,int> mincline;
				int maxnum=0;
				int duplicate;
				int isize=points.size();
				if(isize==0) return 0;
				for(int i=0;i<isize;++i){
					mincline.clear();
					duplicate=0;
					for(int j=i+1;j<isize;++j){
						if(points[j].y==points[i].y&&points[j].x==points[i].x){
							++duplicate;
							continue;
						}
						double k=((points[j].x-points[i].x)==0)?INT_MAX:(double)(points[j].y-points[i].y)/(points[j].x-points[i].x);
						++mincline[k];
					}
					map<double,int>::iterator it;
					int maxtemp=0;
					for(it=mincline.begin();it!=mincline.end();++it){
						if(it->second > maxtemp) maxtemp=it->second;
					}
					if(maxnum<maxtemp+duplicate) maxnum=maxtemp+duplicate;
				}
				return maxnum+1;
			}
	};
	vector<Point> vp;
//	Point pa(1,1);
//	Point pb(1,1);
//	Point pc(1,1);
//	Point pd(3,5);
//	vp.push_back(pa);
//	vp.push_back(pb);
//	vp.push_back(pc);
//	vp.push_back(pd);
	Solution a;
	int b;
	cout<<a.maxPoints(vp)<<endl;
	cin>>b;
	return 0;
}
