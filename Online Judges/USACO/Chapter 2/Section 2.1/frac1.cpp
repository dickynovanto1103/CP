/*
ID: dickyno1
LANG: C++14
TASK: frac1
*/

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

bool cmp(ii a, ii b) {
	return a.first * b.second < a.second * b.first;
}

int main(){
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);

	vii v;
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=0;j<=i;j++){
			if(__gcd(i, j) == 1){
				v.pb(ii(j,i));
			}
		}
	}

	sort(v.begin(), v.end(), cmp);
	for(int i=0;i<v.size();i++){
		printf("%d/%d\n", v[i].first, v[i].second);
	}

	
	return 0;
};