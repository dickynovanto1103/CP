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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	int a[81];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	int ans = 1000;
	int money = 1000;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			//buy at i, sell at j
			money = 1000;
			int st = money / a[i];
			money -= (a[i] * st);
			money += (st * a[j]);
			ans = max(ans, money);
		}
	}
	printf("%d\n",ans);
	
	return 0;
};