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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 5e4 + 4;

map<ii, int> kanan, kiri, atas, bawah;

void adjustSurrounding(int r, int c, char kar) {
	if(bawah.find(ii(r,c)) == bawah.end()) {
		bawah[ii(r,c)] = 1;
	}

	if(atas.find(ii(r,c)) == atas.end()) {
		atas[ii(r,c)] = 1;
	}

	if(kanan.find(ii(r,c)) == kanan.end()) {
		kanan[ii(r,c)] = 1;
	}

	if(kiri.find(ii(r,c)) == kiri.end()) {
		kiri[ii(r,c)] = 1;
	}

	int dAtas = atas[ii(r,c)];
	ii baru = ii(r - dAtas, c);
	bawah[baru] = dAtas + bawah[ii(r,c)];
	
	int dBawah = bawah[ii(r,c)];
	baru = ii(r + dBawah, c);
	atas[baru] = dBawah + atas[ii(r,c)];
	
	int dKanan = kanan[ii(r,c)];
	baru = ii(r, c+dKanan);
	kiri[baru] = dKanan + kiri[ii(r,c)];

	int dKiri = kiri[ii(r,c)];
	baru = ii(r, c - dKiri);
	kanan[baru] = dKiri + kanan[ii(r,c)];
}

ii move(int r, int c, char kar) {
	if(kar == 'N'){
		//cari atasnya r,c
		if(atas.find(ii(r,c)) == atas.end()) {//berarti atasnya bersih
			return ii(r-1, c);
		}else{
			int bil = atas[ii(r,c)];
			return ii(r-bil, c);
		}
	}else if(kar == 'W') {
		if(kiri.find(ii(r,c)) == kiri.end()) {
			return ii(r, c-1);
		}else{
			int bil = kiri[ii(r,c)];
			return ii(r, c-bil);
		}
	}else if(kar == 'E') {
		if(kanan.find(ii(r,c)) == kanan.end()) {
			return ii(r, c+1);
		}else{
			int bil = kanan[ii(r,c)];
			return ii(r, c+bil);
		}
	}else{
		if(bawah.find(ii(r,c)) == bawah.end()) {//berarti atasnya bersih
			return ii(r+1, c);
		}else{
			int bil = bawah[ii(r,c)];
			return ii(r+bil, c);
		}
	}
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		int n,r,c,sr,sc;
		scanf("%d %d %d %d %d",&n,&r,&c,&sr,&sc);
		string s;
		cin>>s;
		kanan[ii(sr,sc-1)] = 2; kiri[ii(sr,sc+1)] = 2;
		atas[ii(sr+1,sc)] = 2; bawah[ii(sr-1,sc)] = 2;

		kanan[ii(sr,sc)] = 1; kiri[ii(sr,sc)] = 1;
		atas[ii(sr,sc)] = 1; bawah[ii(sr,sc)] = 1;
		// adjustSurrounding(sr, sc,'.');
		ii last = ii(sr,sc);
		for(i=0;i<n;i++){
			char kar = s[i];
			
			ii koor = move(last.first, last.second, kar);
			// printf("kar: %c koor: %d %d\n",kar, koor.first, koor.second);
			adjustSurrounding(koor.first, koor.second, kar);
			last = koor;
		}
		kanan.clear(); kiri.clear(); atas.clear(); bawah.clear();
		printf("%d %d\n",last.first, last.second);
	}
	return 0;
};