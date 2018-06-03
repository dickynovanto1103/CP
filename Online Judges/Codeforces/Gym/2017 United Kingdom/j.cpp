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
	double a[100];
	a[0] = 2;
	a[1] = 1;
	a[2] = 1.0/2.0;
	a[4] = 1.0 / 4.0;
	a[8] = 1.0/8.0;
	a[16] = 1.0/16.0;
	int n;
	scanf("%d",&n);
	double sum = 0;
	for(int i=0;i<n;i++){
		int idx;
		scanf("%d",&idx);
		sum+=a[idx];
	}
	printf("%.9lf\n",sum);
	
	return 0;
};