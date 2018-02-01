#include <bits/stdc++.h>

using namespace std;

int main(){
	int m,q,i,j,k;
	string movie[1001];
	scanf("%d %d",&m,&q);
	for(i=0;i<m;i++){cin>>movie[i];}
	while(q--){
		string clip;
		cin>>clip;
		//cari di list movie
		int pjgClip = clip.length();
		int minim = 1000000000, idx = 0;
		for(i=0;i<m;i++){
			string kata = movie[i];
			int pjgKata = kata.length();
			
			if(pjgKata>=pjgClip){
				int awal = 0, akhir = pjgClip-1;
				
				while(akhir<=pjgKata-1){
					int cnt = 0;
					int idxClip = 0;
					for(j=awal;j<=akhir;j++){
						if(kata[j]!=clip[idxClip]){cnt++;}
						idxClip++;
					}
					if(minim > cnt){
						minim = cnt; idx = i;
					}
					awal++; akhir++;
				}
				
			}
		}
		printf("%d\n",idx+1);
	}
	return 0;
}