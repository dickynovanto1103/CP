#include <bits/stdc++.h>

using namespace std;
#define inf 10000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,int> ii;
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int maxn = 1e5 + 5;

viii listBil;

bool cmp(iii a, iii b){
	if(a.first.first == b.first.first){
		return a.second < b.second;
	}
	return a.first.first > b.first.first;
}

int main(){
	int n;
	ll h;
	ll a[maxn],b[maxn];
	int i,j;
	ll ans = inf;
	scanf("%d %lld",&n,&h);
	for(i=0;i<n;i++){
		scanf("%lld %lld",&a[i],&b[i]);
		iii pas1 = make_pair(ii(a[i],i),1);
		iii pas2 = make_pair(ii(b[i],i),2);
		listBil.pb(pas1); listBil.pb(pas2);
	}

	sort(listBil.begin(), listBil.end(), cmp);
	ll health = h;
	vector<bool> isVisited;
	isVisited.assign(maxn,false);
	ll banyakTebasan = 0;
	//metode kurangin semua dengan id2 sampe ketemu id 1, lalu bagi habis
	for(i=0;i<listBil.size();i++){
		iii bil = listBil[i];
		ll damage = bil.first.first;
		int idx = bil.first.second;
		int id = bil.second;

		if(id==2){
			health-=damage;
			banyakTebasan++;
			isVisited[idx] = true;
			if(health<=0){break;}
		}else{
			if(isVisited[idx]){continue;}
			if(health%damage==0){
				banyakTebasan+=(health/damage);
			}else{
				banyakTebasan+=((health/damage)+1);
			}
		}
		
	}
	if(health>0){banyakTebasan = inf; ans = min(ans,banyakTebasan);}
	else{ans = min(ans,banyakTebasan);}
	//printf("ans: %lld\n",ans);
	health = h;
	//metode 2..cek idx1 tertinggi, 
	for(i=0;i<maxn;i++){isVisited[i] = false;}
	int indeks;
	for(i=0;i<listBil.size();i++){
		iii bil = listBil[i];
		ll damage = bil.first.first;
		int idx = bil.first.second;
		int id = bil.second;

		if(id==1){
			indeks = idx;
			break;
		}
	}

	int idx = i;
	//printf("indeks: %d idx: %d\n",indeks,idx);
	banyakTebasan = 0;
	for(i=0;i<idx;i++){
		iii bil = listBil[i];
		ll damage = bil.first.first;
		int idx = bil.first.second;
		int id = bil.second;

		if(idx!=indeks && id==2){
			health-=damage;
			isVisited[idx] = true;
			banyakTebasan++;
			if(health<=0){
				break;
			}
		}
	}
	if(health<=0){
		//printf("masuk sini\n");
		ans = min(ans,banyakTebasan); printf("%lld\n",ans); return 0;
	}
	//printf("health: %lld\n",health);
	if((health-b[indeks])<=0){
		//printf("masuk sini\n");
		banyakTebasan++;
		ans = min(ans,banyakTebasan);
		printf("%lld\n",ans); 
	}else{
		ll sisa = health-b[indeks];

		// printf("sisa: %lld\n",sisa);
		// printf("banyakTebasan: %lld\n",banyakTebasan);
		ll banyak = sisa/a[indeks] + 1;
		// printf("banyak: %lld\n",banyak);
		if(sisa%a[indeks]!=0){
			banyak++;
		}
		ans = min(ans,banyakTebasan+banyak);
		printf("%lld\n",ans);
	}



	return 0;
};