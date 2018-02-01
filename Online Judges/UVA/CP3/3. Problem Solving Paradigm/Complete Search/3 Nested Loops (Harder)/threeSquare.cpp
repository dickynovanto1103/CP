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
	int tc,i,n,j,k,l;
	scanf("%d",&tc);
	while(tc--){
		bool found = false;
		scanf("%d",&n);
		for(i=0;i*i<=n;i++){
			int a = i*i;
			for(j=i;j*j<=(n-a);j++){
				int b = a + j*j;
				//cari c
				int c = n-b;
				double temp = sqrt(c);
				int hasilC = (int)ceil(temp);
				if(hasilC == (int)temp && hasilC>=j){
					found = true;
					printf("%d %d %d\n",i,j,hasilC);
					break;
				}
			}
			if(found){break;}
		}
		if(!found){printf("-1\n");}
	}
	return 0;
}