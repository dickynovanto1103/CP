#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,m,t,i,a[10010];
	while(scanf("%d %d %d",&n,&m,&t)!=EOF){
		memset(a,0,sizeof a);
		a[n] = 1;
		a[m] = 1;
		int minim = min(n,m);
		for(i=minim;i<=t;i++){
			if(a[i]){
				if(i+n<=t){a[i+n] = max(a[i+n],a[i]+1);}
				if(i+m<=t){a[i+m] = max(a[i+m],a[i]+1);}
			}
		}
		if(a[t]){printf("%d\n",a[t]);}
		else{
			//antara ga bs makan samsek atau harus minum bir
			bool found = false;
			for(i=t-1;i>=0;i--){
				if(a[i]){
					printf("%d %d\n",a[i],t-i);
					found = true;
					break;
				}
			}
			if(!found){printf("0 %d\n",t);}
		}
	}
	return 0;
}