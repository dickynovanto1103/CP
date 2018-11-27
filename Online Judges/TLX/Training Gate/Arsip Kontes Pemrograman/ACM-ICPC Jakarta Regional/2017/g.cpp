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
typedef pair<double,double> dd;
typedef pair<dd,dd> iiii;
typedef vector<ii> vii;

class UnionFind{
private: 
	vi rank,p,setSize;
	int numset,i;
public:
	UnionFind(int n){
		numset=n; setSize.assign(n,1); rank.assign(n,0); p.assign(n,0);
		for(i=0;i<n;i++){p[i]=i;}
	}

	int findSet(int i){return (p[i]==i) ? i : (p[i]=findSet(p[i]));}
	bool isSameSet(int i, int j){return findSet(i)==findSet(j);}
	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			numset--;
			int x=findSet(i), y=findSet(j);
			if(rank[x] > rank[y]){p[y]=x; setSize[x]+=setSize[y];}
			else{
				p[x]=y;
				setSize[y]+=setSize[x];
				if(rank[x]==rank[y]){rank[y]++;}
			}
		}
	}
	int numDisjointSet(){return numset;}
	int sizeSetOf(int i){return setSize[findSet(i)];}
};

const int maxn = 1010;

ll hitungJarak(ii koor1, ii koor2){
	ll selisihX = abs(koor1.first - koor2.first);
	ll selisihY = abs(koor1.second - koor2.second);

	return selisihX*selisihX + selisihY*selisihY;
}

bool isInside(ii koor1, ii koor2, ll r1, ll r2){
	double jarak = hypot(koor1.first - koor2.first, koor1.second - koor2.second);
	return (double)r1 >= jarak + (double)r2;
}

bool isSalingLepas(ii koor1, ii koor2, ll r1, ll r2){
	ll selisihX = koor1.first-koor2.first;
	ll selisihY = koor1.second-koor2.second;
	ll jarakKuadrat = selisihX*selisihX + selisihY*selisihY;
	return r1*r1 + 2LL*r1*r2 + r2*r2 >= jarakKuadrat;
}

iiii hasilPotong(ii koor1, ii koor2, ll r1, ll r2){
	ll a = koor1.first, b = koor1.second, c = r1;
	ll d = koor2.first, e = koor2.second, f = r2;
	ll v = c*c - f*f - a*a + d*d - b*b + e*e;
	ll w = -2LL*b + 2LL*e;
	ll z = -2LL*a + 2LL*d;
	ll var1 = w*w + z*z, var2 = -2LL*v*w + 2LL*a*w*z - 2*b*z*z, var3 = v*v - 2LL*a*z*v + a*a*z*z+b*b*z*z-c*c*z*z;
	double y1 = (double)-var2 + sqrt(var2*var2 - 4LL*var1*var3) / 2.0*var1;
	double y2 = (double)-var2 - sqrt(var2*var2 - 4LL*var1*var3) / 2.0*var1;
	
}

