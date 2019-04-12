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
	scanf("%d",&n);
	int a[150];
	bool isVisited[150];
	memset(isVisited, false, sizeof isVisited);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int bil = a[n-1];
	for(i=1;i<=bil;i++){
		if(bil%i == 0){
			// printf("i: %d\n",i);
			int idx = lower_bound(a, a+n, i)-a;
			isVisited[idx] = true;
		}
	}
	int bil1;
	for(i=n-1;i>=0;i--){
		if(!isVisited[i]){bil1 = a[i]; printf("%d %d\n",bil,bil1); return 0;}
	}
	return 0;
};