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

int main(){
	int tc,i,j;
	int n;
	double pMenang;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d:\n",tt);
		scanf("%d %lf",&n,&pMenang);
		//compute orang satu per satu
		for(i=1;i<=n;i++){
			//hitung peluang cuman main 1 kali, 2 kali, 3 kali, ..., n-1 kali
			double ans = 0;
			double peluangLolosSekarang = 1;
			int peserta = n;
			for(j=1;j<n;j++) {
				int banyakMatch = ((peserta*(peserta-1)) / 2);
				int banyakLawanDiAtas = n-i;
				printf("i: %d j: %d banyakMatch: %d banyakLawanDiAtas: %d\n",i,j,banyakMatch, banyakLawanDiAtas);
				double peluangKetemuLawanDiAtas = (double)banyakLawanDiAtas / (double)banyakMatch;
				double peluangKalah = pMenang;
				double peluangGaLolos = (peluangKetemuLawanDiAtas * peluangKalah); //peluang(ketemu lawan di atas) * peluang(kalah)
				ans += ((double)j * peluangLolosSekarang * peluangGaLolos); //jumlah round * peluang(lolos ke rd ini) * peluang(ga lolos ke round selanjutnya)
				peserta--;
				peluangLolosSekarang = 1 - peluangGaLolos;
			}
			if(i == n){
				ans = n-1;
			}
			printf("%.9lf\n",ans);
		}
	}
	
	return 0;
};