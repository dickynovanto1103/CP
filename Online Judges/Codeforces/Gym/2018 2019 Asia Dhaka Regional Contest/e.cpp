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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	while(scanf("%d\n",&n) ,n) {
		// printf("n: %d\n",n);
		int point = 0;
		for(i=0;i<n;i++){
			char shift;
			int h1,m1,s1,h2,m2,s2;
			scanf("%c:%d:%d:%d:%d:%d:%d\n",&shift,&h1,&m1,&s1,&h2,&m2,&s2);
			// printf("%c:%d:%d:%d:%d:%d:%d\n",shift,h1,m1,s1,h2,m2,s2);
			int detik1 = h1*3600 + m1*60 + s1, detik2 = h2*3600 + m2*60 + s2;
			int selisih = detik2 - detik1;
			int detikMin;
			int minWaktu;
			int detikMinBoongan = 8*3600 + 30*60;
			if(shift == 'D'){
				detikMin = 9*3600 + 30*60;
				minWaktu = 8*3600;
				if(detik1 < detikMinBoongan){
					detik1 = detikMinBoongan;
				}
				if(detik1 > detikMin){
					// printf("detik1: %d detikMin: %d\n",detik1, detikMin);
					// printf("halo1\n");
					point++; continue;
				}
			}else{
				detikMin = 12*3600 + 30*60;
				minWaktu = 9*3600;

				if(detik1 < detikMinBoongan){
					detik1 = detikMinBoongan;
				}
				if(detik1 > detikMin){
					// printf("detik1: %d detikMin: %d\n",detik1, detikMin);
					// printf("halo2\n");
					point++; continue;
				}
			}
			selisih = detik2 - detik1;
			if(selisih < minWaktu){
				// printf("halo3\n");
				point++;
			}


		}
		if(point == 0){printf("All OK\n");}
		else if(point == 1){printf("1 Point(s) Deducted\n");}
		else if(point == 2){printf("2 Point(s) Deducted\n");}
		else if(point == 3){printf("3 Point(s) Deducted\n");}
		else{printf("Issue Show Cause Letter\n");}
	}
	return 0;
};