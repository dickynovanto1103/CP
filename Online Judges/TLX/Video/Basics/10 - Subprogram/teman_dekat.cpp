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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int power(int num, int exp) {
	int ans = 1;
	for(int i=0;i<exp;i++){
		ans *= num;
	}

	return ans;
}

int x[1000], y[1000];

int hit(int i, int j, int d) {
	return power(abs(x[i] - x[j]), d) + power(abs(y[i] - y[j]), d);
}

int main(){
	int n,d;
	scanf("%d %d",&n,&d);
	
	for(int i=0;i<n;i++){
		scanf("%d %d",&x[i],&y[i]);
	}


	int minim = inf; int maks = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int ans = hit(i,j,d);
			minim = min(minim, ans);
			maks = max(maks, ans);
		}
	}

	printf("%d %d\n", minim, maks);
	
	return 0;
};