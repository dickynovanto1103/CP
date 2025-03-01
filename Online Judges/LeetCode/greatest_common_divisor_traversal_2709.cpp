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
// typedef __int128_t lll;
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

class Solution {
public:
	bool isprime[500];
	vi primeList;

    bool canTraverseAllPairs(vector<int>& nums) {
  		sieve(400);
  		int n = nums.size();
  		set<int> newPrimeList;
  		set<int>::iterator it;
  		for(int i=0;i<n;i++){
  			if(nums[i] > 400 && checkPrime(nums[i])) {
  				newPrimeList.insert(nums[i]);
  			}
  		}

  		for(it=newPrimeList.begin(); it!= newPrimeList.end();it++){
  			primeList.pb(*it);
  		}


  		int numPrime = primeList.size();
  		// printf("numPrime: %d\n", numPrime);
  		UnionFind UF(n);

  		for(int i=0;i<numPrime;i++){
  			vi idxList;
  			for(int j=0;j<n;j++){
  				if(nums[j] % primeList[i] == 0) {
  					idxList.pb(j);
  					// printf("prime: %d, pushed idx: %d\n", primeList[i], j);
  				}
  			}

  			// printf("processing i: %d, prime: %d idxList size: %d\n", i, primeList[i], idxList.size());
  			for(int j=0;j<(int)idxList.size() - 1;j++) {
  				UF.unionSet(idxList[j], idxList[j+1]);
  			}
  			// printf("done\n");
  		}

  		return UF.numDisjointSet() == 1;
    }

    bool checkPrime(int n) {
    	for(int i=2;i*i<=n;i++){
    		if(n % i == 0) {
    			return false;
    		}
    	}

    	return true;
    }

    void sieve(int n) {
    	memset(isprime, true, sizeof isprime);
    	isprime[0] = isprime[1] = false;
    	for(int i=2;i*i<=n;i++){
    		if(!isprime[i]) {
    			continue;
    		}

    		for(int j=i*i;j<=n;j+=i) {
    			isprime[j] = false;
    		}
    	}

    	for(int i=2;i<=n;i++){
    		if(isprime[i]) {
    			primeList.pb(i);
    		}
    	}
    }
};

void solve(){

}

int main(){
	// int tc = 1;
	// scanf("%d",&tc);
	// while(tc--){
	// 	solve();
	// }
	int n;
	while(scanf("%d",&n) != EOF) {
		Solution s;
		vector<int> nums(n);
		for(int i=0;i<n;i++){
			scanf("%d",&nums[i]);
		}

		cout<<s.canTraverseAllPairs(nums)<<endl;	
	}

	

	return 0;
};