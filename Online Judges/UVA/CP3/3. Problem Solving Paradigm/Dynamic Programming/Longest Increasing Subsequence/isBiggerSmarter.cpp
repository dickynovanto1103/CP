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

struct pas{
	int id, w, val;
};

bool acompare(pas a, pas b){return a.val > b.val;}

int main() {
	int n = 0,i;
	pas a[1010];

	while(scanf("%d %d",&a[n].w,&a[n].val)!=EOF){
		a[n].id = n+1;
		n++;
	}
	for(int i=0;i<n;i++){
		printf("%d %d %d\n",a[i].id,a[i].w, a[i].val);
	}
	sort(a,a+n,acompare);
	printf("setelah terurut:\n");
	for(int i=0;i<n;i++){
		printf("%d %d %d\n",a[i].id,a[i].w, a[i].val);
	}
	
	return 0;
}