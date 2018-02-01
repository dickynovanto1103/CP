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
	int n,m,i,j;
	int a[14],b[14];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	for(i=0;i<m;i++){scanf("%d",&b[i]);}
	sort(a,a+n); sort(b,b+m);
	reverse(a,a+n); reverse(b,b+m);
	int minim = min(n,m);
	int cnt1 = 0, cnt2 = 0;
	for(i=0;i<minim;i++){
		if(a[i]>b[i]){cnt1++;}
		else{cnt2++;}
	}
	printf("%d %d\n",cnt1,cnt2);
	return 0;
};