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

const int maxn = 2e6 + 6;

string s[maxn];

int main(){
	int tc,i,j,n,m,k;

	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		scanf("%d %d %d",&n,&m,&k);
		for(i=0;i<n;i++){
			cin>>s[i];
		}
		int minim = 0;
		for(j=0;j<m;j++){
			if(s[k-1][j] == 'X') {
				minim++;
			}
		}

		
	}
	
	return 0;
};