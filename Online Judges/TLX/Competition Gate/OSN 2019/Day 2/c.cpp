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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

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

struct segment{
	int koor, id;
	int isEnd;
};

bool cmp(segment a, segment b) {
	if(a.koor == b.koor) {
		return a.isEnd < b.isEnd;
	}
	return a.koor < b.koor;
}

int main(){
	int n,s,q,i,j;
	scanf("%d %d %d",&n,&s,&q);
	vector<segment> listSegment;
	for(i=1;i<=n;i++){
		int cnt;
		scanf("%d",&cnt);
		for(j=0;j<cnt;j++){
			int a,b;
			scanf("%d %d",&a,&b);
			segment seg;
			seg.koor = a; seg.id = i; seg.isEnd = 0;
			listSegment.pb(seg);
			seg.koor = b; seg.isEnd = 1;
			listSegment.pb(seg);
		}
	}

	sort(listSegment.begin(), listSegment.end(), cmp);
	int ukuran = listSegment.size();
	UnionFind UF(n+1);
	set<int> ada;
	for(i=0;i<ukuran;i++){
		segment seg = listSegment[i];
		int koor = seg.koor, isEnd = seg.isEnd, id = seg.id;
		// printf("koor: %d id: %d isEnd: %d\n",koor, id, isEnd);
		if(isEnd){
			ada.erase(id);
			// printf("hapus %d\n",id);
		}else{
			if(ada.size()) {
				int awal = *ada.begin();
				UF.unionSet(awal, id);
				// printf("gabung %d dengan %d\n",awal, id);
			}
			// printf("insert %d\n",id);
			ada.insert(id);
		}
	}

	for(i=0;i<q;i++){
		int orang;
		scanf("%d",&orang);
		printf("%d\n",UF.sizeSetOf(orang));
	}
	return 0;
};