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

const int maxn = 1e6 + 6;

int mapper1[maxn], invMapper1[maxn];
int mapper[maxn], invMapper[maxn];

int pref[2][maxn];
int banyak[maxn];
int ans1[maxn], ans0[maxn];

int main(){
	string a,b;
	cin>>a>>b;
	int i,j;
	int n = a.length(), m = b.length();
	int idx0 = 0, idx1 = 0;

	for(i=0;i<m;i++){
		if(b[i] == '1') {
			mapper1[idx1] = i;
			invMapper1[i] = idx1;
			idx1++;
		}else{
			mapper[idx0] = i;
			invMapper[i] = idx0;
			idx0++;
		}
		pref[b[i]-'0'][i] = 1;
		if(i){
			pref[0][i] += pref[0][i-1];
			pref[1][i] += pref[1][i-1];
		}
	}

	for(i=0;i<n;i++){
		banyak[i] = min(i+1, m);
	}
	for(i=n-1;i>=0;i--){
		banyak[i] = min(banyak[i], min(n-i, m));
	}
	for(i=0;i<n/2;i++){
		int cnt = banyak[i];
		int awal = i+1-cnt;
		int akhir = i;
		if(a[i] == '1') {//cari banyak 0 dari 0 sampe cnt-1 di b
			ans[awal] += pref[0][cnt-1];
			ans[akhir+1] -= pref[0][cnt-1];
		}else{
			ans1[]
		}
	}

	return 0;
};