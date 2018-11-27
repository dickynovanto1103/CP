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

const int maxn = 5001;

int dp[maxn];

int main(){
	int n,i,j;
	int a[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		bool isPositive = (a[i] > 0 ? true: false);
		for(j=i-1;j>=0;j--){
			if(isPositive){//cari yang negatif
				if(a[j] < 0 && abs(a[j]) < a[i]){
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}else{
				if(a[j] > 0 && a[j] < abs(a[i])){
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			
		}
	}
	printf("%d\n",*max_element(dp,dp+n) + 1);
	return 0;
};