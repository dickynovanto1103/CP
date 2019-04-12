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

struct pasangan{
	int eye, horn;
};

const int maxn = 5e3 + 3;

pasangan a[maxn];

bool cmp(pasangan a, pasangan b){
	return a.horn < b.horn;
}

int main(){
	int n,w;
	int i,j;
	scanf("%d %d",&n,&w);
	int dp[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i].horn);
		a[i].eye = i;
		dp[i] = 1;
	}
	sort(a, a+n, cmp);
	for(i=1;i<n;i++){
		for(j=i-1;j>=0;j--){
			if(a[i].horn > a[j].horn){
				if(abs(a[i].eye - a[j].eye) <= w){
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
	}
	printf("%d\n",*max_element(dp, dp+n) - 1);


	return 0;
};