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
	int n,a,b;
	
	int arr[maxn];
	bool isB[maxn], isA[maxn];
	scanf("%d %d %d",&n,&a,&b);
	map<int,int> mapper;
	set<int> s,sA,sB;
	for(int i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		arr[i] = bil;
		mapper[bil] = i;
		s.insert(bil);
	}
	
	UnionFind UF(n);
	memset(isA, false, sizeof isA);
	memset(isB, false, sizeof isB);

	for(int i=0;i<n;i++){
		int bil = arr[i];
		
		int bil1 = a-bil;
		int bil2 = b-bil;
		int idx = mapper[bil];
		int idx1 = mapper[bil1];
		int idx2 = mapper[bil2];
		if(s.find(bil1) == s.end() && s.find(bil2) == s.end()){
			printf("NO\n");
			return 0;
		}
		bool terambil = false;
		if(s.find(bil1) == s.end()) {
			if(s.find(bil2)==s.end()){
				printf("NO\n");
			}else{
				if(isA[idx2])
			}
		}
		if(s.find(bil2))
	}

	printf("YES\n");
	for(int i=0;i<n;i++){
		if(i){printf(" ");}
		if(isB[i]){
			printf("1");
		}else{
			printf("0");
		}
	}
	printf("\n");
	return 0;
};