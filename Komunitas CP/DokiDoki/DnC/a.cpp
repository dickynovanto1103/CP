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

const int maxn = 1e5 + 5;

int main(){
	int n,u,i,j;
	int a[maxn];
	scanf("%d %d",&n,&u);
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}

	bool valid = false;
	double maks = 0;
	for(i=0;i<n;i++) {
		int targetMaks = a[i] + u;
		int idx = lower_bound(a,a+n,targetMaks) - a;
		if(idx==n){
			idx--;
		}
		if(a[idx] > targetMaks) {
			idx--;
		}

		if(idx <= (i + 1)){ // ga valid karena i+1 minimal buat j
			continue;
		}

		valid = true;
		double ans = (double)(a[idx] - a[i+1]) / (double)(a[idx] - a[i]);
		maks = max(maks, ans);
	}

	if(!valid){
		printf("-1\n");
	}else{
		printf("%.10lf\n",maks);	
	}
	
	return 0;
};