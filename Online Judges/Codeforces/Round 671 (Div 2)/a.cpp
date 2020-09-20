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
	while(tc--){
		scanf("%d",&n);
		string s;
		cin>>s;
		//player 1 tries to remove all even1, and player 2 tries to remove all odd2
		bool vis[1001];
		memset(vis, false, sizeof vis);
		int turn = 0;
		int left = n;
		while(left > 1){
			int last = -1;
			bool ketemu = false;
			for(i=n-1;i>=0;i--) {
				int bil = s[i] - '0';
				if(vis[i]){continue;}
				if(i % 2 == turn % 2){
					if(i%2 == 1){
						if(bil % 2 == 1){
							ketemu = true;
							vis[i] = true;
							break;
						}else{
							last = i;
						}
					}else{
						if(bil % 2 == 0){
							ketemu = true;
							vis[i] = true;
							break;
						}else{
							last = i;
						}
					}
				}
			}
			if(last != -1 && !ketemu){
				vis[last] = true;
			}
			left--;
			turn = 1 - turn;
		}
		for(i=0;i<n;i++){
			if(!vis[i]){
				int bil = s[i] - '0';
				if(bil % 2 == 1){printf("1\n");}
				else{printf("2\n");}
			}
		}
	}
	
	return 0;
};