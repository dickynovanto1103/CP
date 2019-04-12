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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int pembilang, penyebut;
	while(scanf("%d/%d",&pembilang, &penyebut) !=EOF){
		int cnt = 0;
		for(int i=penyebut + 1;i<=penyebut*2;i++){
			if(i<penyebut){continue;}
			int penyebutBaru = penyebut*i;
			int pembilangBaru = i - penyebut;
			int gcd = __gcd(pembilangBaru, penyebutBaru);
			penyebutBaru/=gcd; pembilangBaru /= gcd;
			if(pembilangBaru == 1){
				// printf("i: %d\n",i);
				cnt++;
			}
		}
		printf("%d,", cnt);
		// printf("%s\n", );
	}
	printf("\n");

	return 0;
};