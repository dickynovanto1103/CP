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
	int i=0;
	int cost[3];
	fill(cost,cost+3,inf);
	int n;
	int a[1010];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	int minim = inf;
	for(i=0;i<=2;i++){
		int cost = 0;
		for(int j=0;j<n;j++){
			if(a[j]==i){continue;}
			int biaya = i-a[j];
			if(biaya<0){biaya+=3;}
			cost+=biaya;
		}
		minim = min(minim,cost);
	}
	printf("%d\n",minim);
	return 0;
};