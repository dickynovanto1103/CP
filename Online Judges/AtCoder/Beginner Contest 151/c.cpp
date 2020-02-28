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
typedef vector<ii> vii;

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int numpen = 0;
	int ac = 0;
	bool isAc[100001];
	memset(isAc, false, sizeof isAc);
	int pen[100001];
	memset(pen, 0, sizeof pen);
	for(i=0;i<m;i++){
		int soal;
		string stat;
		cin>>soal>>stat;
		if(isAc[soal]){continue;}
		if(stat == "WA"){
			pen[soal]++;
		}else{
			isAc[soal] = true;
			ac++;
		}
	}
	printf("%d ",ac);
	for(i=1;i<=n;i++){
		if(isAc[i]){
			numpen += pen[i];
		}
	}
	printf("%d\n",numpen);
	return 0;
};