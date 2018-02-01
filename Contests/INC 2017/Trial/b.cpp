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

int counterKiri[100010], counterKanan[100010];
bool cmp(ii a, ii b){
	if(a.first==b.first){
		return a.second < b.second;
	}
	a.first < b.first;
}

vector<ii> listKoor;
vector<ii>::iterator it1;

int main(){
	int n,x,y,i;

	scanf("%d",&n);
	map<int,int> mapper;
	map<int,int>::iterator it;
	map<ii,int> mapper2;
	map<ii,int>::iterator it2;
	int cnt = 0, cnt1 = 0;
	for(i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		listKoor.pb(ii(x,y));
		it2 = mapper2.find(ii(x,y));
		if(it2==mapper2.end()){
			mapper2[ii(x,y)] = cnt1;
			cnt1++;
		}
		/*absis[i] = x; ordinat[i] = y;
		it = mapper.find(x);
		if(it==mapper.end()){
			mapper[x] = cnt;
			counterKiri[cnt] = 1;
			cnt++;
		}else{
			int idx = mapper[x];
			counterKiri[idx]++;
		}
		it = mapper.find(y);
		if(it==mapper.end()){
			mapper[y] = cnt;
			counterKanan[cnt] = 1;
			cnt++;
		}else{
			int idx = mapper[y];
			counterKanan[idx]++;
		}*/
	}
	/*sort(listKoor.begin(),listKoor.end(),cmp);
	it1=unique(listKoor.begin(),listKoor.end());
	listKoor.resize(distance(listKoor.begin(),it1));*/
	n = listKoor.size();
	for(i=0;i<n;i++){
		x = listKoor[i].first; y = listKoor[i].second;
		//absis[i] = x; ordinat[i] = y;
		it = mapper.find(x);
		if(it==mapper.end()){
			mapper[x] = cnt;
			counterKiri[cnt] = 1;
			cnt++;
		}else{
			int idx = mapper[x];
			counterKiri[idx]++;
		}
		it = mapper.find(y);
		if(it==mapper.end()){
			mapper[y] = cnt;
			counterKanan[cnt] = 1;
			cnt++;
		}else{
			int idx = mapper[y];
			counterKanan[idx]++;
		}	
	}
	int ans = 0;
	/*for(i=0;i<n;i++){
		x = absis[i]; y = ordinat[i];
		int banyakSamaKiri, banyakSamaKanan;
		int idxKiri = mapper[x], idxKanan = mapper[y];
		banyakSamaKiri = counterKiri[idxKiri]; banyakSamaKanan = counterKanan[idxKanan];
		ans = max(ans,max(banyakSamaKanan-1,banyakSamaKiri-1));
	}*/
	for(i=0;i<n;i++){
		x = listKoor[i].first; y = listKoor[i].second;
		int idx1 = mapper[x], idx2 = mapper[y];
		ans = max(ans,counterKiri[idx1])
	}
	for(it=mapper.begin();it!=mapper.end();++it){
		int bil = it->first;
		int idx = it->second;
		// printf("bil: %d idx: %d\n",bil,idx);
		// printf("counterKiri: %d counterKanan: %d\n",counterKiri[idx],counterKanan[idx]);
		int jumlahKiri = counterKiri[idx], jumlahKanan = counterKanan[idx];
		if(jumlahKanan==1 && jumlahKiri==1){continue;}
		ans = max(ans,max(jumlahKiri,jumlahKanan));
	}
	printf("%d\n",ans);
	return 0;
};