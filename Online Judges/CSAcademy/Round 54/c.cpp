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

const int maxn = 100010;

int a[maxn];
int n;

int main(){
	int k,i,j;
	
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	int bil = a[0];
	int idx = 0;
	priority_queue<ii,vii, greater<ii> > pq;
	for(i=idx+1;i<=min(n-1,idx+k);i++){
		//printf("dipush: %d\n",a[i]);
		pq.push(ii(a[i],i));
	}
	while(true){
		bil = a[idx];
		int indeks = min(n-1,idx+k);
		pq.push(ii(a[indeks],indeks));
		bool done = false;

		//printf("idx: %d\n",idx);
		if(pq.top().first<bil){//bisa ditukar
			while(pq.top().second<=idx){pq.pop();}
			if(pq.top().first<bil){
				//printf("masuk dengan minimal: %d idx: %d bil: %d\n",pq.top().first,pq.top().second,bil);

				for(i=min(n-1,idx+k);i>=idx+1;i--){
					if(a[i]==pq.top().first){swap(a[idx],a[i]); done = true; break;}
				}	
			}
			
		}
		if(done){break;}
		idx++;
		if(idx==n-1){break;}
	}
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");

	return 0;
};