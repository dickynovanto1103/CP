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
	int tc,i,j;
	int n,m;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		string s[101];
		for(i=0;i<n;i++){
			cin>>s[i];
		}
		int cnt = 0;
		for(i=0;i<n-1;i++){
			if(s[i][m-1] == 'R'){cnt++;}
		}
		for(j=0;j<m-1;j++){
			if(s[n-1][j] == 'D'){cnt++;}
		}
		printf("%d\n",cnt);
	}
	
	return 0;
};