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

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	int a[maxn], counter[maxn];
	map<int,int> mapper;
	set<int> s;
	set<int>::iterator it;
	scanf("%d",&n);
	int minim = inf;
	ll sum = 0;
	int idx = 0;
	memset(counter,0,sizeof counter);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum+=(ll)a[i];
		
		s.insert(a[i]);
		minim = min(minim,a[i]);
	}
	sort(a,a+n);
	for(i=0;i<n;i++){
		if(mapper.find(a[i])==mapper.end()) {
			mapper[a[i]] = idx;
			counter[idx]++;
			idx++;
		}else{
			int indeks = mapper[a[i]];
			counter[indeks]++;
		}
	}

	vi listBilUnik;
	for(it=s.begin();it!=s.end();it++){
		int bil = *it;
		listBilUnik.pb(bil);
	}
	ll prefSum[maxn];
	for(i=listBilUnik.size()-1;i>=0;i--){
		int bil = listBilUnik[i];
		
		if(i==(listBilUnik.size()-1)){prefSum[i] = counter[i];}
		else{prefSum[i] = prefSum[i+1] + counter[i];}
		
	}
	ll minimSum = (ll)inf*(ll)inf;
	minimSum = sum;
	ll penambahan = 0;
	ll totalBerkurang = 0;
	// printf("awal sum : %lld\n",sum);
	for(i=0;i<listBilUnik.size();i++){
		int efek = prefSum[i];
		ll bil = listBilUnik[i]-totalBerkurang;
		sum-=(efek*(bil));
		// printf("sum setelah dikurang: %lld\n",sum);
		sum+=(penambahan*(bil));
		penambahan+=counter[i];
		totalBerkurang+=bil;
		// printf("efek: %d sum jd: %lld penambahan jd: %lld\n",efek,sum,penambahan);
		if(minimSum > sum){
			minimSum = sum;
		}else{
			break;
		}
	}
	printf("%lld\n",minimSum);
	return 0;
};