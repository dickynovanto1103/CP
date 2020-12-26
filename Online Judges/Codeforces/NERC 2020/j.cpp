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
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

class UnionFind{
private: 
	vi rank,p,setSize;
	int numset,i;
public:
	UnionFind(int n){
		numset=n; setSize.assign(n,1); rank.assign(n,0); p.assign(n,0);
		for(i=0;i<n;i++){p[i]=i;}
	}

	int findSet(int i){return (p[i]==i) ? i : (p[i]=findSet(p[i]));}
	bool isSameSet(int i, int j){return findSet(i)==findSet(j);}
	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			numset--;
			int x=findSet(i), y=findSet(j);
			if(rank[x] > rank[y]){p[y]=x; setSize[x]+=setSize[y];}
			else{
				p[x]=y;
				setSize[y]+=setSize[x];
				if(rank[x]==rank[y]){rank[y]++;}
			}
		}
	}
	int numDisjointSet(){return numset;}
	int sizeSetOf(int i){return setSize[findSet(i)];}
};



int main(){
	int tc,i,j,n,m,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&n,&m,&k);
		viii edgeList;
		int a,b,w;
		for(i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&w);
			a--; b--;
			edgeList.pb(iii(w, ii(a,b)));
			// printf("w: %d a: %d b: %d\n", w, a, b);
		}
		sort(edgeList.begin(), edgeList.end());
		UnionFind UF(n);
		vi listBerat;
		int beratPalingDekatKeK = -1;
		for(i=0;i<m;i++){
			iii pas = edgeList[i];
			int berat = pas.first, a = pas.second.first, b = pas.second.second;
			if(berat >= k && UF.isSameSet(a, b)){
				continue;
			}
			UF.unionSet(a, b);
			listBerat.pb(berat);
			
			if(UF.numDisjointSet() == 1) { //sudah connected, saatnya tanya
				if(berat >= k){
					break;
				}else{
					beratPalingDekatKeK = berat;
				}
			}
		}
		assert(listBerat.size() > 0);
		int palingBerat = listBerat[listBerat.size() - 1];
		if(palingBerat < k){
			for(i=0;i<m;i++){
				iii pas = edgeList[i];
				int berat = pas.first;
				if(berat >= k){
					listBerat.pb(berat);
					break;
				}
			}
		}
		
		ll ans1 = (ll)inf*inf;
		if(beratPalingDekatKeK != -1){
			ans1 = k - beratPalingDekatKeK;
		}

		ll dikurang = 0;
		bool adaSamaAtauLebihBesar = false;
		for(i=listBerat.size()-1;i>=0;i--){
			if(listBerat[i] >= k){
				adaSamaAtauLebihBesar = true;
				dikurang += (listBerat[i] - k);
			}else{
				break;
			}
		}


		ll ans;
		if(adaSamaAtauLebihBesar) {
			ans = min(ans1, dikurang);
		}else{
			ans = ans1;
		}

		printf("%lld\n",ans);
	}
	
	return 0;
};