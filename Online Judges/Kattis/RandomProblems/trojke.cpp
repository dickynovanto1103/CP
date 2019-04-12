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

const int maxn = 1e2 + 2;

int main(){
	int n,i,j,k;
	scanf("%d",&n);
	string kata[maxn];
	ii koor[26];
	for(i=0;i<26;i++){koor[i] = ii(-inf,-inf);}
	int maks = 0;
	for(i=0;i<n;i++){
		cin>>kata[i];
		for(j=0;j<kata[i].length();j++){
			char kar = kata[i][j];
			if(kar != '.'){
				koor[kar - 'A'] = ii(i,j);
				maks = max(maks, kar - 'A');
			}
		}
	}
	map<ii, int> mapper;
	int cntGradien[10010];
	int maks1 = 0;
	int cnt = 0;
	int ans = 0;
	for(i=0;i<=maks;i++){
		if(koor[i] == ii(-inf,-inf)){continue;}
		for(j=i+1;j<=maks;j++){
			if(koor[j] == ii(-inf,-inf)){continue;}

			int penyebut = koor[j].first - koor[i].first;
			int pembilang = koor[j].second - koor[i].second;
			if(penyebut == 0){
				pembilang = 1;
				
			}
			if(penyebut != 0){
				int gcd = __gcd(penyebut, pembilang);
				penyebut /= gcd; pembilang /= gcd;
				
			}
			
			for(k=j+1;k<=maks;k++){
				if(koor[k] == ii(-inf,-inf)){continue;}
				// printf("%d %d %d %d %d %d\n",koor[i].first,koor[i].second,koor[j].first,koor[j].second,koor[k].first,koor[k].second);
				int penyebut1 = koor[k].first - koor[i].first;
				int pembilang1 = koor[k].second - koor[i].second;
				if(penyebut1 == 0){
					pembilang1 = 1;
				}
				if(penyebut1!=0){
					int gcd = __gcd(penyebut1, pembilang1);
					penyebut1 /= gcd; pembilang1 /= gcd;
				}

				// printf("penyebut: %d penyebut1; %d pembilang: %d pembilang1: %d\n",penyebut, penyebut1, pembilang, pembilang1);
				if(penyebut == penyebut1 && pembilang == pembilang1){ans++; continue;}
				penyebut*=-1; pembilang*=-1;
				// printf("skrg penyebut: %d penyebut1; %d pembilang: %d pembilang1: %d\n",penyebut, penyebut1, pembilang, pembilang1);
				if(penyebut == penyebut1 && pembilang == pembilang1){ans++;}
			}
			// printf("cntGradien[%d][%d] jd: %d\n",pembilang, penyebut, cntGradien[pembilang][penyebut]);
		}
		

	}
	printf("%d\n",ans);

	return 0;
};