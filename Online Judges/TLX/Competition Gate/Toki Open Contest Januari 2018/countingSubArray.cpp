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
const int maxn = 1e5 + 5;
bool isVisited[maxn];

int main(){
	int n,i,j,k;
	ll ans = 0;
	int listIdx[maxn];
	memset(isVisited,false,sizeof isVisited);
	scanf("%d %d",&n,&k);
	for(i=0;i<k;i++){scanf("%d",&listIdx[i]);}
	sort(listIdx,listIdx+k);
	for(i=0;i<k;i++){
		if(isVisited[listIdx[i]]){continue;}
		if(i==0){
			ll keKiri = listIdx[i];
			ll keKanan = n-listIdx[i]+1;
			ans+=(keKanan*keKiri);
			ans%=mod;
			isVisited[listIdx[i]] = true;
		}else{
			int idxSebelum = listIdx[i-1];
			int idxSekarang = listIdx[i];
			ll keKanan = n-idxSekarang+1;
			ll keKiri = idxSekarang-idxSebelum;
			ans+=(keKiri*keKanan);
			ans%=mod;
			isVisited[listIdx[i]] = true;
		}
	}
	printf("%lld\n",ans);
	return 0;
};