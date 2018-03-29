#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<double,int> ii;
typedef vector<ii> vii;

const int maxn = 1e3 + 3;



int main(){
	int tc,n,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++) {
		set<ii> s;
		printf("Case #%d: ",tt);
		double awalX, awalY;
		double x[maxn], y[maxn];
		scanf("%lf %lf",&awalX,&awalY);
		double inf = 1.0/0.0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%lf %lf",&x[i], &y[i]);
			double m = (awalY - y[i]) / (awalX-x[i]);
			ii pas;
			if(m==inf){
				if(y[i] < awalY){
					pas = ii(m,-1);
				}else{
					pas = ii(m,1);
				}
			}else if(m==0) {
				if(x[i] < awalX) {
					pas = ii(m,-1);
				}else{
					pas = ii(m,1);
				}
			}else{
				if(y[i] > awalY){
					pas = ii(m,1);
				}else{
					pas = ii(m,-1);
				}
			}
			s.insert(pas);
		}

		printf("%d\n",s.size());
	}
	
	
	return 0;
};