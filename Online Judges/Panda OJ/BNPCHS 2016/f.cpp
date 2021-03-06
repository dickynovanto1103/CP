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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e3 + 4;
bool isNyala[maxn];

int main(){
	int tc,n,x,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Kasus #%d: ",tt);
		memset(isNyala,false,sizeof isNyala);
		scanf("%d %d",&n,&x);
		for(i=1;i<=x;i++){
			for(j=i;j<=n;j+=i){
				if(isNyala[j]){isNyala[j] = false;}
				else{isNyala[j] = true;}
			}
		}
		int cnt = 0;
		for(i=1;i<=n;i++){
			if(isNyala[i]){cnt++;}
		}
		printf("%d\n",cnt);
	}
	return 0;
};