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
	int n,a,b,i,j;
	string kata;
	scanf("%d %d %d",&n,&a,&b);
	cin>>kata;
	vi listBanyak;
	int cnt = 0;
	for(i=0;i<n;i++){
		if(kata[i]=='.'){cnt++;}
		else{
			listBanyak.pb(cnt);
			cnt = 0;
		}
	}
	if(cnt!=0){listBanyak.pb(cnt);}
	int ans = 0;
	for(i=0;i<listBanyak.size();i++) {
		int banyak = listBanyak[i];
		if(banyak % 2 ==1) {
			int banyakAmbil = banyak/2;
			if(a>=b) {
				int cntA = min(a,banyakAmbil+1);
				int cntB = min(b, banyakAmbil);
				a-=(cntA);
				b-=(cntB);
				ans+=(cntA + cntB);
			}else{
				int cntA = min(a,banyakAmbil);
				int cntB = min(b, banyakAmbil+1);
				a-=(cntA);
				b-=(cntB);
				ans+=(cntA + cntB);
			}
		}else{
			int banyakAmbil = banyak/2;
			int cntA = min(a, banyakAmbil);
			int cntB = min(b, banyakAmbil);
			a-=cntA;
			b-=cntB;
			ans+=(cntA + cntB);
		}
		if(a == 0 && b==0){break;}
	}
	printf("%d\n",ans);
	return 0;
};