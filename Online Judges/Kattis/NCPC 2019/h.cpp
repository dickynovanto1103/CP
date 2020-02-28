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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 55;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int minim = inf, idx;
	for(i=0;i<n-2;i++){
		int maks = max(a[i], a[i+2]);
		if(maks < minim){
			minim = maks;
			idx = i;
		}
	}
	printf("%d %d\n",idx+1, minim);
	return 0;
};