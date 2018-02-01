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

int main() {
	double x,y;
	scanf("%lf %lf",&x,&y);
	printf("atan: %lf atan2: %lf\n",radToDeg(atan(y/x)),radToDeg(atan2(y,x)));
	return 0;
}