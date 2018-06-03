#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;


const int maxn = 5e5 + 50;
int a[maxn], pre[maxn];

int main(){
	string kata;
	getline(cin,kata);
	int pjg1,pjg2,i,j;
	scanf("%d %d",&pjg1,&pjg2);
	int pjg = kata.length();
	int cnt = 0;
	int curPjg = 0;
	for(i=0;i<pjg;i++){
		curPjg++;
		// printf("i: %d\n", i);
		if(kata[i] == ' '){
			a[cnt++] = curPjg;
			curPjg = 0;
		}
	}
	a[cnt++] = curPjg+1;


	for(i=0;i<cnt;i++){
		// if(i){printf(" ");}
		// printf("%d",a[i]);
		if(i==0){pre[i] = a[i];}
		else{pre[i] = pre[i-1] + a[i];}
		// printf("(%d)",pre[i]);
	}
	// printf("\n");

	j = 0;
	for(i=pjg1;i<=pjg2;i++){
		int sum = 0;
		while(j<cnt) {
			int awal = a[j];
			sum+=awal;
			// printf("setelah ditambah %d sum jd: %d\n",awal,sum);
			int indeksAwal = pre[j] - a[j];
			int maksIndeksAkhir = indeksAwal + i+1;

			int indeks = upper_bound(pre,pre+cnt,maksIndeksAkhir) - pre;
			// printf("indeksAwal: %d maksIndeksAkhir: %d indeks: %d\n", indeksAwal, maksIndeksAkhir, indeks);
			if(indeks == cnt){break;}
			j = indeks;
			
		}
		// for(j=0;j<cnt;j++){
		// 	if((sisa-a[j]) >=-1){
		// 		if(awal == -1){awal = a[j];}
		// 		sisa-=a[j];
		// 	}else{//udah ga cukup
		// 		j--; sisa = panjangDiharapkan;
		// 		sum+=awal;
		// 		// printf("sum ditambah %d jd: %d\n",awal,sum);
		// 		awal = -1;
		// 	}
		// }

		// if(awal!=-1){
		// 	sum+=awal;
		// 	printf("akhir sum ditambah %d jd: %d\n",awal,sum);
		// }	
		printf("%d\n",sum-1);
		j = 0;
	}
	
	// printf("\n");
	return 0;
};