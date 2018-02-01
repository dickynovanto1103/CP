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

const int maxn = 20000005;

bool isVisited[maxn];

int main(){
	int a[3],i,j;
	for(i=0;i<3;i++){scanf("%d",&a[i]);}
	sort(a,a+3);
	memset(isVisited,false,sizeof isVisited);
	for(i=0;i<3;i++){
		int periode = a[i];
		for(j=0;j<maxn;j++){if(!isVisited[j]){break;}}
		int idx = j;
		for(j=idx;j<maxn;j+=periode){
			isVisited[j] = true;
		}
	}
	for(i=1;i<maxn;i++){
		if(!isVisited[i]){printf("NO\n"); return 0;}
	}
	printf("YES\n");
	return 0;
};