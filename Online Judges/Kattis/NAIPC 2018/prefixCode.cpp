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

const ll mod = 1e9 + 7;
const int maxn = 1e6 + 6;
ll fac[maxn];
string kata[maxn];

struct trie{
	int next[26];
	int index;

	trie() {
		memset(next,-1,sizeof next);
		index = -1;
	}
};

trie trie_node[maxn];
int idx = 1;

void insertKata(string word, int id) {
	int pjg = word.length();
	int node = 0, next;
	for(int i=0;i<pjg;i++) {
		char kar = word[i];
		next = trie_node[node].next[kar - 'a'];
		if(next==-1){
			next = trie_node[node].next[kar - 'a'] = idx++;
		}
		node = next;
	}
	trie_node[node].index = id;
}

ll modPow(ll a, ll b) {
	if(b==0){return 1;}
	else{
		if(b%2==1){return (a*modPow(a,b-1)) %mod;}
		else{
			ll temp = modPow(a,b/2);
			return (temp*temp)%mod;
		}
	}
}

ll BIT[maxn];

void update(int idx, int val, int n) {
	for(int i=idx;i<=n;i+=(i&-i)) {
		BIT[i] +=val;
	}
}

ll getJumlah(int idx) {
	ll sum = 0;
	for(int i = idx; i>0;i-=(i&-i)) {
		sum+=BIT[i];
	}
	return sum;
}

int main(){
	int n,k,i,j;
	fac[0] = 1;
	for(i=1;i<maxn;i++){
		fac[i] = ((ll)i*fac[i-1])%mod;;
	}

	scanf("%d %d",&n,&k);

	for(i=0;i<n;i++){
		cin>>kata[i];
	}
	sort(kata,kata+n);
	// printf("terurut:\n");
	for(i=0;i<n;i++){
		// cout<<kata[i]<<endl;
		insertKata(kata[i], i+1);
	}
	// printf("\n");

	string query;
	cin>>query;
	int pjg = query.length();
	
	int node = 0;
	// printf("query: "); cout<<query<<endl;
	for(i=1;i<=n;i++){
		update(i,1,n);
	}
	// printf("cek: %lld\n",getJumlah(1));

	ll penyebut = modPow(fac[n-k], mod-2);
	int start = n-1;
	// printf("fac[%d]: %lld\n",start, fac[start]);
	ll ans = 0;
	for(i=0;i<pjg;i++){
		char kar = query[i];
		node = trie_node[node].next[kar - 'a'];
		// temp+=kar;
		if(trie_node[node].index != -1) {
			int indeks = trie_node[node].index;
			ll pengali = getJumlah(indeks-1);
			update(indeks,-1,n);
			ll pembilang = (pengali * fac[start]) %mod;
			// printf("pengali: %lld pembilang: %lld penyebut: %lld\n",pengali, pembilang, penyebut);
			ll jawab = ((pembilang*penyebut) % mod);
			// printf("jawab: %lld\n",jawab);
			ans+=jawab;
			ans%=mod;

			// printf("ans jd: %lld\n",ans);
			// cout<<"temp: "<<temp<<" index: "<<trie_node[node].index<<endl;
			// temp = "";
			node = 0;
			start--;
		}
	}

	ans++;
	ans%=mod;
	printf("%lld\n",ans);
	

	return 0;
};