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

int main(){
	int n,sb,r,i,j;
	int a[15], b[15];
	scanf("%d %d %d",&n,&sb,&r);
	set<int> s,sA;
	set<int>::iterator it;
	for(i=0;i<sb;i++){scanf("%d",&a[i]); sA.insert(a[i]);}
	
	for(i=0;i<r;i++){scanf("%d",&b[i]); s.insert(b[i]);}

	for(i=0;i<sb;i++){//ada ga yg dirinya sendiri
		int yangRusak = a[i];
		if(s.count(yangRusak)){
			s.erase(yangRusak);
			sA.erase(yangRusak);
		}
	}
	int cntA = 0;
	for(it=sA.begin();it!=sA.end();it++){
		int v = *it;
		a[cntA] = v;
		cntA++;
	}
	int cntB = 0;
	for(it=s.begin();it!=s.end();it++){
		int v = *it;
		b[cntB] = v;
		cntB++;
	}
	int ans = cntA;

	for(i=0;i<cntA;i++){
		int bil = a[i];
		if(s.count(bil-1)){
			ans--;
			s.erase(bil-1);
			continue;
		}
		if(s.count(bil+1)){
			ans--;
			s.erase(bil+1);
			continue;
		}
	}
	printf("%d\n",ans);
	return 0;
};