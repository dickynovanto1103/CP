#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct point_i{
	ll x,y;
	point_i(){x = 0; y=0;}
	point_i(ll _x, ll _y){x = _x; y = _y;}
};

struct vec{
	ll x,y;
	vec(ll _x, ll _y): x(_x), y(_y){}
};

vec toVec(point_i a, point_i b){
	return vec(b.x-a.x, b.y-a.y);
}

ll cross(vec a, vec b){return a.x*b.y - a.y*b.x;}
bool ccw(point_i p, point_i q, point_i r){
	return cross(toVec(p,q), toVec(p,r)) > 0;
}
bool collinear(point_i p, point_i q, point_i r){
	return cross(toVec(p,q), toVec(p,r)) == 0;	
}

int main() {
	int tc,i;
	point_i p1,p2,p3;
	scanf("%d",&tc);
	int test = 1;
	while(tc--){
		printf("Case #%d: ",test++);
		scanf("%lld %lld %lld %lld %lld %lld",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y);
		//if(hasil)
		if(collinear(p1,p2,p3)){
			printf("rasi ular\n");
		}else{
			if(ccw(p1,p2,p3)){printf("rasi kucing\n");}
			else{printf("rasi anjing\n");}
		}
		/*double xnyata = p3.x;
		if(xnyata > xseharusnya){printf("rasi anjing\n");}
		else if(xnyata < xseharusnya){printf("rasi kucing\n");}
		else{printf("rasi ular\n");}*/
	}
	return 0;
}