#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int gcd(int a, int b){return b==0? a: gcd(b,a%b);}

int main() {
	int tc,n,i;
	vi a;
	vi::iterator it;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int bil;
		for(i=0;i<n;i++){scanf("%d",&bil); a.pb(bil);}
		sort(a.begin(),a.end());
		it = unique(a.begin(),a.end());
		a.resize(distance(a.begin(),it));
		int ukuran = a.size();
		
		int fpb = 0;
		for(i=0;i<ukuran;i++){
			fpb = gcd(fpb,a[i]);
		}
		if(fpb==1){printf("YES\n");}
		else{printf("NO\n");}
		a.clear();
	}
	return 0;
}