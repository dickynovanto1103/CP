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

const int maxn = 110;

int main(){
	int n,d,u,i,j,tc;
	int a[maxn];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&n,&u,&d);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		bool isUsed = false;
		for(i=0;i<n-1;i++){
			if(a[i] == a[i+1]){continue;}
			if(a[i] > a[i+1]){
				if((a[i] - a[i+1]) > d){
					if(!isUsed){
						isUsed = true;
					}else{
						break;
					}
				}
			}else{
				if((a[i+1] - a[i])>u){break;}
			}
		}
		printf("%d\n",i+1);
	}
	return 0;
};