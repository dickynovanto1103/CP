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

int main(){
	int n,i,j,tc,k;
	int a[maxn];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		sort(a,a+n);
		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d",a[i]);
		}
		printf("\n");
		vi listDiff;
		for(i=0;i<(n-1);i++){
			int diff = a[i+1] - a[i];
			listDiff.pb(diff);
		}
		sort(listDiff.begin(), listDiff.end());
		printf("listDiff\n");
		for(i=0;i<listDiff.size();i++){
			if(i){printf(" ");}
			printf("%d",listDiff[i]);
		}
		printf("\n");
		int selisih = a[n-1] - a[0];
		int banyakGrup = n/k;
		int banyakAmbil = banyakGrup-1;
		for(i=0;i<banyakAmbil;i++){
			int bilTerakhir = listDiff.back();
			printf("bilTerakhir: %d\n",bilTerakhir);
			selisih-=bilTerakhir;
			printf("selisih jd: %d\n",selisih);
			listDiff.pop_back();
		}
		printf("%d\n",selisih);
	}
	return 0;
};