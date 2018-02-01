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

const int maxn = 1010;

int main(){
	int t,c,n;
	int x[maxn], y[maxn], s[maxn] ,i,j;
	double detikSampaiAxis[maxn];
	scanf("%d %d %d",&t,&c,&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d",&x[i],&y[i],&s[i]);
		detikSampaiAxis[i] = (double)y[i]/(double)s[i];
		//printf("i: %d detikSampaiDaun : %.2lf\n",i,detikSampaiAxis[i]);
	}
	for(i=0;i<t;i++){
		int cnt = 0;
		for(j=0;j<n;j++){
			int absis = x[j];
			double detikSampaiCat = ((double)absis / (double)c) + i;
			//printf("absis: %d detikSampaiCat : %.2lf\n",absis,detikSampaiCat);
			if(fabs(detikSampaiCat-detikSampaiAxis[j])<eps){cnt++;}
		}
		printf("%d\n",cnt);
	}
	return 0;
};