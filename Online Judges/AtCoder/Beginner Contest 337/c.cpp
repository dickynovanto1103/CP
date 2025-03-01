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

int a[300001];
int belakang[300001];
int first;

void solve(){
	int n;

	while(cin>>n) {
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i] == -1) {
				first = i;
			}else{
				belakang[a[i]] = i;
			}
		}

		printf("%d",first);
		int person = first;
		for(int i=0;i<n-1;i++){
			person = belakang[person];
			printf(" %d", person);
		}

		puts("");
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