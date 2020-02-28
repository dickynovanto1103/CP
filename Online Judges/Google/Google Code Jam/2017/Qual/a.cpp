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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		string s;
		int k;
		cin>>s>>k;
		int ans = 0;
		printf("Case #%d: ",tt);
		int n = s.length();
		for(i=0;i<=n-k;i++){
			if(s[i] == '-'){
				for(j=i;j<i+k;j++){
					s[j] = (s[j] == '+' ? '-' : '+');
				}
				ans++;
			}
		}
		bool valid = true;
		for(i=n-k+1;i<n;i++){
			// printf("i: %d\n",i);
			if(s[i] == '-'){valid = false; break;}
		}
		if(valid){printf("%d\n",ans);}
		else{printf("IMPOSSIBLE\n");}
	}
	return 0;
};