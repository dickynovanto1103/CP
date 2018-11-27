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
	int n,l,a;
	int t[maxn], waktu[maxn];
	scanf("%d %d %d",&n,&l,&a);
	int i;
	for(i=0;i<n;i++){scanf("%d %d",&t[i], &waktu[i]);}
	int start = 0;
	int ans = 0;

	for(i=0;i<n;i++){
		int selisih = (t[i] - start);
		if(selisih >= a){
			ans += (selisih/a);
		}
		start = t[i] + waktu[i];
	}
	int sisa = l - start;
	ans += (sisa/a);
	printf("%d\n",ans);
	return 0;
};