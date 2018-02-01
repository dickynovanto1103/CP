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
	int n,i,a[55],w[55], sumW = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	for(i=0;i<n;i++){scanf("%d",&w[i]); sumW+=w[i];}

	int pembilang = 0;
	for(i=0;i<n;i++){
		pembilang+=(a[i]*w[i]);
	}
	printf("%.1lf\n",(double)pembilang/(double)sumW);

	return 0;
};