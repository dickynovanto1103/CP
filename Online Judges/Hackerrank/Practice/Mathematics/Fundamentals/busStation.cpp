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

const int maxn = 1e5 + 5;

int a[maxn],n;

bool can(int batas){
	int i;
	i = 0;
	int jumlah = 0;
	while(i<n){
		jumlah+=a[i];
		// printf("i: %d jumlah jadi: %d\n",i,jumlah);
		if(jumlah==batas){
			//printf("masuk sini jumlah jd 0\n");
			jumlah=0;
		}
		else if(jumlah>batas){return false;}
		i++;
	}
	return jumlah==0;//tidak ada sisa
	
}

set<int> listDivisor;
set<int>::iterator it;

int main(){
	int i,j;
	int sum = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for(i=1;i*i<=sum;i++){
		if(sum%i==0){
			listDivisor.insert(i); listDivisor.insert(sum/i);
		}
	}

	vi listAns;
	for(it=listDivisor.begin();it!=listDivisor.end();it++){
		int batas = *it;
		//printf("batas: %d\n",batas);
		if(can(batas)){listAns.pb(batas);}
	}
	for(i=0;i<listAns.size();i++){
		if(i){printf(" ");}
		printf("%d",listAns[i]);
	}
	printf("\n");
	return 0;
};