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

const int maxn = 1001;
int res[maxn][maxn], f,mf, s,t;
vi p;
 
vector<vi> AdjList;

void augment(int node, int minEdge) {
	if(node == s){f = minEdge; return;}
	else if(p[node] != -1){
		augment(p[node], min(minEdge, res[p[node]][node]));
		res[p[node]][node] -= f; res[node][p[node]] += f;
	}
}

void maxflow() {
	mf = 0;
	while(true) {
		f = 0;
		p.assign(maxn,-1);
		int i;
		
		bitset<maxn> isVisited; isVisited[s] = true; p[s] = -1;
		queue<int> q; q.push(s);
		while(!q.empty()) {
			int front = q.front(); q.pop();
			if(front == t){break;}
			for(i=0;i<AdjList[front].size();i++){
				int v = AdjList[front][i];
				if(res[front][v] > 0 && !isVisited[v]) {
					isVisited[v] = true; q.push(v); p[v] = front;
				}
			}
		}
		augment(t, inf);
		p.clear();
		if(f==0){break;}
		mf+=f;
	}
}

map<string,int> mapper;
string listKata[1000*maxn];

int main(){
	int tc;
	scanf("%d ",&tc);
	int cnt = 1;
	s = 0, t = 1000;
	int banyakLine = 0;
	while(tc--) {
		AdjList.assign(1001,vi());

		while(true) {
			string kata;
			getline(cin,kata);
			if(kata==""){
				maxflow();
				break;
			}
			stringstream ss(kata);
			string participant, dummy;
			ss>>participant>>dummy;
			string state;
			banyakLine++;
			cout<<"participant: "<<participant<<endl;
			int idxParticipant = 0;
			if(mapper.find(participant) == mapper.end()) {
				mapper[participant] = cnt;
				listKata[cnt] = participant;
				idxParticipant = cnt;
				cnt++;
			}
			while(ss>>state) {
				cout<<"state: "<<state<<endl;
				if(mapper.find(state) == mapper.end()) {
					mapper[state] = cnt;
					listKata[cnt] = state;
					AdjList[idxParticipant].pb(cnt);
					AdjList[cnt].pb(idxParticipant);
					res[idxParticipant][cnt]
					cnt++;
				}else{
					int idxState = mapper[state];
				}
			}
			cout<<"kata: "<<kata<<endl;	
		}
		
	}
	return 0;
};