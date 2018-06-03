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

int main(){
	int n,k,i,j;
	int a[200010];
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	sort(a,a+n);
	if(k==0){
		if(a[0] == 1){printf("-1\n");}
		else{printf("%d\n",a[0]-1);}
	}else{
		int idx = upper_bound(a,a+n,a[k-1]) - a;
		idx--;
		if((idx+1)>k){printf("-1\n");}
		else{printf("%d\n",a[k-1]);}
	}
	return 0;
};