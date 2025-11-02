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

ll power(int a, int b) {
	ll ans = 1;
	for(int i=0;i<b;i++){
		ans *= a;
	}

	return ans;
}

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void solve(){
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF) {
		vector<string> v;
		string s;
		for(int i=0;i<n;i++){
			cin>>s;
			v.pb(s);
		}

		set<string> sets;

		for(int i=0;i+m-1<n;i++){
			for(int j=0;j+m-1<n;j++){
				int startR = i, startC = j, endR = i + m - 1, endC = j + m - 1;
				string newS;
				for(int k = startR; k<=endR;k++){
					for(int l=startC; l <=endC;l++){
						newS += v[k][l];
					}
				}

				sets.insert(newS);
			}
		}

		printf("%d\n", sets.size());
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};