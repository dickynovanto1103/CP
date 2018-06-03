/*
ID: dickyno1
LANG: C++
TASK: milk2
*/

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

const int maxn = 5e3 + 3;

bool isVisited[1000001];
bool isCounted[1000001];
int maksEnd = 0, minStart = inf;

struct period {
	int begin, end;
};

bool cmp(period a, period b) {
	if(a.begin==b.begin) {return a.end < b.end;}
	return a.begin < b.begin;
}

int count(int node, bool nilaiAwal) {
	isCounted[node] = true;
	int cnt = 1;
	for(int i=node+1;i<maksEnd;i++){
		if(nilaiAwal == isVisited[i]) {
			isCounted[i] = true;
			cnt++;
		}else{
			break;
		}
	}
	return cnt;
}

int main() {
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);

	int n,i,j;
	scanf("%d",&n);
	period p[maxn];
	
	for(i=0;i<n;i++){
		scanf("%d %d",&p[i].begin,&p[i].end);
		maksEnd = max(maksEnd, p[i].end);
		minStart = min(minStart, p[i].begin);
	}
	fprintf(stderr, "maksEnd: %d minStart ;%d \n",maksEnd, minStart);
	sort(p,p+n,cmp);
	
	memset(isVisited, false,sizeof isVisited);
	fprintf(stderr, "n: %d\n",n);
	for(i=0;i<n;i++){
		int awal = p[i].begin, akhir = p[i].end;
		fprintf(stderr, "i: %d awal: %d akhir: %d\n",i,awal, akhir);
		if(!isVisited[awal]) {
			for(j=awal;j<akhir;j++){
				if(isVisited[j]){break;}
				isVisited[j] = true;
			}
		}
		if(!isVisited[akhir]) {
			for(j=akhir-1;j>=awal;j--) {
				if(isVisited[j]){break;}
				isVisited[j] = true;
			}
		}
	}

	memset(isCounted, false, sizeof isCounted);
	int maksNyambung = 0, maksTidakNyambung = 0;
	for(i=minStart;i<maksEnd;i++){
		if(isCounted[i]){continue;}
		int ans = count(i,isVisited[i]);
		if(isVisited[i]){
			maksNyambung = max(maksNyambung, ans);
		}else{
			maksTidakNyambung = max(maksTidakNyambung, ans);
		}
	}

	printf("%d %d\n",maksNyambung, maksTidakNyambung);
	cerr<<maksNyambung<<" "<<maksTidakNyambung<<endl;
	return 0;
}
