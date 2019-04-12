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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int main(){
	int n,i,j,x;
	scanf("%d %d",&n,&x);
	int a[maxn];
	int ans = 0;
	int maks = 0, minim = inf;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i] <= x/2){ans++; maks = max(maks, a[i]);}
		else{minim = min(minim, a[i]);}
	}
	
	if(maks + minim <= x){ans++;}
	printf("%d\n",max(ans, 1));
	
	
	// sort(a,a+n);
	// int ans = 1;
	// for(i=1;i<n;i++){
	// 	// printf("%d %d %d\n",i,a[i],a[i-1]);
	// 	if((a[i] + a[i-1]) > x){
	// 		break;
	// 	}else{
	// 		ans++;
	// 	}
	// }
	// printf("%d\n",ans);
	return 0;
};