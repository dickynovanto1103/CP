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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

string s;
int suff[2010];

int findInversion(int n) {
	memset(suff, -1, sizeof suff);
	suff[n-1] = s[n-1] == '0';
	int i;
	for(i=n-2;i>=0;i--){
		suff[i] = suff[i+1];
		if(s[i] == '0'){suff[i]++;}
		// printf("suff[%d]: %d\n", i, suff[i]);
	}

	int inv = 0;
	for(i=0;i<n-1;i++){
		if(s[i] == '1') inv += suff[i+1];
	}
	return inv;
}

int dp[2002][2002];
int pref1[2002], suff0[2002];

vi list1, list0;
int k;

int solve(int atm, int kiri) {
	if(atm == k){return 0;}
	if(kiri >= list1.size()){return 0;}

	int kanan = atm - kiri;
	if(kanan >= list0.size()){return 0;}
	// printf("atm: %d kiri: %d kanan: %d\n", atm, kiri, kanan);
	//antara kanan + 1 or kiri + 1
	if(dp[atm][kiri] != -1){return dp[atm][kiri];}
	//jika ganti kiri, hitung banyak 0 di kanannya, harus liat index di kanan sekarang jg
	int idxKiri = list1[kiri];
	int idxKanan = list0[kanan];
	int tambahJikaGantiKiri = max(suff0[idxKiri] - kanan, 0);
	int tambahJikaGantiKanan = max(pref1[idxKanan] - kiri, 0);
	// printf("tambahJikaGantiKiri: %d tambahJikaGantiKanan: %d\n", tambahJikaGantiKiri, tambahJikaGantiKanan);

	return dp[atm][kiri] = max(tambahJikaGantiKiri + solve(atm+1, kiri+1), tambahJikaGantiKanan + solve(atm+1, kiri));
}

int main(){
	int n,i,j;
	while(scanf("%d %d",&n,&k) != EOF) {
		cin>>s;
		list1.clear(); list0.clear();
		memset(dp, -1, sizeof dp);
		int kiri = -1, kanan = -1;
		memset(pref1, 0, sizeof pref1); memset(suff0, 0, sizeof suff0);
		for(i=0;i<n;i++){
			if(s[i] == '1' && kiri == -1){kiri = i;}
			if(s[i] == '0'){kanan = i;}
			if(s[i] == '1'){list1.pb(i);}
			else{list0.pb(i);}

			if(s[i] == '1'){pref1[i]++;}
			if(i){pref1[i] += pref1[i-1];}
		}

		if(kiri == -1 || kanan == -1){puts("0"); continue;}
		for(i=n-1;i>=0;i--){
			if(s[i] == '0'){suff0[i]++;}
			suff0[i] += suff0[i+1];
		}
		int ans = findInversion(n);
		//antara switch dr kanan / kiri
		reverse(list0.begin(), list0.end());
		int maksPengurangan = solve(0, 0);
		// printf("ans: %d maksPengurangan: %d\n", ans, maksPengurangan);

		printf("%d\n", ans - maksPengurangan);
	}
	
	return 0;
};