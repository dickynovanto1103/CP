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

const int maxn = 15;
int n,m, b[maxn];
bool valid = false;

vi fold(vi a, int batas){
	int batasKiri = batas, batasKanan = batas+1;
	int ukuran = a.size();
	int i,j;
	int temp[maxn];
	for(i=0;i<ukuran;i++) {
		temp[i] = a[i];
	}

	vi sementara;
	for(j=0;;j++){
		int kiri = batasKiri - j, kanan = batasKanan + j;
		if(kanan >= ukuran || kiri < 0) {
			vi tempb;
			if(kanan>=ukuran) {
				
				for(i=0;i<kiri;i++){
					tempb.pb(temp[i]);
				}
				for(i=0;i<sementara.size();i++){
					tempb.pb(sementara[i]);
				}
			}else{
				reverse(sementara.begin(), sementara.end());
				for(i=0;i<sementara.size();i++){
					tempb.pb(sementara[i]);
				}
				for(i=kanan;i<ukuran;i++) {
					tempb.pb(temp[i]);
				}

			}
			return tempb;

			break;
		}else{
			sementara.pb(temp[kiri] + temp[kanan]);
		}
	}
	
}

bool check(vi a) {
	for(int i=0;i<m;i++) {
		if(a[i] != b[i]) {
			printf("tidak sama dengan b\n");
			return false;
		}
	}
	printf("sama dengan b\n");
	valid = true;
	return true;
}

void solve(vi a, int idx) {
	if(a.size() < m){
		printf("panjang vector a: %d kurang dari %d\n",(int)a.size(), m);
		return;
	}
	int i;
	printf("vector a dengan idx :%d\n",idx);
	for(i=0;i<a.size();i++){
		if(i){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");

	if(a.size() == m) {
		printf("mau dicek\n");
		check(a); 
		reverse(a.begin(), a.end());
		printf("hasil reverse\n");
		for(i=0;i<a.size();i++){
			if(i){printf(" ");}
			printf("%d",a[i]);
		}
		printf("\n");
		check(a);
		return;
	}

	for(int i=0;i<a.size();i++) {
		printf("i: %d\n",i);
		vi ans1 = fold(a, i);
		printf("hasil fold dengan i: %d\n",i);
		for(int j=0;j<ans1.size();j++){
			if(j){printf(" ");}
			printf("%d",ans1[j]);
		}
		printf("\n");
		if(ans1.size() < m){
			printf("masuk sinikah\n");
			continue;
		}
		solve(ans1, i);
		reverse(ans1.begin(), ans1.begin());
		solve(ans1, i);
	}
	
}

int main(){
	int i,j;
	
	vi a;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		a.pb(bil);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	//proses
	solve(a,0);
	if(valid){printf("S\n");}
	else{printf("N\n");}
	return 0;
};