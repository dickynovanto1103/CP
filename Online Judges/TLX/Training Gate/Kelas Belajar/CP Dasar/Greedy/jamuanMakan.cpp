#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct pas{
	int s,e;
};

bool cmp(pas a, pas b){return a.e < b.e;}

int main() {
	int n,i,s,d;
	pas pair[100010];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&s,&d);
		pair[i].s = s; pair[i].e = s+d;
	}
	sort(pair,pair+n,cmp);
	/*for(i=0;i<n;i++){
		printf("%d %d",pair[i].s,pair[i].e);
	}*/
	int start = 0, cnt = 0;

	for(i=0;i<n;i++){
		if(pair[i].s >= start){
			//printf("yang diambil: %d hingga %d\n",pair[i].s,pair[i].e);
			cnt++;
			start = pair[i].e;
		}
	}
	printf("%d\n",cnt);
	return 0;
}