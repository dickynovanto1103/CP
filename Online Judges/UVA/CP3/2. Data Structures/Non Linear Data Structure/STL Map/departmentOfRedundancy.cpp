#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n;
	map<int,int> mapper;
	map<int,int>::iterator it;
	vi listAngka, listCounter;
	int cnt = 0;
	while(scanf("%d",&n)!=EOF){
		it=mapper.find(n);
		if(it!=mapper.end()){
			int idx = mapper[n];
			listCounter[idx]++;
		}else{
			//printf("ga ketemu: %d\n",n);
			mapper[n] = cnt;
			listAngka.pb(n);
			listCounter.pb(1);
			cnt++;
		}
	}
	int ukuran = listAngka.size();
	int i;
	for(i=0;i<ukuran;i++){
		printf("%d %d\n",listAngka[i], listCounter[i]);
	}
	return 0;
}