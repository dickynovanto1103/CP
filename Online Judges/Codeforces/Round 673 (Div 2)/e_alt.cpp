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

void cetak(const vi& a){
	for(int i=0;i<a.size();i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

const int maxn = 4000000; //untuk amannya sebenernya nilainya numBit(30) * N = 9000000 ...nilai maxn ini didapatkan dari eksperimen ngesubmit

int t[maxn][2];
int a[300001];
vi indices[maxn];
ll numInv[maxn][2];
int idTrie;

void addNum(int num, int idx) {
	int height = 0;
	for(int i=29;i>=0;i--){
		int digit = (num>>i) & 1;
		if(t[height][digit] == -1){//create new node
			t[height][digit] = ++idTrie;
		}
		height = t[height][digit];
		indices[height].pb(idx);
	}
}

void go(int height, int b = 29) {
	int l = t[height][0], r = t[height][1];

	if(l != -1){go(l, b-1);}
	if(r != -1){go(r, b-1);}
	if(l == -1 || r == -1){return;} //kalo ga ada yg lain, ga ada yang bs dicompare, dan berlaku seterusnya, jd diskip
	//process hitung inverse
	ll ans = 0;
	int index = 0;
	for(int idxKecil : indices[l]) {
		while(index < indices[r].size() && indices[r][index] < idxKecil) { //ada bil lebih besar yg indeksnya lebih kecil drpd idxKecil -> inversion
			index++;
		}
		ans += index;
	}
	numInv[b][0] += ans;
	numInv[b][1] += ((ll)indices[r].size() * indices[l].size()) - ans;
}

int main(){
	int n,i,j;
	
	//solution of using trie
	while(scanf("%d",&n)!=EOF){
		idTrie = 0;
		for(i=0;i<maxn;i++){
			indices[i].clear();
			for(j=0;j<2;j++){
				t[i][j] = -1;
				numInv[i][j] = 0;
			}
		}

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			// cout<<numToBinary(a[i], 7)<<endl;
			addNum(a[i], i);
		}
		go(0);
		ll jawabInv = 0;
		int sor = 0;
		for(i=0;i<=29;i++){
			ll minim = min(numInv[i][0], numInv[i][1]);
			if(numInv[i][1] < numInv[i][0]) {
				sor += (1<<i);
			}
			jawabInv += minim;
		}
		
		printf("%lld %d\n",jawabInv, sor);

		
	}
	
	
	return 0;
};