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

vector<vi> AdjList;

int banyakRoot = 1;

void addToNextLevel(int n, int node){
	for(int i=n-1;i>=0;i--){
		if(AdjList[i].size() < banyakRoot) {
			AdjList[i].pb(node);
			break;
		}
	}

}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int cnt[1010];
	memset(cnt, 0, sizeof cnt);
	multiset<ii> s;
	multiset<ii>::iterator it;

	for(i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		s.insert(ii(a,b));
		cnt[a]++; cnt[b]++;
	}

	vii a;

	for(i=1;i<=1000;i++){
		if(cnt[i] > 0){a.pb(ii(cnt[i],i));}
	}
	sort(a.begin(), a.end());
	int terbesar = a[0].first;

	if(a[1].first == terbesar){printf("NO\n"); return 0;}

	//assigning level
	int level[1010];
	
	AdjList.assign(1010, vi());
	int maks = a.back().first;
	
	for(i=a.size()-2;i>=0;i--){
		ii front = a[i];
		if(front.first == maks){
			banyakRoot++;
		}
	}

	memset(level, -1, sizeof level);
	for(i=0;i<a.size();i++){
		ii front = a[i];
		int ukuran = front.first, node = front.second;

		int selisih = terbesar - ukuran;
		int lvl = 1 + selisih;
		level[node] = lvl;
		AdjList[lvl].pb(node);
	}

	for(i=1;i<=n;i++){
		if(level[i] != -1 && level[i]!=1){
			//cek ada brp banyak angka yang lebih kecil dari dia dan levelnya -1 dan diassign ke sana..kalo 
			int butuh = level[i] - 2;
			int counter = 0;
			for(j=i-1;j>=0;j--){
				if(level[j] == -1)
					addToNextLevel(butuh,j)
			}
			if(counter >= butuh){
				int levelButuh = 
				for(j=i-1;j>=0;j--){
					
				}
			}

		}
	}

	return 0;
};