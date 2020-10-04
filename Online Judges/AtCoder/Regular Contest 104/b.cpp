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
	int n,i,j;
	string s;
	
	map<char, int> mapper;
	mapper['A'] = 0;
	mapper['T'] = 1;
	mapper['C'] = 2;
	mapper['G'] = 3;
	while(scanf("%d",&n) !=EOF){
		cin>>s;
		int ans = 0;
		for(i=0;i<n;i++){
			int cnt[4];
			memset(cnt, 0, sizeof cnt);
			for(j=i;j<n;j++){
				char c = s[j];
				cnt[mapper[c]]++;
				if(cnt[0] == cnt[1] && cnt[2] == cnt[3]){
					ans++;
				}
			}
		}
		printf("%d\n",ans);	
	}
	
	
	return 0;
};