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
	int n;
	set<int> s;
	set<int>::iterator it;
	int occ[120],i,j;
	memset(occ,0,sizeof occ);
	scanf("%d",&n);
	int bil;
	for(i=0;i<n;i++){
		scanf("%d",&bil); 
		s.insert(bil);
		occ[bil]++;
	}
	if(s.size()==2){
		vi listBil;
		for(it=s.begin();it!=s.end();it++){
			listBil.pb(*it);
		}
		int bil1 = listBil[0], bil2 = listBil[1];
		if(occ[bil1]==occ[bil2]){printf("YES\n%d %d\n",bil1,bil2); }
		else{printf("NO\n");}
	}else{
		printf("NO\n");
	}
	return 0;
};