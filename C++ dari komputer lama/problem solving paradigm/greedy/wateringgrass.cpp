#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;
struct data{
	double awal;
	double akhir;
	int i;
};
bool acompare(data lhs, data rhs){return lhs.awal < rhs.awal;}
bool bcompare(data lhs, data rhs){return lhs.akhir > rhs.akhir;}
data sp[10010];
int main(){
	int n,i,j,l,w;
	double a,b;
	
	double dx;
	
	while(scanf("%d %d %d",&n,&l,&w)==3){
		for(i=0;i<n;i++){
			scanf("%lf %lf",&a,&b);
			if(b>w/2.0){
				sp[i].awal = (double)a-sqrt(b*b - w*w/4.0); sp[i].akhir = (double)a+sqrt(b*b - w*w/4.0); sp[i].i=i;
			}
			
		}
		sort(sp,sp+n,acompare);
		
		double awal,akhir;
		int idx=0;
		awal = sp[0].awal;
		for(i=0;i<n;i++){
			if(sp[i].awal != awal){sort(sp+idx,sp+i,bcompare); idx=i; awal = sp[idx].awal;}
		}
		sort(sp+idx,sp+n,bcompare);
		
		
		double bataskiri=0,bataskanan=0;
		long long ans=0;
		for(i=0;i<n;i=j){
			if(sp[i].awal > bataskanan) break; // ada lubang lgsg keluar
			for(j=i+1;j<n && sp[j].awal <= bataskanan;j++){
				if(sp[i].akhir < sp[j].akhir){i=j;}
			}
			ans++;
			bataskanan = sp[i].akhir;
			if(bataskanan >= (double)l){break;}
		}
		if(bataskanan>= (double)l){printf("%lld\n",ans);}
		else{printf("-1\n");}
		
	}
	return 0;
}
/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
    double l, r;
} DD;
int cmp(const void *i, const void *j) {
    DD *a, *b;
    a = (DD *)i, b = (DD *)j;
    return a->l < b->l ? -1 : 1;
}
int main() {
    int n, l, w;
    double x, r;
    int i, j;
    while(scanf("%d %d %d", &n, &l, &w) == 3) {
        int m = 0;
        DD D[10000];
        for(i = 0; i < n; i++) {
            scanf("%lf %lf", &x, &r);
            if(r > w/2.0) {
                double ll = x - sqrt(r*r - w*w/4.0);
                double rr = x + sqrt(r*r - w*w/4.0);
                D[m].l = ll, D[m].r = rr;
                m++;
            }
        }
        qsort(D, m, sizeof(DD), cmp);
        int ch, flag = 0;
        double right = 0;
        for(i = 0, j = 0; i < m; i++) {
            double tmp = right;
            ch = -1;
            while(j < m && D[j].l <= right) {
                if(D[j].r > tmp) {
                    tmp = D[j].r;
                    ch = j;
                }
                j++;
            }
            if(tmp >= l) {
                printf("%d\n", i+1);
                flag = 1;
                break;
            }
            if(ch == -1)
                break;
            right = tmp;
        }
        if(!flag)    puts("-1");
    }
    return 0;
}*/