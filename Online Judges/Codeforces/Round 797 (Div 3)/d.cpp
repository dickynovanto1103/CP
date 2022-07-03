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

int main(){
	int tc, n, k;
	scanf("%d",&tc);
	int pref[200001];
	while(tc--){
		scanf("%d %d",&n,&k);
		string s;
		cin>>s;

		for(int i=0;i<n;i++){
			pref[i] = 0;
		}

		for(int i=0;i<n;i++){
			pref[i] = (i == 0 ? 0 : pref[i-1]);
			if(s[i] == 'B') {
				pref[i]++;
			}
		}

		int minim = inf;
		for(int i=0;i<=(n - k);i++){
			int banyakB = pref[i+k-1] - (i == 0 ? 0 : pref[i-1]);
			minim = min(minim, k - banyakB);
		}

		printf("%d\n", minim);
	}
	
	return 0;
};