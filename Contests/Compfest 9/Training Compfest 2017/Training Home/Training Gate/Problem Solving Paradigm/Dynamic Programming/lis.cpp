#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int parent[5010];
void print(int idx){
	if(parent[idx]!=-1){print(parent[idx]);}
	printf(" %d",idx);
}

int main() {
	int n,i,a[5010],j,lis[5010];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	memset(parent,-1,sizeof parent);
	for(i=0;i<n;i++){lis[i] = 1;}
	lis[0] = 1;
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(lis[i] < lis[j]+1 && a[j] < a[i]){
				lis[i] = lis[j]+1; parent[i] = j;
			}
		}
	}
	int ans=-1, idxAwal=-1;
	printf("array lis:\n");
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",lis[i]);
		if(ans < lis[i]){ans = lis[i]; idxAwal = i;}
	}
	printf("\n");
	printf("lis: %d\n",ans);
	printf("list idx:"); print(idxAwal);
	printf("\n");
	return 0;
}