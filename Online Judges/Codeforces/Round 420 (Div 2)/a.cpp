#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,a[51][51],i,j,k,l;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	bool found;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			int bil = a[i][j];
			//printf("bil: %d\n",bil);
			if(bil!=1){
				found = false;
				//printf("bil yang ingin diuji: %d\n",bil);
				for(k=0;k<n;k++){//cek di row
					if(k!=i){
						int bil1 = a[k][j];
						//printf("cek di r: %d c: %d bil1: %d\n",k,j,bil1);
						for(l=0;l<n;l++){
							
							if(l!=j){
								int bil2 = a[i][l];
								//printf("cek di r: %d c: %d bil2: %d\n",k,j,bil2);
								//printf("bil2: %d\n",bil2);
								
								if(bil1+bil2==bil){found = true; break;}
								
							}
						}						
					}
					if(found){break;}	
					
				}
				if(!found){break;}
			}
		}
		if(!found){break;}
	}
	if(!found){printf("No\n");}
	else{printf("Yes\n");}
	return 0;
}