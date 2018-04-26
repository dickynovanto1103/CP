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
	int n,m,i=0,j=0;
	int a[maxn], b[maxn];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	for(i=0;i<m;i++){scanf("%d",&b[i]);}
	i = 0; j = 0;
	int jumlah1 = a[i], jumlah2 = b[j];
	int cnt = 0;
	while(i<n && j<m){
		if(jumlah1 > jumlah2){
			j++;
			jumlah2+=b[j];
		}else if(jumlah1 < jumlah2) {
			i++;
			jumlah1+=a[i];
		}else{
			cnt++;
			i++;
			j++;
			jumlah1 = a[i]; jumlah2 = b[j];
		}
	}
	printf("%d\n",cnt);
	return 0;
};