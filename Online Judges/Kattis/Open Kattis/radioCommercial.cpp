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

const int maxn = 1e5 + 5;

int main(){
	int n,i,j,p;
	int a[maxn];
	scanf("%d %d",&n,&p);
	for(i=0;i<n;i++){scanf("%d",&a[i]); a[i] -= p;}
	int sum = 0, maks = 0;
	for(i=0;i<n;i++){
		sum += a[i];
		if(sum < 0){
			sum = 0;
		}
		maks = max(maks, sum);
	}
	printf("%d\n",maks);
	return 0;
};