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

struct node {
	ll biaya;
	int a, b, c;
};

struct compare{
	bool operator()(const node& node1, const node& node2){
		return node1.biaya < node2.biaya;
	}
}

priority_queue<node, vector<node>, compare, > pq;

int main(){
	int tc,x,y,z,a,b,c;
	int pos1 = 0,pos2 = 0,pos3 = 0;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d %d %d %d",&x,&y,&z,&a,&b,&c);
		node titik;
		titik.a = 0; titik.b = 0; titik.c = 0; titik.biaya = 0;
		pq.push(titik);
		while(!pq.empty()) {
			node u = pq.front(); pq.pop();
			if()
		}
	}
	return 0;
};