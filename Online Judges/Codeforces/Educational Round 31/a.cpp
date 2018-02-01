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
	int n,t;
	int a[110],i,j;
	scanf("%d %d",&n,&t);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	for(i=0;i<n;i++){
		int sisa = 86400-a[i];
		t-=sisa;
		if(t<=0){break;}
	}
	printf("%d\n",i+1);
	return 0;
};