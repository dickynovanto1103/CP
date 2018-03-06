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

vector<ll> v;

int main(){
	int q,i;
	scanf("%d",&q);
	int maks = 0;
	bool isAwalSatu = false;
	ll jumlah = 0;
	double avgMin;
	int idx = 0;
	int banyakAmbil = 0;
	double ans = 0.0;
	for(int tt=1;tt<=q;tt++){
		int com;
		ll bil;
		scanf("%d",&com);
		// printf("tt: %d\n",tt);
		// printf("jumlah: %lld ans: %.2lf\n",jumlah,ans);
		if(com==1){
			scanf("%lld",&bil);
			
			
			if(v.size()==0){
				jumlah = bil;
				banyakAmbil = 1;
				idx = 0;
				// printf(" sekarang jumlah: %d banyakAmbil: %d\n",jumlah, banyakAmbil);
			}else{
				//iterasi tambah"in bilangan sebelum sampe maks
				jumlah -= v[v.size()-1];
				jumlah += bil;
				if(v.size()==1){
					jumlah+=v[0];
					banyakAmbil = 2;
				}
				// printf("banyakAmbil: %d\n",banyakAmbil);
				double avg = (double)jumlah/(double)banyakAmbil;
				double kandidat = ((double)bil-avg);
				// printf("kandidat: %.2lf ans: %.2lf avg: %.2lf\n",kandidat,ans,avg);
				if(kandidat > ans){
					// printf("masuk sini\n");
					// printf("ukuran: %d\n",(int)v.size());
					ans = ((double)bil-avg);
					// printf("ans jd: %.2lf\n",ans);
					for(i=idx+1;i<v.size();i++){
						// printf("i: %d\n",i);
						ll temp = jumlah+v[i];
						if(((double)bil - (double)temp/(double)(banyakAmbil+1)) < ans){
							break;
						}else{
							jumlah+=v[i];
							
							ans = (double)bil - (double)temp/(double)(banyakAmbil+1);
							banyakAmbil++;
							// printf("bil: %lld avg: %.2lf ans improve jadi: %.2lf\n",bil,(double)temp/(double)(banyakAmbil+1),ans);
						}
					}
					idx = i-1;
				}
			}
			// printf("jumlah: %lld banyakAmbil: %d\n",jumlah, banyakAmbil);
			v.pb(bil);
		}else{
			printf("%.10lf\n",ans);
		}
	}
	return 0;
};