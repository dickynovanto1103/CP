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

vector<vi> adj(27);
bool vis[200010];

int main(){
	int n,i,j;
	while(scanf("%d",&n) != EOF) {

		for(i=0;i<=n;i++) {
			vis[i] = false;
		}
		for(i=0;i<26;i++){
			adj[i].clear();
		}
		string s;
		cin>>s;
		// printf("n: %d s: ", n);
		// cout<<s<<endl;
		for(i=0;i<n;i++){
			char c = s[i];
			adj[c-'a'].pb(i);
		}

		int maksIdx = n;
		for(i=0;i<n;i++){
			if(vis[i]){break;}
			int maksBil = s[i] - 'a';

			bool foundMatch = false;
			for(j=0;j<maksBil;j++) {
				int idxLowerBound = lower_bound(adj[j].begin(), adj[j].end(), maksIdx) - adj[j].begin();
				// printf("j: %d c: %c idxLowerBound: %d\n",j, j+'a', idxLowerBound);
				for(int k=idxLowerBound-1;k>=0;k--){
					int idxSwap = adj[j][k];
					// printf("try idxSwap: %d\n", idxSwap);
					if(idxSwap < i || vis[idxSwap]) {
						break;
					}

					foundMatch = true;
					// printf("s[%d]: %c swapped with: s[%d]: %c\n", i, s[i], idxSwap, s[idxSwap]);
					swap(s[i], s[idxSwap]);
					vis[i] = vis[idxSwap] = true;
					
					maksIdx = idxSwap;
					break;
				}
				if(foundMatch) break;
			}

		}

		cout<<s<<endl;
	}
	
	
	return 0;
};