#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,tt,n,i,a[5001],b[5001];
	scanf("%d",&tc);
	for(tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		sort(a,a+n);
		reverse(a,a+n);
		for(i=0;i<n;i++){scanf("%d",&b[i]);}
		int sisa = 0;
		bool found = true;
		for(i=0;i<n;i++){
			a[i]+=sisa;
			if(a[i]<b[i]){found = false; break;}
			else{
				sisa = a[i]-b[i];
			}
		}
		if(found){printf("Yes he made it\n");}
		else{printf("IMPOSSIBLE\n");}
	}
	return 0;
};