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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

int pas[2001];
string s;

void process(int n) {
	int i,j;
	vii v;
	vii ans;
	for(i=0;i<n;i++){
		if(s[i] == '('){
			v.pb(ii(i, -1));
		}else if(s[i] == ')'){
			ii belakang = v.back(); v.pop_back();
			pas[belakang.first] = i;
		}
	}
}

bool isAngka(char c) {
	return c >= '2' && c <= '9';
}

void normalize(ll& bil){
	bil %= inf;
	if(bil < 0){bil += inf;}
}

ii getCoord(int pengulangan, int idxAwal, int idxAkhir, ll koorAwal, ll koorAkhir) {
	int i,j;
	ii now = ii(koorAwal, koorAkhir);
	ii awalBanget = now;
	for(i=idxAwal;i<=idxAkhir;i++){
		if(isAngka(s[i])){
			int pasangan = pas[i+1];
			now = getCoord(s[i] - '0', i+1, pasangan, now.first, now.second);
			i = pasangan; //skip ke pasangan
		} else if(s[i] == ')' || s[i] == '('){continue;}
		else if(s[i] == 'S'){
			now.first++;
			// normalize(now.first);
		}else if(s[i] == 'E'){
			now.second++;
			// normalize(now.second);
		}else if(s[i] == 'N'){
			now.first--;
			// normalize(now.first);
		}else if(s[i] == 'W'){
			now.second--;
			// normalize(now.second);
		}
	}
	//urus pengulangan
	ll selisihX = now.first - awalBanget.first;
	ll selisihY = now.second - awalBanget.second;
	selisihY *= pengulangan;
	selisihX *= pengulangan;
	normalize(selisihX); normalize(selisihY);
	// printf("pengulangan: %d awal: %d akhir: %d\n",pengulangan, idxAwal, idxAkhir);
	// printf("awalBanget: %lld %lld\n",awalBanget.first, awalBanget.second);
	awalBanget.first += selisihX;
	awalBanget.second += selisihY;
	// printf("akhir coord: %lld %lld\n",awalBanget.first, awalBanget.second);
	normalize(awalBanget.first);
	normalize(awalBanget.second);
	return awalBanget;
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		
		cin>>s;
		int n = s.length();
		for(i=0;i<n;i++){pas[i] = 0;}
		process(n);
		// for(i=0;i<n;i++){
		// 	if(pas[i] != 0){
		// 		printf("pas[%d]: %d\n",i, pas[i]);
		// 	}
		// }
		ii ans;
		ans = getCoord(1, 0, n-1, 0, 0);
		
		swap(ans.first, ans.second);

		printf("%lld %lld\n",ans.first + 1, ans.second + 1);
	}
	return 0;
};