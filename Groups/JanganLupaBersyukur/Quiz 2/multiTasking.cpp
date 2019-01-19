#include <bits/stdc++.h>

using namespace std;
#define maxn 1000002


int main()
{
	int n,m,i,j,test=1;
	while(scanf("%d %d",&n,&m),(n||m)){
		bitset<maxn> bs;
		bool found = true;
		//printf("case: %d n: %d m: %d\n",test++,n,m);
		int a[105],b[105];
		for(i=0;i<n;i++){scanf("%d %d",&a[i],&b[i]);}
		for(i=0;i<n;i++){
			
			for(j=a[i];j<b[i];j++){
				
				if(bs.test(j)){found = false; break;}
				else{bs.set(j);}
			}

			if(!found){break;}

		}
		int rep[105];
		for(i=0;i<m;i++){scanf("%d %d %d",&a[i],&b[i],&rep[i]);}
		if(found){
			for(i=0;i<m;i++){
				//j=0;
				int awal = a[i], akhir = b[i];
				while(awal<=1000000){
					
					for(j=awal;j<akhir && j<=1000000;j++){
						if(bs.test(j)){found = false; break;}
						else{bs.set(j);}
					}
					if(!found) break;
					awal+=rep[i]; akhir+=rep[i];
				}
				if(!found) break;
			}	
		}
		
		if(found){printf("NO CONFLICT\n");}
		else{printf("CONFLICT\n");}
		
	}
	return 0;
}