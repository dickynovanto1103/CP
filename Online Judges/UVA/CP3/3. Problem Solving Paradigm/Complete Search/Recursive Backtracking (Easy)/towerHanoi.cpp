#include <bits/stdc++.h>

using namespace std;
int a[55], ans, n;
bool found;
void solve(int bil, int terpakai){
	int i;
	if(found){return;}
	else{
		for(i=0;i<terpakai;i++){
			if(a[i]!=-1){
				int angka = a[i]+bil;
				double akar = sqrt(angka);
				double temp = ceil(akar);
				if(akar==temp){
					//printf("bil: %d ditempati di peg ke %d\n",bil,i);
					a[i]=bil; solve(bil+1, terpakai); break;
				}//bs ditempati
			}
		}
		if(i==n){
			//printf("bil final: %d\n",bil);
			found = true; ans = bil;
		}
		if(!found){
			if(i==terpakai && terpakai!=n){
				//printf("memakai i: %d dengan bil: %d\n",i,bil);
				a[terpakai] = bil; solve(bil+1,terpakai+1);
			}	
		}
		
		
	}
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		found = false;
		memset(a,-1,sizeof a);
		scanf("%d",&n);
		solve(1,0);
		printf("%d\n",ans-1);
	}
	return 0;
}