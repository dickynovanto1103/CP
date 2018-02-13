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

const int maxn = 1e5 + 5;

int main(){
	int tc,n,i,j;
	int a[maxn], temp[maxn];
	bool isVisited[maxn];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int minim = inf;
		
		for(i=0;i<n;i++){scanf("%d",&temp[i]); minim = min(minim,temp[i]);}

		int ans = minim;
		for(i=1;i<=2;i++){
			for(j=0;j<n;j++){a[j] = temp[j];}
			memset(isVisited,false,sizeof isVisited);
			int tebak = minim + i;

			for(j=0;j<n-1;j++){
				if(a[j]>tebak){
					if(isVisited[j]){continue;}
					a[j]--; a[j+1]++;
					// isVisited[j] = true;
				}else if(a[j]<tebak){
					a[j]++; a[j+1]--;
					isVisited[j+1] = true;
				}
			}
			bool isValid = true;
			for(j=0;j<n;j++){
				if(a[j]<tebak){isValid = false; break;}
			}
			if(!isValid){break;}
			else{ans = tebak;}
		}
		
		printf("%d\n",ans);
	}
	return 0;
};