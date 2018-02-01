#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct point{
	ll x,y;
};

int orientation(point p1, point p2, point p3){
	ll val = (p2.y-p1.y)*(p3.x-p2.x) - (p3.y-p2.y)*(p2.x-p1.x);
	if(val==0){return 0;} //collinear
	return (val>0) ? 1:2; // 1 adalah clockwise dan 2 adalah counter clockwise
}

bool onSegment(point p, point q, point r){
	if(q.x >=min(p.x,r.x) && q.x <= max(p.x,r.x)
		&& q.y >=min(p.y,r.y) && q.y <= max(p.y,r.y)){return true;}
	return false;
}

bool isInRectangle(ll xmin, ll ymin, ll xmax, ll ymax, point p, point q){
	if((p.x>=xmin && p.x<=xmax && p.y>=ymin && p.y<=ymax) || (q.x>=xmin && q.x<=xmax && q.y>=ymin && q.y<=ymax)){return true;}
	return false;
}

bool isIntersect(point p1, point q1, point p2, point q2){
	ll o1 = orientation(p1,q1,p2);
	ll o2 = orientation(p1,q1,q2);
	ll o3 = orientation(p2,q2,p1);
	ll o4 = orientation(p2,q2,q1);

	if(o1!=o2 && o3!=o4){return true;}

	//special case
	if(o1==0 && onSegment(p1,p2,p1)){return true;}
	if(o2==0 && onSegment(p1,q2,p1)){return true;}
	if(o3==0 && onSegment(p2,p1,q2)){return true;}
	if(o4==0 && onSegment(p2,q1,p2)){return true;}
	return false;
}


int main() {
	int n,i;
	scanf("%d",&n);
	point p1, p2;
	point p3,p4,p5,p6;
	while(n--){
		scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y,&p5.x,&p5.y);
		p4.x = p5.x; p4.y = p3.y;
		p6.x = p3.x; p6.y = p5.y;

		//printf("%lld %lld, %lld %lld, %lld %lld, %lld %lld\n",p3.x,p3.y,p4.x,p4.y,p5.x,p5.y,p6.x,p6.y);
		bool found = isIntersect(p1,p2,p3,p4);
		int xmin = min(p3.x, p5.x);
		int ymin = min(p3.y, p5.y);
		int xmax = max(p3.x, p5.x);
		int ymax = max(p3.y, p5.y);
		if(!found){found = isInRectangle(xmin, ymin, xmax, ymax, p1,p2);}
		if(!found){found = isIntersect(p1,p2,p5,p4);}
		if(!found){found = isIntersect(p1,p2,p5,p6);}
		if(!found){found = isIntersect(p1,p2,p3,p6);}
		if(!found){printf("F\n");}
		else{printf("T\n");}
	}
	return 0;
}