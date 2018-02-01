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

int a[205][205], idx, pjg;
string kata,totalkata;

void solveD(int barisawal,int barisakhir, int kolomawal, int kolomakhir, char kar){
	int i,j;
	if(idx>=pjg){return;}
	if(kar=='1'){
		for(i=barisawal; i<=barisakhir;i++){
			for(j=kolomawal;j<=kolomakhir;j++){
				a[i][j] = 1;
			}
		}
	}else if(kar=='0'){
		for(i=barisawal; i<=barisakhir;i++){
			for(j=kolomawal;j<=kolomakhir;j++){
				a[i][j] = 0;
			}
		}
	}else{
		int cntRow = barisakhir-barisawal+1;
		int cntCol = kolomakhir-kolomawal+1;
		if(cntRow==1){//pasti cntCol ga mungkin 1	
			idx++;
			solveD(barisawal,barisakhir,kolomawal,(kolomawal+kolomakhir)/2,totalkata[idx]);
			idx++;
			solveD(barisawal,barisakhir,(kolomawal+kolomakhir)/2 + 1,kolomakhir,totalkata[idx]);
		}else if(cntCol==1){
			idx++;
			solveD(barisawal,(barisawal+barisakhir)/2,kolomawal,kolomakhir,totalkata[idx]);
			idx++;
			solveD((barisawal+barisakhir)/2 + 1,barisakhir,kolomawal,kolomakhir,totalkata[idx]);
		}else{
			idx++;
			solveD(barisawal,(barisawal+barisakhir)/2,kolomawal,(kolomawal+kolomakhir)/2,totalkata[idx]);
			idx++;
			solveD(barisawal,(barisawal+barisakhir)/2,(kolomawal+kolomakhir)/2 + 1,kolomakhir,totalkata[idx]);
			idx++;
			solveD((barisawal+barisakhir)/2 + 1,barisakhir,kolomawal,(kolomawal+kolomakhir)/2,totalkata[idx]);
			idx++;
			solveD((barisawal+barisakhir)/2 + 1,barisakhir,(kolomawal+kolomakhir)/2 + 1,kolomakhir,totalkata[idx]);
			
		}
	}
}

bool isAllOne(int barisawal,int barisakhir, int kolomawal, int kolomakhir){
	int i,j;
	for(i=barisawal;i<=barisakhir;i++){
		for(j=kolomawal;j<=kolomakhir;j++){
			if(a[i][j]==0){return false;}
		}
	}
	return true;
}

bool isAllZero(int barisawal,int barisakhir, int kolomawal, int kolomakhir){
	int i,j;
	for(i=barisawal;i<=barisakhir;i++){
		for(j=kolomawal;j<=kolomakhir;j++){
			if(a[i][j]==1){return false;}
		}
	}
	return true;
}

string ans;

void solveB(int barisawal,int barisakhir, int kolomawal, int kolomakhir){
	if(isAllOne(barisawal,barisakhir,kolomawal,kolomakhir)){
		ans+='1';
	}else if(isAllZero(barisawal,barisakhir,kolomawal,kolomakhir)){
		ans+='0';
	}else{
		int cntRow = barisakhir-barisawal+1;
		int cntCol = kolomakhir-kolomawal+1;
		ans+='D';
		if(cntRow==1){//pasti cntCol ga mungkin 1	
			solveB(barisawal,barisakhir,kolomawal,(kolomawal+kolomakhir)/2);
			solveB(barisawal,barisakhir,(kolomawal+kolomakhir)/2 + 1,kolomakhir);
		}else if(cntCol==1){
			solveB(barisawal,(barisawal+barisakhir)/2,kolomawal,kolomakhir);
			solveB((barisawal+barisakhir)/2 + 1,barisakhir,kolomawal,kolomakhir);
		}else{
			solveB(barisawal,(barisawal+barisakhir)/2,kolomawal,(kolomawal+kolomakhir)/2);
			solveB(barisawal,(barisawal+barisakhir)/2,(kolomawal+kolomakhir)/2 + 1,kolomakhir);
			solveB((barisawal+barisakhir)/2 + 1,barisakhir,kolomawal,(kolomawal+kolomakhir)/2);
			solveB((barisawal+barisakhir)/2 + 1,barisakhir,(kolomawal+kolomakhir)/2 + 1,kolomakhir);
			
		}
	}
}

int banyakDigit(int a){
	int cnt = 0;
	while(a>0){a/=10; cnt++;}
	return cnt;
}

int main() {
	char kar;
	int i,j,r,c,test=1;
	while(getline(cin,kata)){
		
		if((kata.length()>1 && kata[1]==' ') || kata[0]=='#'){
			if(test>1){
				//cout<<"total kata: "<<totalkata<<endl;
				pjg = totalkata.length();
				idx = 0;
				if(kar=='D'){
					printf("B");
					int cntDigitR = banyakDigit(r);
					for(i=0;i<4-cntDigitR;i++){printf(" ");}
					printf("%d",r);
					int cntDigitC = banyakDigit(c);
					for(i=0;i<4-cntDigitC;i++){printf(" ");}
					printf("%d\n",c);

					solveD(0,r-1,0,c-1,totalkata[idx]);
					int cnt = 0;
					for(i=0;i<r;i++){
						for(j=0;j<c;j++){
							if(cnt%50==0 && cnt!=0){printf("\n");}
							printf("%d",a[i][j]); cnt++;
						}
					}
					printf("\n");
				}else{
					printf("D");
					int cntDigitR = banyakDigit(r);
					for(i=0;i<4-cntDigitR;i++){printf(" ");}
					printf("%d",r);
					int cntDigitC = banyakDigit(c);
					for(i=0;i<4-cntDigitC;i++){printf(" ");}
					printf("%d\n",c);

					int cnt = 0;
					for(i=0;i<r;i++){
						for(j=0;j<c;j++){
							a[i][j] = totalkata[cnt]-'0'; cnt++;
						}
					}
					
					ans = "";
					solveB(0,r-1,0,c-1);
					int ukuran = ans.length();
					cnt = 0;
					for(i=0;i<ukuran;i++){
						if(cnt%50==0 && cnt!=0){printf("\n");}
						printf("%c",ans[i]); cnt++;
					}
					printf("\n");
					//cout<<ans<<endl;
				}	
			}
			if(kata[0]=='#'){break;}
			kar = kata[0];
			totalkata = "";
			//cari nilai r
			int bil,arr[2];
			int cnt = 0;
			bool foundR = false;
			bil=0;
			for(i=1;i<kata.length();i++){
				if(kata[i]==' '){
					if(foundR){arr[cnt] = bil; r = bil; foundR = false; bil = 0; cnt++;}
				}else{bil*=10; bil= bil+(kata[i]-'0'); foundR = true;}
			}
			c = bil;
			//printf("r: %d c: %d\n",r,c);
		}else{
			//printf("kata yang dibaca: \n");cout<<kata<<endl;
			totalkata=totalkata+kata;
			//printf("total kata menjadi: \n");cout<<totalkata<<endl;
			test=2;
		}
	}

	return 0;
}