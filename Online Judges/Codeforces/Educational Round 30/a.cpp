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
	int n,k,x;
	int a[110],i,j;
	scanf("%d %d %d",&n,&k,&x);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	sort(a,a+n);
	reverse(a,a+n);
	for(i=0;i<k;i++){
		a[i] = x;
	}
	int sum = 0;
	for(i=0;i<n;i++){
		sum+=a[i];
	}
	printf("%d\n",sum);
	return 0;
};