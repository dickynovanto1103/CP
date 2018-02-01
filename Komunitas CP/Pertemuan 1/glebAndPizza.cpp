#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define inside -1
#define rightAtTheEdge 0
#define outside 1
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int r,d,n;
	scanf("%d %d",&r,&d);
	scanf("%d",&n);
	int cnt = 0;
	for(int i=0;i<n;i++){
		int x,y,radius;
		scanf("%d %d %d",&x,&y,&radius);
		double pjgAsli = hypot(x,y);
		double asli1 = pjgAsli-(radius), asli2 = pjgAsli+(radius);
		int pjgDalam = (r-d);
		int pjgLuar = r;
		
		if(pjgAsli>=pjgDalam && pjgAsli<=pjgLuar){
			if(asli1>=pjgDalam && asli2<=pjgLuar){
				cnt++;
			}	
		}
		
	}
	printf("%d\n",cnt);
	return 0;
};