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

int s[1000001];

int main(){
	int tc,i,j,n,a,b,c,x,y;
	scanf("%d",&tc);

	while(tc--){
		scanf("%d",&n);
		scanf("%d %d %d",&a,&b,&c);
		scanf("%d %d",&x,&y);
		s[0] = a;
		for(i=1;i<n;i++){
			s[i] = ((s[i-1]%c*b%c)%c + a%c) % c;
		}
		// sort(s,s+n);
		int v = 0;
		for(i=0;i<n;i++){
			v = ((v%y*x%y)%y+s[i]%y)%y;
		}
		printf("%d\n",v);
	}
	return 0;
};