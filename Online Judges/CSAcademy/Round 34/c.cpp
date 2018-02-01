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

string toBase2(int bil){
	string kata = "", kata2 = "";
	while(bil>0){
		int angka = bil%2;
		bil/=2;
		kata+=angka+'0';
	}

	if(kata==""){kata="0";}
	int n = kata.length();
	for(int i=0;i<n;i++){kata2 += kata[n-i-1];}
	return kata2;
}

int main() {
	int n,i,j,k,a[100010], bit[35];
	scanf("%d",&n);
	int bil = 0, makspjg = 0;
	for(i=0;i<34;i++){bit[i]=0;}
	for(i=0;i<n;i++){
		scanf("%d",&a[i]); 
		bil|=a[i];
		string kata = toBase2(a[i]);
		int pjg = kata.length();
		makspjg = max(makspjg, pjg);
		//cout<<kata<<endl;
		for(j=0;j<pjg;j++){if(kata[j]=='1'){bit[pjg-j-1]++;}}
		
	}
	int sum;
	/*printf("bit:\n");
	for(i=0;i<makspjg;i++){
		if(i){printf(" ");}
		printf("%d",bit[i]);
	}
	printf("\n");
	printf("sum: %d\n",sum);*/
	i=0;j=n-1;
	bool gaBsDikurangin = false;
	while(i<=j && !gaBsDikurangin){
		string a1 = toBase2(a[i]);
		int pjg = a1.length();
		for(k=0;k<pjg;k++){if(a1[k]=='1'){bit[pjg-k-1]--;}}
		sum = 0;
		for(k=0;k<makspjg;k++){
			if(bit[k]>0){sum+=(1<<k);}
		}

		int kurangkiri = sum, kurangkanan;
		if(bil==kurangkiri){i++;}
		else{
			//kembalikan bit seperti semula
			for(k=0;k<pjg;k++){if(a1[k]=='1'){bit[pjg-k-1]++;}}
			//hitung bit a2
			string a2 = toBase2(a[j]);
			int pjg2 = a2.length();
			for(k=0;k<pjg2;k++){if(a2[k]=='1'){bit[pjg2-k-1]--;}}
			sum = 0;
			for(k=0;k<makspjg;k++){
				if(bit[k]>0){sum+=(1<<k);}
			}
			kurangkanan = sum;
			if(bil==kurangkanan){j--;}
			else{gaBsDikurangin = true; break;}
		}
		
	}
	printf("bil: %d\n",bil);
	if(bil==0){printf("1\n");}
	else{printf("%d\n",j-i+1);}
	
	return 0;
}