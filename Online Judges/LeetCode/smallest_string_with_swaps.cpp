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
typedef vector<char> vc;
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    	int n = s.size();
    	UnionFind UF(n);
    	for(vi pair: pairs) {
    		int a = pair[0], b = pair[1];
    		UF.unionSet(a, b);
    	}

    	groupToChars.assign(n, vc());
    	for(int i=0;i<n;i++){
    		int group = UF.findSet(i);
    		groupToChars[group].pb(s[i]);
    	}

    	for(int i=0;i<n;i++){
    		sort(groupToChars[i].begin(), groupToChars[i].end());
    		curIdxes[i] = 0;
    	}

    	for(int i=0;i<n;i++){
    		int group = UF.findSet(i);
    		s[i] = groupToChars[group][curIdxes[group]++];
    	}

        return s;
    }
private:
	vector<vc> groupToChars;
	int curIdxes[100001];
};

int main(){
	string s;
	while(cin>>s) {
		Solution sol;
		int n;
		scanf("%d",&n);
		vector<vi> pairs;
		for(int i=0;i<n;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			vi v = {a, b};
			pairs.pb(v);
		}
		cout<<sol.smallestStringWithSwaps(s, pairs)<<endl;
	}
	
	return 0;
};