int main(){
	ll x1,y1,x2,y2,n;
	int i,j;
	scanf("%lld %lld %lld %lld %lld",&x1,&y1,&x2,&y2,&n);
	ii kiriBawah = ii(x1,y1);
	ii kiriAtas = ii(x1,y2);
	ii kananAtas = ii(x2,y2);
	ii kananBawah = ii(x2,y1);
	listPinggir.pb(kiriBawah); listPinggir.pb(kiriAtas); listPinggir.pb(kananBawah); listPinggir.pb(kananAtas);
	ll x[maxn], y[maxn], r[maxn];
	if(n == 0){printf("YES\n"); return 0;}
	vi listKiri, listKanan, listAtas, listBawah;
	for(i=0;i<n;i++){
		scanf("%lld %lld %lld",&x[i],&y[i],&r[i]);
		if(abs(x[i] - x1) < r[i]){
			if(y[i] < y1){
				ll jarak = hitungJarak(ii(x[i], y[i]), kiriBawah);
				if(jarak < r[i]*r[i]){
					listKiri.pb(i);
					printf("tambah ke listKiri: %d\n",i);
				}
			}else if(y[i] > y2){
				ll jarak = hitungJarak(ii(x[i], y[i]), kiriAtas);
				if(jarak < r[i]*r[i]){
					listKiri.pb(i);
					printf("tambah ke listKiri: %d\n",i);
				}
			}else{
				listKiri.pb(i);
				printf("tambah ke listKiri: %d\n",i);
			}
		}
		if(abs(y[i] - y1) < r[i]){
			if(x[i] < x1){
				ll jarak = hitungJarak(ii(x[i], y[i]), kiriBawah);
				if(jarak < r[i]*r[i]){
					listBawah.pb(i);
					printf("tambah ke listBawah: %d\n",i);
				}
			}else if(x[i] > x2){
				ll jarak = hitungJarak(ii(x[i], y[i]), kananBawah);
				if(jarak < r[i]*r[i]){
					listBawah.pb(i);
					printf("tambah ke listBawah: %d\n",i);
				}
			}else{
				listBawah.pb(i);
				printf("tambah ke listBawah: %d\n",i);
			}
			
			
		}
		if(abs(x[i] - x2) < r[i]){
			if(y[i] < y1){
				ll jarak = hitungJarak(ii(x[i], y[i]), kananBawah);
				if(jarak < r[i]*r[i]){
					listKanan.pb(i);
					printf("tambah ke listKanan: %d\n",i);
				}
			}else if(y[i] > y2){
				ll jarak = hitungJarak(ii(x[i], y[i]), kananAtas);
				if(jarak < r[i]*r[i]){
					listKanan.pb(i);
					printf("tambah ke listKanan: %d\n",i);
				}
			}else{
				listKanan.pb(i);
				printf("tambah ke listKanan: %d\n",i);
			}
			
			
		}
		if(abs(y[i] - y2) < r[i]){
			if(x[i] < x1){
				ll jarak = hitungJarak(ii(x[i], y[i]), kiriAtas);
				if(jarak < r[i]*r[i]){
					listAtas.pb(i);
					printf("tambah ke listAtas: %d\n",i);
				}
			}else if(x[i] > x2){
				ll jarak = hitungJarak(ii(x[i], y[i]), kananAtas);
				if(jarak < r[i]*r[i]){
					listAtas.pb(i);
					printf("tambah ke listAtas: %d\n",i);
				}
			}else{
				listAtas.pb(i);
				printf("tambah ke listAtas: %d\n",i);
			}
			
		}
	}
	UnionFind UF(n);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			
			ll selisihX = abs(x[i] - x[j]);
			ll selisihY = abs(y[i] - y[j]);
			ll r1 = r[i], r2 = r[j];
			ll totalJarak = selisihX*selisihX + selisihY*selisihY;
			ll totalR = (r1 + r2)*(r1 + r2);
			if(totalR > totalJarak){

				UF.unionSet(i,j);
				printf("digabungkan indeks %d ke %d\n",i,j);
			}
		}
	}
	int ukuranKiri = listKiri.size(), ukuranKanan = listKanan.size(), ukuranBawah = listBawah.size(), ukuranAtas = listAtas.size();
	for(i=0;i<ukuranKiri;i++){
		for(j=0;j<ukuranBawah;j++){
			int idx1 = listKiri[i], idx2 = listBawah[j];
			if(UF.isSameSet(idx1, idx2)){printf("NO\n"); return 0;}
		}
	}
	for(i=0;i<ukuranAtas;i++){
		for(j=0;j<ukuranKanan;j++){
			int idx1 = listAtas[i], idx2 = listKanan[j];
			if(UF.isSameSet(idx1, idx2)){printf("NO\n"); return 0;}
		}
	}
	for(i=0;i<ukuranKiri;i++){
		for(j=0;j<ukuranKanan;j++){
			int idx1 = listKiri[i], idx2 = listKanan[j];
			if(UF.isSameSet(idx1, idx2)){printf("NO\n"); return 0;}
		}
	}
	for(i=0;i<ukuranAtas;i++){
		for(j=0;j<ukuranBawah;j++){
			int idx1 = listAtas[i], idx2 = listBawah[j];
			if(UF.isSameSet(idx1, idx2)){printf("NO\n"); return 0;}
		}
	}
	printf("YES\n");
	return 0;
};