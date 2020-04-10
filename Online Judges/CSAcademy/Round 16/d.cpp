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
	int n, k, i,j;
	scanf("%d %d",&n,&k);
	string s[100000];
	for(i=0;i<n;i++){cin>>s[i];}
	vi list;
	for(i=0;i<n;i++){list.pb(i);}
	for(int j=0;j<k;j++){
		int ukuran = list.size();
		vi temp;
		bool vis[26];
		memset(vis, false, sizeof vis);
		for(i=0;i<ukuran;i++){
			char tebak = s[list[i]][j];
			if(vis[tebak-'a']){
				continue;
			}
			printf("%c\n",tebak);
			fflush(stdout);
			int ans;
			scanf("%d",&ans);
			if(ans == 1){
				for(int l=0;l<ukuran;l++){
					if(s[list[l]][j] == tebak){
						temp.pb(list[l]);
					}
				}
				list = temp;
				break;
			}else{
				vis[tebak-'a'] = true;
			}
		}
	}
	
	return 0;
};