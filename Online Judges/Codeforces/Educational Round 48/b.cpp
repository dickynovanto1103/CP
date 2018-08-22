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

const int maxn = 1e3 + 3;

int main(){
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	string a,b;
	int i,j;
	cin>>a>>b; //cek apakah b ada di a
	vi ans;
	int cnt[maxn];
	memset(cnt,0,sizeof cnt);
	for(i=0;i<=(n-m);i++){
		string kataAmbil = a.substr(i,m);
		if(kataAmbil == b){
			ans.pb(i+1);
			cnt[i+1]++;
		}
	}
	for(i=1;i<maxn;i++){
		cnt[i] += cnt[i-1];
	}

	while(q--){
		int kiri,kanan;
		scanf("%d %d",&kiri,&kanan);
		int panjang = kanan-kiri+1;
		int idxKiri = kiri;
		int idxKanan = kanan-m+1;
		if(panjang < m){
			printf("0\n");
		}else{
			printf("%d\n",cnt[idxKanan] - cnt[idxKiri-1]);
		}
		
	}



	return 0;
};