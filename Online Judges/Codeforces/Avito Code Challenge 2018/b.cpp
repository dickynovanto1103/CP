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

const int maxn = 1e5 + 5;

int main(){
	int n,m,i,j;
	int a[maxn], x[maxn], y[maxn], b[maxn];
	scanf("%d",&n);
	// ll idx[maxn];
	int hargaMaks[maxn];
	memset(hargaMaks,-1,sizeof hargaMaks);
	int idx = 0;
	map<int,int> mapper1, mapper2;
	for(i=0;i<n;i++){

		scanf("%d %d",&a[i],&x[i]);
		
		mapper1[a[i]] = i;
	}
	scanf("%d",&m);
	
	for(i=0;i<m;i++){
		scanf("%d %d",&b[i],&y[i]);
		mapper2[b[i]] = i;
		
	}
	ll sum = 0;
	bool isVisited[maxn];
	memset(isVisited,false,sizeof isVisited);
	for(i=0;i<n;i++){
		if(mapper2.find(a[i]) == mapper2.end()) {
			sum+=x[i];
		}else{
			//cari maks
			int idx = mapper2[a[i]];
			sum+=max(x[i], y[idx]);
			isVisited[idx] = true;
		}
	}
	for(i=0;i<m;i++){
		if(mapper1.find(b[i]) == mapper1.end()) {
			sum+=y[i];
		}else{
			int idx = mapper1[b[i]];
			if(isVisited[idx]){continue;}
			isVisited[idx] = true;
			sum+=max(y[i], x[idx]);
		}
	}

	printf("%lld\n",sum);
	return 0;
};