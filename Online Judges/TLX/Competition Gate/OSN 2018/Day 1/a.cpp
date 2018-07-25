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

const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;

ll fac[maxn];
vector<vi> AdjListKiri, AdjListKanan;
int h[maxn],a[maxn], b[maxn];
int cntMasukSini = 0;

bool isReachable(int awal, int akhir){
	int idxJembatan = a[awal-1];
	int jembatan = h[idxJembatan-1];
	if((awal < jembatan && akhir < jembatan) || (awal > jembatan && akhir > jembatan)){
		return false;
	}
	for(int i=0;i<AdjListKanan[idxJembatan].size();i++){
		int tetangga = AdjListKanan[idxJembatan][i];
		if(akhir == tetangga){return true;}
	}
	return false;
}

int main(){
	string dummy;
	cin>>dummy;

	fac[0] = 1;
	for(ll i=1;i<maxn;i++){
		fac[i] = i*fac[i-1];
		fac[i]%=mod;
	}

	int n,k,i,j;
	scanf("%d %d",&n,&k);
	AdjListKiri.assign(n+1,vi()); AdjListKanan.assign(n+1,vi());
	for(i=0;i<k;i++){scanf("%d",&h[i]);}
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		AdjListKiri[a[i]].pb(i+1);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
		AdjListKanan[b[i]].pb(i+1);
	}

	if(k==n){
		for(i=0;i<n;i++){
			int idxJembatan = a[i];
			int tinggi = h[idxJembatan-1];
			int kiri = AdjListKiri[idxJembatan][0], kanan = AdjListKanan[idxJembatan][0];
			if((kiri < tinggi && kanan < tinggi) || (kiri > tinggi && kanan > tinggi)){
				printf("0\n");
				return 0;
			}
		}
		printf("1\n"); return 0;
	}

	if(k==1){
		ll ans;
		if(n%2==0){
			if(h[0] == (n/2) || h[0] == (n/2 + 1)){
				ans = fac[n/2]*fac[n/2];
				ans%=mod;
			}else{
				ans = 0;
			}
		}else{
			if(h[0] == (n/2 + 1)){
				ans = fac[n/2]*fac[n/2 + 1];
				ans%=mod;
				ans*=2LL;  ans%=mod;
				ll pengurang = fac[n/2] * fac[n/2];
				pengurang%=mod;
				ans-=pengurang;
				if(ans<0){ans+=mod;}
			}else{
				ans = 0;
			}
		}
		printf("%lld\n",ans);
		return 0;
	}

	if(n<=10){
		int listIdx[11], listIdxTemp[11];
		for(i=0;i<n;i++){
			listIdx[i] = i+1;
			listIdxTemp[i] = i+1;
		}
		int cnt = 0;
		ll ans = 0;
		int temp[11];
		do{
			
			bool isValid = true;
			for(i=0;i<n;i++){
				temp[i] = listIdx[i];
				
				if(!isReachable(listIdxTemp[i],temp[i])){
					isValid = false; break;
				}
				
			}

			// printf("\n");
			if(isValid){ans++;}
		}while(next_permutation(listIdx, listIdx+n));
		printf("%lld\n",ans);
		return 0;
	}

	ll ans = 1;
	for(i=0;i<k;i++){
		
		int tinggi = h[i];
		int idxKiriBawah = lower_bound(AdjListKiri[i+1].begin(),AdjListKiri[i+1].end(), tinggi) - AdjListKiri[i+1].begin();
		// printf("idxKiriBawah : %d\n",idxKiriBawah);
		
		int banyakKiriBawah, banyakKananBawah,banyakKiriAtas, banyakKananAtas;
		int flag = 0;
		int ukuranKiri = AdjListKiri[i+1].size();
		if(AdjListKiri[i+1][idxKiriBawah] == tinggi){
			banyakKiriBawah = idxKiriBawah+1;
			ukuranKiri = AdjListKiri[i+1].size();
			banyakKiriAtas = ukuranKiri - banyakKiriBawah + 1;
			flag |= 1;
		}else{
			banyakKiriBawah = idxKiriBawah;
			banyakKiriAtas = ukuranKiri - banyakKiriBawah;
		}

		int idxKananBawah = lower_bound(AdjListKanan[i+1].begin(), AdjListKanan[i+1].end(), tinggi) - AdjListKanan[i+1].begin();
		int ukuranKanan = AdjListKanan[i+1].size();
		if(AdjListKanan[i+1][idxKananBawah] == tinggi){
			flag|=2;
			banyakKananBawah = idxKananBawah +1;
			ukuranKanan = AdjListKanan[i+1].size();
			banyakKananAtas = ukuranKanan - banyakKananBawah + 1;
		}else{
			banyakKananBawah = idxKananBawah;
			banyakKananAtas = ukuranKanan - banyakKananBawah;
		}
		// printf("banyakKiriAtas: %d banyakKiriBawah: %d banyakKananAtas: %d banyakKananBawah: %d\n",banyakKiriAtas, banyakKiriBawah, banyakKananAtas, banyakKananBawah);
		ll jawab = 0;
		if(banyakKiriAtas == banyakKananBawah || banyakKiriBawah == banyakKananAtas) {
			if(flag==1 || flag==2){
				if(banyakKiriAtas == banyakKananBawah){
					jawab+=(fac[banyakKiriAtas]*fac[banyakKiriBawah]);
					jawab%=mod;
				}else{
					jawab+=(fac[banyakKiriBawah]*fac[banyakKiriAtas]);
					jawab%=mod;
				}
			}else if(flag==3){
				int ukuran = ukuranKanan;
				if(ukuran%2==0){
					jawab+=(fac[ukuran/2]*fac[ukuran/2]);
					jawab%=mod;
				}else{
					jawab+=(fac[ukuran/2]*fac[ukuran/2 + 1]);
					jawab%=mod;
					jawab*=2LL; jawab%=mod;
					ll pengurang = fac[ukuran/2]*fac[ukuran/2];
					pengurang%=mod;
					jawab-=pengurang;
					if(jawab<0){jawab+=mod;}
				}

			}else{ //flag 0
				jawab+=(fac[banyakKiriAtas] * fac[banyakKiriBawah]);
				jawab%=mod;
			}
		}else{
			if(flag==3){
				int minim1 = min(banyakKiriAtas, banyakKananBawah), minim2 = min(banyakKiriBawah, banyakKananAtas);
				int minim = min(minim1,minim2);
				int maks1 = max(banyakKiriAtas, banyakKananBawah), maks2 = max(banyakKiriBawah, banyakKananAtas);
				int maks = max(maks1,maks2);
				if(minim == 1 && maks == 2){
					jawab = 1;
					continue;
				}else{
					printf("0\n");
					return 0;
				}
			}
			printf("0\n");
			return 0;
		}

		ans*=jawab;
		ans%=mod;
	}

	printf("%lld\n",ans);
	return 0;
};