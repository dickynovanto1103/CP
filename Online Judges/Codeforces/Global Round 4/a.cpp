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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	int a[101];
	scanf("%d",&n);
	int tot = 0;
	for(i=0;i<n;i++){scanf("%d",&a[i]); tot += a[i];}
	int sum = a[0];
	vi ans;
	ans.pb(1);
	for(i=1;i<n;i++){
		if(a[0] >= 2*a[i]){
			sum += a[i];
			ans.pb(i+1);
		}
	}
	int minim = tot/2;
	minim++;
	if(sum >= minim){
		int ukuran = ans.size();
		printf("%d\n",ukuran);
		for(i=0;i<ukuran;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}else{
		printf("0\n");
	}
	return 0;
};