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

int d[11];
char tipe[11];

int ans;
vector<int> listAns;

void hitung(vector<int> v, int y) {
	int n = v.size();

	do {
		bool sudahYakin = false;
		char tipeSebelum = 'a';
		int tot = 0;
		for(int i=0;i<n;i++){
			int elem = v[i];
			int nilai = d[elem];

			if(tipeSebelum == 'L') {
				nilai /= 2;
			} else if (tipeSebelum == 'P'){
				nilai *= 2;
			}

			if(sudahYakin) {
				nilai += y;
			}

			tot += nilai;

			if (tipe[elem] == 'Y'){
				sudahYakin = true;
			}
			tipeSebelum = tipe[elem];
		}
		listAns.pb(tot);
	}while(next_permutation(v.begin(), v.end()));
}

void generate(int idx, int n, int r, int y, vector<int> v) {
	if(idx == n){
		hitung(v, y);
		return;
	}

	int selisih = n - idx;
	if(selisih == r) {
		v.pb(idx);
		generate(idx+1, n, r-1, y, v);
	} else if (r == 0){
		generate(idx+1, n, r, y, v);
	} else {
		//ada 2 kemungkinan
		v.pb(idx);
		generate(idx+1, n, r-1, y, v);
		v.pop_back();
		generate(idx+1, n, r, y, v);
	}
}

int compute(int n, int r, int y) {
	//generate semua kombinasi, terus permutasiin
	//tiap permutasi...hitung
	ans = 0;
	vector<int> v;
	generate(0, n, r, y, v);
	return ans;
}

int main(){
	string dum;
	cin>>dum>>dum;

	int n,r,y,m;
	scanf("%d %d %d %d",&n,&r,&y,&m);
	for(int i=0;i<n;i++){
		cin>>d[i]>>tipe[i];
	}
	compute(n, r, y);
	sort(listAns.begin(), listAns.end());
	int banyakAns = listAns.size();
	for(int i=0;i<m;i++){
		int minVal;
		scanf("%d",&minVal);
		int idx = upper_bound(listAns.begin(), listAns.end(), minVal) - listAns.begin();

		printf("%d\n",banyakAns - idx);
	}
	return 0;
};