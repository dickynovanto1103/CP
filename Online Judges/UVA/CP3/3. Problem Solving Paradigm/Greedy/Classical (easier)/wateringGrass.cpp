#include <bits/stdc++.h>

using namespace std;
#define eps 1e-9
typedef long long ll;
struct data{
	double l, r;
};

bool acompare(data a, data b){return a.l < b.l;}
bool bcompare(data a, data b){return a.r > b.r;}
int cmp(const void *i, const void *j){
	data *a,*b;
	a = (data *)i; b = (data *)j;
	return a->l < b->l ? -1:1;
}
data pasangan[10010];

void urutkan(int n){
	sort(pasangan,pasangan+n,acompare);
	int idx = 0; double curnilai = pasangan[0].l;
	for(int i=1;i<n;i++){	
		if(pasangan[i].l > pasangan[idx].l){sort(pasangan+idx,pasangan+i,bcompare); idx = i; curnilai = pasangan[i].l;}
	}
	sort(pasangan+idx,pasangan+n,bcompare);
}


int main(){
	int n,i,j;
	double pjg, w;
	while(scanf("%d %lf %lf",&n,&pjg,&w)!=EOF){
		//printf("n: %d pjg: %lf w: %lf\n",n,pjg,w);
		double pos,rad;
		int j = 0;
		for(i=0;i<n;i++){
			scanf("%lf %lf",&pos,&rad);
			//printf("pos: %lf rad: %lf\n",pos,rad);
			if(rad > w/2.0){
				double bataskiri = pos - sqrt(rad*rad - w*w/4.0);
				double bataskanan = pos + sqrt(rad*rad - w*w/4.0);
				pasangan[j].l = bataskiri; pasangan[j].r = bataskanan;
				//printf("i: %d bataskiri: %lf bataskanan: %lf\n",i,bataskiri,bataskanan);
				j++;
			}
		}
		int cnt = j;
		urutkan(cnt);
		//qsort(pasangan,cnt,sizeof(data),cmp);
		/*printf("akhir:\n");
		for(i=0;i<cnt;i++){
			printf("%lf %lf\n",pasangan[i].l,pasangan[i].r);
		}*/
		
		int ans, ch=0, flag = 0;
		//bool foundSalah = false;
		double bataskanan = 0;
		bool adaSprinkleTerpakai;
		double temp;
		//printf("cnt: %d\n",cnt);
		for(i=0 , j=0 ;i<cnt;i++){
			//printf("butuh idx ke %d\n",i);
			//bataskiri = pasangan[i].l, bataskanan = pasangan[i].r;
			adaSprinkleTerpakai = false;
			temp = bataskanan;
			while(j<cnt && pasangan[j].l <= bataskanan ){
				if(pasangan[j].r > temp){
					temp = pasangan[j].r;
					adaSprinkleTerpakai = true;
					//ch = j;
				}
				j++;
			}
			if(temp>=pjg){
				//ans = i+1;
				printf("%d\n",i+1);
				flag = 1;
				//foundSalah = false;
				break;
			}

			if(!adaSprinkleTerpakai){break;}
			

			
			//double kiri = pasangan[j].l;
			//if(kiri > bataskanan){foundSalah = true; break;}
			bataskanan = temp;
		}
		//if(bataskanan < pjg){foundSalah =true;}
		if(!flag){printf("-1\n");}
		//else{printf("%d\n",ans);}
		
	}
	

	
	

	return 0;
}
