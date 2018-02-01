#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

string nol[7] = {"xxxxx","x...x","x...x","x...x","x...x","x...x","xxxxx"};
string satu[7] = {"....x","....x","....x","....x","....x","....x","....x"};
string dua[7] = {"xxxxx","....x","....x","xxxxx","x....","x....","xxxxx"};
string tiga[7] = {"xxxxx","....x","....x","xxxxx","....x","....x","xxxxx"};
string empat[7] = {"x...x","x...x","x...x","xxxxx","....x","....x","....x"};
string lima[7] = {"xxxxx","x....","x....","xxxxx","....x","....x","xxxxx"};
string enam[7] = {"xxxxx","x....","x....","xxxxx","x...x","x...x","xxxxx"};
string tujuh[7] = {"xxxxx","....x","....x","....x","....x","....x","....x"};
string delapan[7] = {"xxxxx","x...x","x...x","xxxxx","x...x","x...x","xxxxx"};
string sembilan[7] = {"xxxxx","x...x","x...x","xxxxx","....x","....x","xxxxx"};
string tambah[7] = {".....","..x..","..x..","xxxxx","..x..","..x..","....."};

string temp[7];
int cari(){
	int i,j;
	bool found = true;
	for(i=0;i<7;i++){
		for(j=0;j<5;j++){
			if(temp[i][j]!=nol[i][j]){
				found = false;
				break;
			}
		}
		if(!found){break;}
	}
	if(found){return 0;}
	found = true;
	for(i=0;i<7;i++){
		for(j=0;j<5;j++){
			if(temp[i][j]!=satu[i][j]){
				found = false;
				break;
			}
		}
		if(!found){break;}
	}
	if(found){return 1;}
	found = true;
	for(i=0;i<7;i++){
		for(j=0;j<5;j++){
			if(temp[i][j]!=dua[i][j]){
				found = false;
				break;
			}
		}
		if(!found){break;}
	}
	if(found){return 2;}
	found = true;
	for(i=0;i<7;i++){
		for(j=0;j<5;j++){
			if(temp[i][j]!=tiga[i][j]){
				found = false;
				break;
			}
		}
		if(!found){break;}
	}
	if(found){return 3;}
	found = true;
	for(i=0;i<7;i++){
		for(j=0;j<5;j++){
			if(temp[i][j]!=empat[i][j]){
				found = false;
				break;
			}
		}
		if(!found){break;}
	}
	if(found){return 4;}
	found = true;
	for(i=0;i<7;i++){
		for(j=0;j<5;j++){
			if(temp[i][j]!=lima[i][j]){
				found = false;
				break;
			}
		}
		if(!found){break;}
	}
	if(found){return 5;}
	found = true;
	for(i=0;i<7;i++){
		for(j=0;j<5;j++){
			if(temp[i][j]!=enam[i][j]){
				found = false;
				break;
			}
		}
		if(!found){break;}
	}
	if(found){return 6;}
	found = true;
	for(i=0;i<7;i++){
		for(j=0;j<5;j++){
			if(temp[i][j]!=tujuh[i][j]){
				found = false;
				break;
			}
		}
		if(!found){break;}
	}
	if(found){return 7;}
	found = true;
	for(i=0;i<7;i++){
		for(j=0;j<5;j++){
			if(temp[i][j]!=delapan[i][j]){
				found = false;
				break;
			}
		}
		if(!found){break;}
	}
	if(found){return 8;}
	found = true;
	for(i=0;i<7;i++){
		for(j=0;j<5;j++){
			if(temp[i][j]!=sembilan[i][j]){
				found = false;
				break;
			}
		}
		if(!found){break;}
	}
	if(found){return 9;}
	found = true;
	for(i=0;i<7;i++){
		for(j=0;j<5;j++){
			if(temp[i][j]!=tambah[i][j]){
				found = false;
				break;
			}
		}
		if(!found){break;}
	}
	if(found){return 10;}
}

