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
typedef pair<int,ii> iii;
typedef vector<ii> vii;

int listAns[2000000];
iii listABC[300];

int main(){
	int a,b,i,j;
	int cnt = 0;

	bool done = false;
	for(i=2;i<=3000;i++){
		for(j=1;j<i;j++){
			// printf("i: %d j: %d --> ",i,j);
			a = i*i - j*j;
			b = 2*i*j;
			int c = i*i + j*j;
			// printf("%d %d %d ",a, b, c);
			if(__gcd(a,__gcd(b,c)) == 1){
				if((a+b+c)<=3000){
					// printf("%d %d %d\n",a, b, c);

					listAns[cnt] = (a+b+c);
					listABC[cnt] = make_pair(a, ii(b,c));
					cnt++;
					if(a == 1443 && b==76 && c==1445){done = true; break;}
				}
			}
		}
		if(done){break;}
	}

	int tc,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		ll ans = -1;
		for(i=0;i<cnt;i++){
			if(n%listAns[i] == 0) {
				ll pembagi = n / listAns[i];
				iii pas = listABC[i];
				ans = max(ans, (ll)pas.first*pembagi*(ll)pas.second.first*pembagi*(ll)pas.second.second*pembagi);
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
};