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

const int maxn = 1e3 + 3;

set<ii> s;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int x[maxn], y[maxn], a[maxn], b[maxn];
	for(i=0;i<n;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
	}

	for(i=0;i<n;i++){
		set<ii> stemp;
		for(j=0;j<n;j++){
			int xbaru = x[i] + a[j], ybaru = y[i] + b[j];
			if(i == 0){
				s.insert(ii(xbaru, ybaru));
				// printf("insert %d %d\n",xbaru, ybaru);
			}else{
				if(s.count(ii(xbaru, ybaru))){
					stemp.insert(ii(xbaru, ybaru));
					// printf("diinsert yang ini %d %d\n",xbaru, ybaru);
				}
			}
		}
		

		if(i > 0){
			s.clear();
			s = stemp;
		}
	}
	ii bil = *s.begin();
	printf("%d %d\n",bil.first, bil.second);

	return 0;
};