int main(){
	string kata[10];

	int i,j,k;
	for(i=0;i<7;i++){cin>>kata[i];}
	string ans[10];
	int pjg = kata[0].length();
	int idx = 0;
	int bil1 = 0, bil2 = 0;
	bool sudahTambah = false;
	while(idx<pjg){
		for(i=0;i<7;i++){
			temp[i] = kata[i].substr(idx,5);
			
		}
		idx+=5; idx++;
		//if(idx>=pjg){break;}
		//printf("\n");
		/*printf("temp\n");
		for(i=0;i<7;i++){
			for(j=0;j<5;j++){
				printf("%c",temp[i][j]);
			}
			printf("\n");
		}*/
		int nilai = cari();
		/*printf("nilai: %d\n",nilai);
		printf("idx: %d pjg: %d\n",idx,pjg);
		printf("temp\n");
		for(i=0;i<7;i++){
			for(j=0;j<5;j++){
				printf("%c",temp[i][j]);
			}
			printf("\n");
		}*/
		if(nilai==10){sudahTambah = true; continue;}
		if(sudahTambah){
			bil2*=10; bil2+=nilai;
		}else{
			bil1*=10; bil1+=nilai;	
		}
		
	}
	ll jumlah = (ll)bil1 + (ll)bil2;
	//printf("bil1: %d bil2: %d\n",bil1,bil2);
	//printf("jumlah; %d\n",jumlah);
	vi listAngka;
	if(jumlah==0){listAngka.pb(0);}

	while(jumlah>0){
		int angka = jumlah%10;
		jumlah/=10;
		listAngka.pb(angka);
	}
	reverse(listAngka.begin(),listAngka.end());

	for(i=0;i<7;i++){
	
		ans[i] = ".............................................................................................................................";
	
	}
	//printf("test\n");
	idx = 0;
	for(i=0;i<listAngka.size();i++){
		int angka = listAngka[i];
		if(angka==0){
			for(j=0;j<7;j++){
				for(k=0;k<5;k++){
					ans[j][idx+k] = nol[j][k];
				}
			}
			idx+=6;
		}else if(angka==1){
			for(j=0;j<7;j++){
				for(k=0;k<5;k++){
					ans[j][idx+k] = satu[j][k];
				}
			}
			idx+=6;
		}else if(angka==2){
			for(j=0;j<7;j++){
				for(k=0;k<5;k++){
					ans[j][idx+k] = dua[j][k];
				}
			}
			idx+=6;
		}else if(angka==3){
			for(j=0;j<7;j++){
				for(k=0;k<5;k++){
					ans[j][idx+k] = tiga[j][k];
				}
			}
			idx+=6;
		}else if(angka==4){
			for(j=0;j<7;j++){
				for(k=0;k<5;k++){
					ans[j][idx+k] = empat[j][k];
				}
			}
			idx+=6;
		}else if(angka==5){
			for(j=0;j<7;j++){
				for(k=0;k<5;k++){
					ans[j][idx+k] = lima[j][k];
				}
			}
			idx+=6;
		}else if(angka==6){
			for(j=0;j<7;j++){
				for(k=0;k<5;k++){
					ans[j][idx+k] = enam[j][k];
				}
			}
			idx+=6;
		}else if(angka==7){
			for(j=0;j<7;j++){
				for(k=0;k<5;k++){
					ans[j][idx+k] = tujuh[j][k];
				}
			}
			idx+=6;
		}else if(angka==8){
			for(j=0;j<7;j++){
				for(k=0;k<5;k++){
					ans[j][idx+k] = delapan[j][k];
				}
			}
			idx+=6;
		}else if(angka==9){
			for(j=0;j<7;j++){
				for(k=0;k<5;k++){
					ans[j][idx+k] = sembilan[j][k];
				}
			}
			idx+=6;
		}
		//printf("idx: %d\n",idx);
	}
	for(i=0;i<7;i++){
		for(j=0;j<idx-1;j++){
			printf("%c",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
};