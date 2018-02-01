#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,i,j,a[5010], waktu[1010], pil[1010];
	scanf("%d",&n);
	int sum = 0, minim = 0;
	memset(a,-1,sizeof a);
	int batasbawah = 0;
	for(i=0;i<n;i++){
		scanf("%d %d",&pil[i],&waktu[i]);
	}
	for(i=0;i<n;i++){
		if(pil[i]==1){
			//cari terus sampe 2;
			int time=waktu[i];
			j = i+1;
			while(pil[j]!=2 && j<n){j++;}
			if(j==n){sum+=(5000-time);}
			else{sum+=waktu[j] - time;}
			
			i = j;
		}
	}
	printf("%d\n",sum);

	return 0;
}