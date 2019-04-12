#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<double,double> ii;
typedef vector<ii> vii;

int main(){
	double xawal, yawal;
	int n,i,j;
	int tc = 1;
	ii cur;
	while(scanf("%lf %lf %d",&xawal,&yawal,&n) != EOF) {
		printf("Case %d: ",tc++);
		cur = ii(xawal,yawal);
		double pjg = sqrt(xawal*xawal + yawal*yawal);
		if(pjg > 2){printf("OUT\n"); continue;}
		bool foundOut = false;
		for(i=1;i<n;i++){
			double x = cur.first, y = cur.second;
			cur.first = x*x - y*y;
			cur.second = 2.0*x*y;
			cur.first += xawal, cur.second += yawal;
			pjg = sqrt(cur.first*cur.first + cur.second*cur.second);
			if(pjg > 2){foundOut = true; printf("OUT\n"); break;}
		}
		if(!foundOut){printf("IN\n");}
	}
	return 0;
};