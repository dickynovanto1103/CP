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
	int n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		string s,r;
		cin>>s>>r;
		sort(s.begin(), s.end());
		sort(r.begin(), r.end());
		if(s == r){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
		// int cnt[2][2];
		// for(i=0;i<n;i++){
		// 	int bil = s[i] - '0';
		// 	cnt[0][bil]++;
		// 	bil = r[i] - '0';
		// 	cnt[1][bil]++;
		// }
		// if(cnt[0][0] == cnt[1][0] && cnt[0][1] == cnt[1][1]){printf("YES\n");}
		// else{printf("NO\n");}
	}
	return 0;
};