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
		printf("Case #%d: ", tt);
		scanf("%d",&n);
		string s;
		cin>>s;
		char last = 'a';
		int cnt = 0;
		for(i=0;i<n;i++){
			if(s[i] == 'X' || s[i] == 'O') {
				if(last != s[i]) {
					cnt++;
					last = s[i];
				}
			}
		}

		printf("%d\n", max(cnt-1, 0));
	}
	
	return 0;
};