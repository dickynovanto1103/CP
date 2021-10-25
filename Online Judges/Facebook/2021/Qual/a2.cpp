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

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		string s;
		cin>>s;
		int dist[256][256];
		for(int i='A';i<='Z';i++){
			for(int j='A';j<='Z';j++){
				dist[i][j] = inf;	
			}
			dist[i][i] = 0;
		}

		int n = s.size();

		int k;
		scanf("%d",&k);
		for(int i=0;i<k;i++){
			char a, b;
			scanf("\n%c%c", &a, &b);
			dist[b][a] = 1;
		}

		for(int l='A';l<='Z';l++){
			for(int i='A';i<='Z';i++){
				for(int j='A';j<='Z';j++){
					dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
				}
			}
		}

		int ans = inf;
		for(int i=0;i<26;i++){
			char dest = i + 'A';
			int sum = 0;
			bool possible = true;
			for(int j=0;j<n;j++){
				if(dist[dest][s[j]] == inf) {
					possible = false;
					break;
				}
				// printf("dist[%c][%c] = %d\n", dest, s[j], dist[dest][s[j]]);
				sum += dist[dest][s[j]];
			}
			if(possible) {
				ans = min(ans, sum);	
			}
			
		}
		if(ans == inf){
			ans = -1;
		}
		printf("%d\n", ans);
		
	}
	
	return 0;
};