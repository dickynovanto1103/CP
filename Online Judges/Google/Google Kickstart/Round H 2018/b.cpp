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

const int maxn = 5000010;

int pref[maxn];
string kata;
	
int main(){
	int tc,i,j;
	int n;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		scanf("%d",&n);
		cin>>kata;
		
		for(i=0;i<n;i++){
			pref[i] = kata[i] - '0';
		}
		for(i=1;i<n;i++){
			pref[i] += pref[i-1];
		}
		int bagi2 = n/2 + (n%2 == 1? 1 : 0);
		int ans = pref[bagi2 - 1];
		int awal = 1, akhir = bagi2;

		while(akhir < n){
			ans = max(ans, pref[akhir] - pref[awal-1]);
			akhir++;
			awal++;
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	
	return 0;
};