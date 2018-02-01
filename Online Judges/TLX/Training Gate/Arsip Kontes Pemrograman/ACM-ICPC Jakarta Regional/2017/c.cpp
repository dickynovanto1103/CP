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

const int maxn = 50010;
ll ans[maxn], idx;
string kata;
bool pas;

bool isPossible(ll kiri, ll kanan, int pos) {

	if(kiri==kanan){
		return true;
	}
	if(kata[pos]=='='){return false;}

	if(kata[pos]=='<'){
		ll mid = (kiri+kanan+1)/2LL;
		return isPossible(kiri, mid-1, pos+1);
	}else if(kata[pos]=='>'){
		ll mid = (kiri+kanan-1)/2LL;
		return isPossible(mid+1, kanan, pos+1);
	}
}

void solve(ll kiri, ll kanan, int pos) {
	if(kata[pos]=='='){ans[idx] = kiri; idx++; return;}
	
	if(kata[pos]=='<'){
		if(isPossible(kiri,kanan-1,pos+1)){
			
			ans[idx] = kanan; idx++;
			solve(kiri,kanan-1,pos+1);	
			
			
		}else{
			ll mid = (kiri+kanan+1)/2LL;
			ans[idx] = mid; idx++;
			solve(kiri, mid-1,pos+1);
		}
	}else{
		if(isPossible(kiri+1,kanan,pos+1)){
			
			ans[idx] = kiri; idx++;
			solve(kiri+1,kanan,pos+1);	
			
			
		}else{
			ll mid = (kiri+kanan-1)/2LL;
			ans[idx] = mid; idx++;
			solve(mid+1, kanan,pos+1);
		}
	}
}

int main(){
	ll n;
	int k,i,j;
	
	scanf("%lld %d",&n,&k);
	cin>>kata;

	int pjg = (int)kata.length();

	ll kiri = 1, kanan = n;
	
	if(kata[pjg-1]!='='){
		//printf("masuk sini dong\n");
		if(n<=(ll)pjg){printf("-1\n"); return 0;}
		//iterasi satu"
		for(i=0;i<pjg;i++){
			if(kata[i]=='>'){
				ans[idx] = kiri;
				kiri++;
			}else{
				ans[idx] = kanan;
				kanan--;
			}
			idx++;
		}
	}else{
		//printf("masuk sini\n");
		if(!isPossible(1,n,0)){printf("-1\n"); return 0;}//yang sisa sekarang aja ga cukup buat nebak
		if((ll)pjg>n){printf("-1\n"); return 0;}
		idx = 0;
		solve(1,n,0);
	}
	//print ans
	for(i=0;i<idx;i++){
		if(i){printf(" ");}
		printf("%lld",ans[i]);
	}
	printf("\n");

	return 0;
};