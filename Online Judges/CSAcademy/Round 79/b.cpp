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

const int maxn = 2010;

int main(){
	int n,m,i,j;
	int x1[maxn], y1[maxn], x2[maxn], y2[maxn];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d %d",&x1[i],&y1[i]);
	}
	for(i=0;i<m;i++){
		scanf("%d %d",&x2[i],&y2[i]);
	}
	int counter[maxn];
	memset(counter, 0,sizeof counter);
	for(i=0;i<m;i++){
		double jarakMin = (double)inf*1000.0;
		int idx = 0;
		// printf("i: %d\n",i);
		for(j=n-1;j>=0;j--){
			double jarak = hypot(x1[j] - x2[i], y1[j] - y2[i]);
			// printf("j: %d jarak: %.2lf\n",j,jarak);
			if(jarakMin > jarak){
				jarakMin = jarak;
				idx = j;
			}
			if(fabs(jarakMin - jarak) < eps){
				idx = j;
			}
		}
		// printf("i: %d jarakMin: %.2lf\n",i,jarakMin);
		// printf("idx :%d\n",idx);
		counter[idx]++;
	}
	int cnt = 0;
	for(i=0;i<n;i++){
		if(counter[i] == 1){cnt++;}
	}
	printf("%d\n",cnt);
	return 0;
};