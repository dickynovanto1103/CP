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
	int n,i,j,l;
	scanf("%d %d",&n,&l);
	int a[1000];
	int sum = 0;
	for(i=1;i<=n;i++){
		a[i] = l + i - 1;
		sum += a[i];
	}
	int temp = sum;
	int minim = inf;
	int ans;
	for(i=1;i<=n;i++){
		temp -= a[i];
		if(abs(temp - sum) < minim) {
			minim = abs(temp - sum);
			ans = temp;
		}
		temp = sum;
	}
	printf("%d\n",ans);
	return 0;
};