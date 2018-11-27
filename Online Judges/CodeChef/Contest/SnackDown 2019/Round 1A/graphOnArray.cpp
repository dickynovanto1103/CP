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

bool isprime[55];
int prime[55];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

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
	int tc,n,i,j;
	scanf("%d",&tc);
	int a[55];
	memset(isprime, true, sizeof isprime);
	sieve(50);
	int cnt = 0;
	bool isVisited[55];

	for(i=0;i<50;i++){
		if(isprime[i]){
			prime[cnt++] = i;
		}
	}

	while(tc--){
		scanf("%d",&n);
		UnionFind UF(n);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(__gcd(a[i],a[j]) == 1){
					UF.unionSet(i,j);
				}
			}
		}
		int berubah = UF.numDisjointSet()-1;
		
		srand(time(NULL));
		if(berubah == 0){
			printf("0\n");
			for(i=0;i<n;i++){
				if(i){printf(" ");}
				printf("%d",a[i]);
			}
			printf("\n");
		}else{
			printf("1\n");
			memset(isVisited, false, sizeof isVisited);
			for(i=0;i<n;i++){
				if(isprime[a[i]]){
					isVisited[a[i]] = true;
				}
			}
			int bil;
			for(i=cnt-1;i>=0;i--){
				if(!isVisited[prime[i]]){
					bil = prime[i];
					// printf("bil: %d\n",bil);
					break;
				}
			}
			bool assigned = false;
			for(i=0;i<n;i++){
				if(!isprime[a[i]]){
					a[i] = bil;
					assigned = true;
					break;
				}
			}
			if(!assigned){
				a[n-1] = bil;
			}
			for(i=0;i<n;i++){
				if(i){printf(" ");}
				printf("%d",a[i]);
			}
			printf("\n");
		}
	}
	return 0;
};