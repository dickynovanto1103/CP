#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000000LL
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

const int maxn =  1e5 + 5;

ll a[maxn];

vector<vi> AdjList;

int main(){
	int n,i,j;
	scanf("%d",&n);
	string kata;
	cin>>kata;
	AdjList.assign(30, vi());
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	for(i=0;i<n;i++){
		char kar = kata[i];
		AdjList[kar-'a'].pb(i);
	}
	string temp = "hard";
	for(i=0;i<temp.length();i++){
		if(AdjList[temp[i] - 'a'].size() == 0){printf("0\n"); return 0;}
	}
	int awal[26];
	int akhir[26];
	int awalH = AdjList['h' - 'a'][0];
	awal['h' - 'a'] = 0;
	int cur = awalH;
	for(i=1;i<temp.length();i++){
		char kar = temp[i];
		int idx = lower_bound(AdjList[kar-'a'].begin(), AdjList[kar-'a'].end(), cur) - AdjList[kar-'a'].begin();
		// printf("kar: %c idx: %d cur: %d\n",kar,idx,cur);
		if(idx == AdjList[kar-'a'].size()){
			printf("0\n"); return 0;
		}
		else{awal[kar - 'a'] = idx; cur = AdjList[kar - 'a'][idx];}
	}
	//valid skrg harus ngehapus
	akhir['d' - 'a'] = AdjList['d' - 'a'].size() - 1;
	// printf("size: %d\n",AdjList['d' - 'a'].size());
	cur = AdjList['d' - 'a'].back();
	for(i=temp.length()-2;i>=0;i--){
		char kar = temp[i];
		int idx = lower_bound(AdjList[kar - 'a'].begin(), AdjList[kar-'a'].end(), cur) - AdjList[kar-'a'].begin();

		idx--;
		akhir[kar - 'a'] = idx; cur = AdjList[kar-'a'][idx];
	}
	ll ans = inf;
	for(i=0;i<temp.length();i++){
		int idxAwal = awal[temp[i] - 'a'];
		int idxAkhir = akhir[temp[i] - 'a'];
		ll sum = 0;
		for(j=idxAwal;j<=idxAkhir;j++){
			int idx = AdjList[temp[i] - 'a'][j];
			sum += a[idx];
		}
		ans = min(ans, sum);

		// printf("awal[%c]: %d akhir: %d\n",temp[i], awal[temp[i] - 'a'], akhir[temp[i] - 'a']);
	}
	printf("%lld\n",ans);
	return 0;
};