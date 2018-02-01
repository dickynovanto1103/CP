#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

double degToRad(double a){return a*pi/180.0;}
double radToDeg(double a){return a*180.0/pi;}

struct point{
	double x,y;
	double z;
	point(){x = y = z = 0.0;}
	point(double _x, double _y, double _z): x(_x), y(_y), z(_z){}
	bool operator < (point other) const {
		if(fabs(x-other.x)>eps){return x < other.x;}
		return y<other.y;
	}
	bool operator == (point other){return ((fabs(x-other.x)<eps) && (fabs(y-other.y)<eps));}
};
double dist(point p1, point p2){return hypot(p1.z - p2.z, hypot(p1.x-p2.x,p1.y-p2.y));}

int countDigit(int n){
	if(n==0){return 1;}
	int cnt = 0;
	while(n){
		n/=10;
		cnt++;
	}
	return cnt;
}

int main() {
	int counter[11] = {0}, i,j;
	point listPoint[5050];
	i = 0;
	while(scanf("%lf %lf %lf",&listPoint[i].x,&listPoint[i].y,&listPoint[i].z),(listPoint[i].x || listPoint[i].y || listPoint[i].z)){i++;}
	int n = i;
	for(i=0;i<n;i++){
		point p1 = listPoint[i];
		double jarak = (double)inf;
		for(j=0;j<n;j++){
			if(j!=i){
				point p2 = listPoint[j];
				jarak = min(jarak,dist(p1,p2));
			}
		}
		int idx = (int)floor(jarak);
		counter[idx]++;
	}
	for(i=0;i<10;i++){
		int banyakSpasi = 4-countDigit(counter[i]);
		for(j=0;j<banyakSpasi;j++){printf(" ");}
		printf("%d",counter[i]);
	}
	printf("\n");


	return 0;
}