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
	int n,i,a[1010];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	int batas = n-1;
	int cnt = 0;
	for(i=1;i<batas;i++){
		if((a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1])){cnt++;}
	}
	printf("%d\n",cnt);
	return 0;
};