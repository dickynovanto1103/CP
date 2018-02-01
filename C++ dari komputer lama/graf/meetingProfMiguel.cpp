#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
#define inf 1000000000
int mat[30][30], mat1[30][30];

int main(){
	int n,i,j,k,w,cnt;
	char age,dir,awal,akhir;
	
	map<char,int> mapper;
	map<char,int>::iterator it;
	map<int,char> mapper2;
	while(scanf("%d",&n),n){
		//printf("n: %d\n",n);
		for(i=0;i<26;i++){
			for(j=0;j<26;j++){
				mat[i][j] = inf; mat1[i][j] = inf;
				if(i==j){mat[i][j] = 0; mat1[i][j] = 0;}
			}
		}
		cnt=0;
		for(i=0;i<n;i++){
			scanf("\n%c %c %c %c %d",&age,&dir,&awal,&akhir,&w);
			//printf("%c %c %c %c %d\n",age,dir,awal,akhir,w);
			it = mapper.find(awal);
			if(it==mapper.end()){mapper[awal]=cnt; mapper2[cnt]=awal; cnt++;}
			it = mapper.find(akhir);
			if(it==mapper.end()){mapper[akhir]=cnt; mapper2[cnt]=akhir; cnt++;}

			int bil1 = mapper[awal], bil2 = mapper[akhir];
			//printf("bil1: %d bil2: %d\n",bil1,bil2);
			//printf("karakter: %c bil: %d karakter: %c bil: %d\n",awal,bil1,akhir,bil2);
			if(age=='Y'){
				if(bil1!=bil2){//klo sama..ttp 0
					mat[bil1][bil2] = w;
					if(dir=='B'){mat[bil2][bil1]=w;}	
				}
			}
			else{
				if(bil1!=bil2){
					mat1[bil1][bil2] = w;
					if(dir=='B'){mat1[bil2][bil1]=w;}	
				}
			}
		}
		//printf("cnt: %d\n",cnt);
		
		//floyd warshall on Y graph
		for(k=0;k<cnt;k++){
			for(i=0;i<cnt;i++){
				for(j=0;j<cnt;j++){
					mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
				}
			}
		}
		//floyd warshall on M graph
		for(k=0;k<cnt;k++){
			for(i=0;i<cnt;i++){
				for(j=0;j<cnt;j++){
					mat1[i][j] = min(mat1[i][j], mat1[i][k]+mat1[k][j]);
				}
			}
		}

		//traversal semua node..cari yang dr awal hingga akhir yg dihubungkan dengan node ke i
		scanf(" %c %c ",&awal,&akhir);
		//printf("awal: %c bil: %d akhir: %c bil: %d\n",awal,bil1,akhir,bil2);
		int ans = inf;
		char karakter;
		vector<char> listkar;
		bool found = true;
		it=mapper.find(awal);
		if(it==mapper.end()){found = false;}
		it=mapper.find(akhir);
		if(it==mapper.end()){found = false;}
		if(found){
			int bil1 = mapper[awal], bil2 = mapper[akhir];
			for(i=0;i<cnt;i++){
				if(ans > mat[bil1][i] + mat1[bil2][i]){
					ans = mat[bil1][i] + mat1[bil2][i];
				}
			}
			if(ans!=inf){
				for(i=0;i<cnt;i++){
					if(ans == mat[bil1][i] + mat1[bil2][i]){
						ans = mat[bil1][i] + mat1[bil2][i];
						karakter = mapper2[i];
						listkar.push_back(karakter);
					}
				}	
			}
			
		}
		sort(listkar.begin(), listkar.end());

		if(ans==inf){printf("You will never meet.\n");}
		else{
			printf("%d",ans);
			for(i=0;i<listkar.size();i++){printf(" %c",listkar[i]);}
			printf("\n");
		}
		mapper.clear(); mapper2.clear(); listkar.clear();
	}	
	return 0;
}