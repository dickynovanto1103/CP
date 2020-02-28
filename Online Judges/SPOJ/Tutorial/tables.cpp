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
	int n,k,s,i,j;
	int a[1010];
	scanf("%d %d %d",&n,&k,&s);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int tot = k*s;
	sort(a,a+n, [](int a, int b){
		return a > b;
	});
	int cnt = 0;
	for(i=0;i<n;i++){
		tot -= a[i];
		cnt++;
		if(tot <= 0){
			break;
		}
	}
	printf("%d\n",cnt);
	return 0;
};