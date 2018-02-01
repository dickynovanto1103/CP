#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc,i,idxp,idxs,j;
	string p,s;
	bool found;
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		found=false;
		printf("Case #%d: ",i);
		cin>>p>>s;
		idxp=idxs=0;
		int panjangp = p.length();
		int panjangs = s.length();
		while(panjangp <= panjangs-idxs){
			for(j=0;j<panjangp;j++){
				if(p[j]!=s[idxs]){idxs++;break;}
				else{idxs++;}
				//if(panjangp > panjangs-idxs){break;}
			}
			if(j==panjangp){found=true; break;}
		}
		if(!found){printf("NO\n");}
		else{printf("YES\n");}
	}
	return 0;
}