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

int main() {
	double x[4],y[4];
	int i,j;
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&x[3],&y[3])!=EOF){
		double xbaru,ybaru;
		double selisihx, selisihy;
		//cari point yg sama
		int idx = 0;
		bool found = false;
		for(i=0;i<2;i++){
			for(j=2;j<4;j++){
				if(x[i]==x[j] && y[i]==y[j]){
					found = true; 
					swap(x[i],x[1]); swap(y[i],y[1]);
					swap(x[j],x[2]); swap(y[j],y[2]);
				}
			}
			
		}
		//if(x[1]==x[3] && y[1]==y[3]){swap(x[2],x[2]); swap(y[2],y[2]);}
		selisihx = x[3]-x[2];
		selisihy = y[3]-y[2];
		xbaru = x[0] + selisihx; ybaru = y[0]+selisihy;
		printf("%.3lf %.3lf\n",xbaru,ybaru);
	}
	return 0;
}