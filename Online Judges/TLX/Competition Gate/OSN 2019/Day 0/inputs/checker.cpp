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

string s[1010];

int main(){
	int n,m,i,j;
	n = 1000, m = n;
	for(i=0;i<n;i++){
		cin>>s[i];
	}
	int dx[] = {-1,0,1,0};
	int dy[] = {0,1,0,-1};
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(s[i][j] == 'x'){
				int cnt = 0;
				for(int k=0;k<4;k++){
					int xbaru = i + dx[k], ybaru = j + dy[k];
					if(xbaru >= 0 && xbaru < n && ybaru >= 0 && ybaru < m) {
						if(k == 1){
							if(s[xbaru][ybaru] == '<'){cnt++;}
						}else if(k == 3) {
							if(s[xbaru][ybaru] == '>'){cnt++;}
						}
					}
				}
				if(cnt == 0){printf("%d %d\n",i,j);}
			}
			if((i+j) % 2 == 0){
				if(i%2 == 0){
					s[i][j] = '>';
				}else{
					s[i][j] = '<';
				}
			}
			// printf("%c",s[i][j]);
		}
		// printf("\n");
	}
	return 0;
};