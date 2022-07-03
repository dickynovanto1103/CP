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
typedef pair<ii,int> iii;
typedef vector<ii> vii;

bool cmp(iii a, iii b) {
	return a.second < b.second;
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

class Solution {
public:
	int jarak(ii a, ii b) {
		return abs(a.first - b.first) + abs(a.second - b.second);
	}

    int minCostConnectPoints(vector<vector<int>>& points) {
        int sz = points.size();
        for(int i=0;i<sz;i++){
        	ii point1 = ii(points[i][0], points[i][1]);
        	for(int j=i+1;j<sz;j++){
        		ii point2 = ii(points[j][0], points[j][1]);
        		int selisih = jarak(point1, point2);

        		edgeList.pb(iii(ii(i,j), selisih));
        	}
        }

        sort(edgeList.begin(), edgeList.end(), cmp);
        UnionFind UF(points.size() + 1);
        int mst = 0;
        sz = edgeList.size();
        for(int i=0;i<sz;i++){
        	ii pas = edgeList[i].first;
        	int jarak = edgeList[i].second;
        	if(UF.isSameSet(pas.first, pas.second)) {
        		continue;
        	}

        	mst += jarak;
        	UF.unionSet(pas.first, pas.second);
        }

        return mst;
    }

private:
	vector<iii> edgeList;
};

int main(){
		
	
	return 0;
};