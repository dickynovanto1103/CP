#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int tc,a,b,x;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&a,&b,&x);
		//double hasil = a**b;
		//printf("hasil: %lf\n", hasil);
		double ans = pow(a,b);
		int hasil1 = (int)floor(ans / (double)x) * x;
		int hasil2 = (int)ceil(ans / (double)x) * x;
		double jarak1 = fabs((double)hasil1-ans);
		double jarak2 = fabs((double)hasil2-ans);
		if(jarak1>jarak2){printf("%d\n",hasil2);}
		else{printf("%d\n",hasil1);}
	}
	return 0;
}