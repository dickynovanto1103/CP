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
	int n,x;
	int a[100010],i,j;
	scanf("%d %d",&n,&x);
	int sum = 0;
	for(i=0;i<n;i++){scanf("%d",&a[i]); sum+=a[i];}
	if((sum+n-1)==x){printf("YES\n");}
	else{printf("NO\n");}
	return 0;
};