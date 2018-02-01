#include <bits/stdc++.h>

using namespace std;

int m1[32][32],m2[32][32];
int i,j;
void quad(string kata, int brsAwal,int brsAkhir,int kolAwal,int kolAkhir, int kode){
	if(i==kata.length()){return;}
	//printf("kata[%d] = %c\n", i,kata[i]);
	if(kata[i]=='p'){//bagi 4
		//printf("%d %d %d %d\n",brsAwal,brsAkhir,kolAwal,kolAkhir);
		//printf("baris dari %d sampe %d dan kol: %d sampe %d\n",brsAwal,(brsAwal+brsAkhir)/2,(kolAkhir+kolAwal)/2+1,kolAkhir);
		i++;
		quad(kata,brsAwal,(brsAwal+brsAkhir)/2,(kolAkhir+kolAwal)/2+1,kolAkhir,kode);

		//printf("baris dari %d sampe %d dan kol: %d sampe %d\n",brsAwal,(brsAwal+brsAkhir)/2,kolAwal,(kolAwal+kolAkhir)/2);
		i++;
		quad(kata,brsAwal,(brsAwal+brsAkhir)/2,kolAwal,(kolAwal+kolAkhir)/2,kode);
		i++;
		//printf("baris dari %d sampe %d dan kol: %d sampe %d\n",(brsAwal+brsAkhir)/2+1,brsAkhir,kolAwal,(kolAwal+kolAkhir)/2);
		quad(kata,(brsAwal+brsAkhir)/2+1,brsAkhir,kolAwal,(kolAwal+kolAkhir)/2,kode);
		//printf("baris dari %d sampe %d dan kol: %d sampe %d\n",(brsAwal+brsAkhir)/2+1,brsAkhir,(kolAwal+kolAkhir)/2+1,kolAkhir);
		i++;
		quad(kata,(brsAwal+brsAkhir)/2+1,brsAkhir,(kolAwal+kolAkhir)/2+1,kolAkhir,kode);
	}else if(kata[i]=='f'){
		/*printf("terdeteksi f di indeks: %d kata: %c\n",i,kata[i]);
		printf("menghitamkan %d %d %d %d\n",brsAwal,brsAkhir,kolAwal,kolAkhir);
		printf("di kode %d\n",kode);*/
		for(int idxBrs=brsAwal;idxBrs<=brsAkhir;idxBrs++){
			for(int idxKol=kolAwal;idxKol<=kolAkhir;idxKol++){

				if(kode==1){

					m1[idxBrs][idxKol] = 1;
				}else{
					m2[idxBrs][idxKol] = 1;
				}
			}
		}
	}
}

int main(){
	int tc,n,j;
	string kata,kata2;

	scanf("%d",&tc);
	for(int tt=0;tt<tc;tt++){

		if(tt>0){
			for(i=0;i<32;i++){
				for(j=0;j<32;j++){m1[i][j]=0; m2[i][j]=0;}
			}
		}
		cin>>kata>>kata2;
		//cout<<"kata: "<<kata<<" kata2: "<<kata2<<endl;
		i=0;
		quad(kata,0,31,0,31,1);//dpt m1
		/*printf("m1:\n");
		for(i=0;i<32;i++){
			for(j=0;j<32;j++){
				printf("%d",m1[i][j]);
			}
			printf("\n");
		*/
		i=0;
		quad(kata2,0,31,0,31,2);//dpt m2

		/*printf("m2:\n");
		for(i=0;i<32;i++){
			for(j=0;j<32;j++){
				printf("%d",m2[i][j]);
			}
			printf("\n");
		}*/
		int ans=0;
		for(i=0;i<32;i++){
			for(j=0;j<32;j++){
				if(m1[i][j]==1 || m2[i][j]==1){ans++;}
			}
		}

		printf("There are %d black pixels.\n",ans);
	}
	return 0;
}