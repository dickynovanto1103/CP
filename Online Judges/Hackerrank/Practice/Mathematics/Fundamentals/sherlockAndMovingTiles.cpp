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
	double l,s1,s2;
	int q;
	double luas;
	scanf("%lf %lf %lf",&l,&s1,&s2);
	scanf("%d",&q);
	//double diagonal = l*sqrt(2);
	double v1 = s1*sqrt(2) / 2.0;
	double v2 = s2*sqrt(2) / 2.0;
	while(q--){
		scanf("%lf",&luas);
		//double diagonal2 = sqrt(luas)*sqrt(2);
		double sisi = sqrt(luas);
		double time = abs(sisi-l) / abs(v1-v2);
		printf("%lf\n",time);
	}
	return 0;
}