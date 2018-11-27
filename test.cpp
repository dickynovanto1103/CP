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
	double a[10], b[10];
	int i,j;
	double sum = 0;
	for(i=0;i<8;i++){
		scanf("%lf",&a[i]);
	}
	for(i=0;i<8;i++){
		scanf("%lf",&b[i]);
	}

	for(i=0;i<8;i++){
		sum += ((a[i] - b[i])*(a[i] - b[i]));
	}
	printf("%.8lf\n",sum);
	return 0;
};