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
	int n,i,j;
	int a[100001], temp[100010];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]); temp[i] = a[i];}
	sort(a,a+n);
	int cnt = 0;
	for(i=0;i<n;i++){
		if(a[i]!=temp[i]){cnt++;}
	}
	if(cnt>2){printf("NO\n");}
	else{printf("YES\n");}
	return 0;
};