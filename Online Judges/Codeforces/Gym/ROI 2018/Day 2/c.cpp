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

const int maxn = 3e3 + 3;

int a[maxn];
int pos[maxn];

void sim(int awal, int akhir) {
	vi depan, belakang;
	int i,j;
	for(i=awal + 1;i<=akhir;i+=2){
		depan.pb(a[i]);
	}
	for(i=awal;i<=akhir;i+=2){
		belakang.pb(a[i]);
	}
	int idx = awal;
	int ukuranDepan = depan.size(), ukuranBelakang = belakang.size();
	for(i=0;i<ukuranDepan;i++){
		a[idx] = depan[i];
		pos[a[idx]] = idx;
		idx++;
	}
	for(i=0;i<ukuranBelakang;i++){
		a[idx] = belakang[i];
		pos[a[idx]] = idx;
		idx++;
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	
	
	for(i=1;i<=n;i++){scanf("%d",&a[i]); pos[a[i]] = i;}
	vii listPas;
	
	for(i=1;i<=n;i++){
		int posAwal = pos[i];
		//gmn cara bawa angka i ke posisi seharusnya..di idx i
		int jarak = pos[i] - i;
		// printf("i: %d jarak: %d pos: %d\n",i,jarak, posAwal);
		while(jarak) {
			if(jarak&1){
				listPas.pb(ii(i, pos[i]));
				int idxRelatif = pos[i] - i;
				int jadi = idxRelatif / 2;
				int selisih = idxRelatif - jadi;
				sim(i, pos[i]);
				
			}else{
				listPas.pb(ii(i+1, pos[i]));
				int idxRelatif = pos[i] - (i+1);
				int jadi = idxRelatif / 2;
				int selisih = idxRelatif - jadi;
				sim(i+1, pos[i]);
			}
			jarak = pos[i] - i;

		}
	}
	int ukuran = listPas.size();
	printf("%d\n",ukuran);
	for(i=0;i<ukuran;i++){
		printf("%d %d\n",listPas[i].first,listPas[i].second);
	}
	return 0;
};