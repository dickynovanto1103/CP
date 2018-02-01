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

int main(){
	int n,d;
	int i,j;
	int dist[110];

	scanf("%d %d",&n,&d);
	for(i=0;i<n;i++){dist[i] = inf;}
	string kata;
	cin>>kata;
	dist[0] = 0;
	int idx = 1;
	int jarak = 1;
	bool tidakValid = false;
	while(idx<n){
		//printf("idx sekarang: %d\n",idx);
		for(i=idx;i<min(n,(idx+d));i++){dist[i]=dist[idx-1]+1;}
		tidakValid = true;
		for(i=idx+d-1;i>=idx;i--){
			if(kata[i]=='1'){
				idx = i+1; 
				//printf("idx: %d\n",idx);
				tidakValid = false;
				break;
			}
		}
		if(tidakValid && i==idx-1){printf("-1\n"); return 0;}
	}
	printf("%d\n",dist[n-1]);
	return 0;
};