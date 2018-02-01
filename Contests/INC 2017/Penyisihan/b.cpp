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

int a[100010];
struct cmp{
	bool operator()(const ii& a, const ii& b){
		return a.second
	}
}
set<ii> s;

int main(){
	int n,m,k;
	int i,j;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	
	if(m==1 || k>=m){printf("%d\n",n); return 0;}
	sort(a,a+m);
	for(i=1;i<m-1;i++){
		int jarakKiri = a[i] - a[i-1], jarakKanan = a[i+1] - a[i];
		int tot = jarakKanan/2 + jarakKiri/2 + 1;
		mapper[i] = tot;
		
	}
	//ujung kiri
	int jarakKiri = a[0] - 1, jarakKanan = a[1] - a[0];
	int tot = jarakKanan/2 + jarakKiri + 1;
	mapper[0] = tot;
	//ujung kanan
	jarakKiri = a[m-1] - a[m-2]; jarakKanan = n - a[m-1];
	tot = jarakKanan + jarakKiri/2 + 1;
	mapper[m-1] = tot;
	printf("isi mapper\n");
	for(it=mapper.begin(); it!=mapper.end();it++){
		printf("%d %d\n",it->first, it->second);
	}

	return 0;
};