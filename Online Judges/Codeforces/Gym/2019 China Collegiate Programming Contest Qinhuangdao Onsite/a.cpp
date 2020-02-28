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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<ii> vii;

const int maxn = 2e3 + 3;

int main(){
	int n,q,i,j;
	scanf("%d %d",&n,&q);
	map<int,int> mapperX, mapperY;
	ii a[maxn];
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i].first, &a[i].second);
		mapperX[a[i].first]++; mapperY[a[i].second]++;
	}

	for(i=0;i<q;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		//cari yg se x sama dia, dan tiap dari yg se x, ada brp yg se y dari node lain itu..dan juga sebaliknya dari y juga
		int ans = 0;
		for(j=0;j<n;j++){
			if(x == a[j].first){
				ans += mapperY[a[j].second];
				ans--;
				// printf("ans jd: %d\n",ans);
			}
		}
		for(j=0;j<n;j++){
			if(y == a[j].second){
				ans += mapperX[a[j].first];
				ans--;
				// printf("sini ans jd: %d\n",ans);
			}
		}
		int tambahX = mapperX[x], tambahY = mapperY[y];
		ans += tambahY*tambahX;
		printf("%d\n",ans);
	}

	return 0;
};