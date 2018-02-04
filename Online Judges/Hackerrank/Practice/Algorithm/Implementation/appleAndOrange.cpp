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
	int s,t,a,b,m,n;
	int orange,apple;
	int cntApel = 0, cntJeruk = 0;
	scanf("%d %d %d %d %d %d",&s,&t,&a,&b,&m,&n);
	int i;
	for(i=0;i<m;i++){
		int jarak;
		scanf("%d",&jarak);
		int titikJatuh = jarak+a;
		if(titikJatuh>=s && titikJatuh<=t){cntApel++;}
	}
	for(i=0;i<n;i++){
		int jarak;
		scanf("%d",&jarak);
		int titikJatuh = jarak+b;
		if(titikJatuh>=s && titikJatuh<=t){cntJeruk++;}
	}
	printf("%d\n%d\n",cntApel,cntJeruk);
	return 0;
};