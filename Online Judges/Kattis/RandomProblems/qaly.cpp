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
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n;
	double a,b, sum = 0;
	scanf("%d",&n);
	while(n--){
		scanf("%lf %lf",&a,&b);
		sum += (a*b);
	}
	printf("%.9lf\n",sum);
	return 0;
};