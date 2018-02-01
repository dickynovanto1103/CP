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

double degToRad(double a){return a/180.0 * pi;}

int main() {
	double r,n;
	while(scanf("%lf %lf",&r,&n)!=EOF){
		double luasLingkaran = pi*r*r;
		double segitiga;
		segitiga = 0.5*r*r*sin(degToRad(360.0/n));
		//printf("luas segitiga: %lf\n",segitiga);
		printf("%.3lf\n",segitiga*n);
	}
	return 0;
}