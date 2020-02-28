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
typedef pair<ii,int> iii;
typedef vector<ii> vii;

ii getGradien(ii a, ii b) {
	if(a.first == b.first){return ii(1,0);}
	if(a.second == b.second){return ii(0,1);}
	int selisihX = b.first - a.first;
	int selisihY = b.second - a.second;
	return ii(selisihY, selisihX);
}

int getDir(ii a, ii b) {
	if(b.second > a.second){return 1;}
	else if(b.second < a.second){return 0;}
	else{
		if(b.first > a.first){return 1;}
		else{return 0;}
	}
}

int sq;
int cnt[300001];
int ans = 0;

struct query{
	int l,r,id;
};

bool cmp(query a, query b) {
	if(a.l/sq != b.l/sq){return a.l/sq < b.l/sq;}
	return a.r < b.r;
}

void add(int bil) {
	if(cnt[bil] == 0){
		ans++;
	}
	cnt[bil]++;
}

void remove(int bil) {
	if(cnt[bil] == 1){
		ans--;
	}
	cnt[bil]--;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int totEdge = 0;
	map<iii, int> mapper;
	int numVertex[100001];
	int arr[300001];
	int cntUnik = 0;
	int idx = 0;
	for(i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		totEdge += k;
		numVertex[i] = k;
		vii listKoor;
		for(j=0;j<k;j++){
			int a,b;
			scanf("%d %d",&a,&b);
			listKoor.pb(ii(a,b));
		}
		for(j=0;j<k;j++){
			int next = (j+1)%k;
			ii first = listKoor[j], second = listKoor[next];
			iii pas = iii(getGradien(first, second), getDir(first, second));
			// printf("first: %d %d second: %d %d\n",first.first, first.second, second.first, second.second);
			ii gradien = getGradien(first, second);
			// printf("gradien: %d %d dir: %d\n",gradien.first, gradien.second, getDir(first, second));
			if(mapper.find(pas) == mapper.end()) {
				mapper[pas] = cntUnik;
				arr[idx++] = cntUnik;
				cntUnik++;
			}else{
				int bil = mapper[pas];
				arr[idx++] = bil;
			}
		}
	}
	sq = (int)sqrt(idx);
	for(i=1;i<=n;i++){
		numVertex[i] += numVertex[i-1];
	}
	int numQ;
	scanf("%d",&numQ);
	query q[numQ+1];
	int jawab[numQ+1];
	for(i=0;i<numQ;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--; b--;
		// printf("a: %d b: %d\n",a,b);
		if(a == 0){q[i].l = 0;}
		else{q[i].l = numVertex[a-1];}
		q[i].r = numVertex[b]-1; q[i].id = i;

		// printf("q[%d].l: %d r: %d\n",i,q[i].l, q[i].r);
	}

	sort(q, q+numQ, cmp);
	int kiri = q[0].l, kanan = q[0].l;
	add(arr[kiri]);
	for(i=0;i<numQ;i++){
		while(kiri > q[i].l) {
			add(arr[--kiri]);
		}
		while(kiri < q[i].l){
			remove(arr[kiri++]);
		}
		while(kanan > q[i].r) {
			remove(arr[kanan--]);
		}
		while(kanan < q[i].r) {
			add(arr[++kanan]);
		}
		int id = q[i].id;
		jawab[id] = ans;
	}
	for(i=0;i<numQ;i++){
		printf("%d\n",jawab[i]);
	}

	return 0;
};