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

struct pasangan{
	int l,r,idx;
};

const int maxn = 1e5 + 5;
pasangan pas[maxn];

bool cmp(pasangan a, pasangan b){
	if(a.l==b.l){
		return a.r < b.r;
	}
	return a.l < b.l;
}

bool isVisited[maxn];
int jawaban[maxn];

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	if(m==1){printf("%d\n",n); return 0;}
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		pas[i].l = a; pas[i].r = b; pas[i].idx = i;
	}
	memset(isVisited,false,sizeof isVisited);
	sort(pas,pas+m,cmp);
	for(i=0;i<m;i++){
		int bil1 = pas[i].l, bil2 = pas[i].r, indeks = pas[i].idx;
		if(!isVisited[bil2]){
			for(j=bil2;j>=bil1;j--){
				if(isVisited[j]){break;}
				isVisited[j] = true;
			}
		}
	}
	//menentukan banyak yang painted
	int cnt = 0;
	for(i=1;i<=n;i++){
		if(isVisited[i]){cnt++;}
	}
	for(i=0;i<m;i++){
		int bil1 = pas[i].l, bil2 = pas[i].r, indeks = pas[i].idx;
		printf("%d %d %d\n",bil1,bil2,indeks);
	}
	for(i=0;i<m;i++){
		int bil1 = pas[i].l, bil2 = pas[i].r, indeks = pas[i].idx;
		//printf("%d %d %d\n",bil1,bil2,indeks);
		//mencari banyak bilangan yang berhasil dicover dari indeks sebelum dan  atau setelahnya
		int ans = cnt-(bil2-bil1+1);

		if(i==0){
			int next1 = pas[i+1].l, next2 = pas[i+1].r;
			if(next1<=bil1){
				if(next2>=bil2){
					ans+=(bil2-bil1+1);
				}else{
					ans+=(next2-bil1+1);
				}
			}else{
				if(next2>=bil2){
					ans+=(bil2-next1+1);
				}else{
					ans+=(next2-next1+1);
				}
			}
			jawaban[indeks] = n-ans;
		}else if(i==m-1){
			int sebelum1 = pas[i-1].l, sebelum2 = pas[i-1].r;
			if(sebelum1<=bil1){
				if(sebelum2>=bil2){
					ans+=(bil2-bil1+1);
				}else{
					ans+=(sebelum2-bil1+1);
				}
			}else{
				if(sebelum2>=bil2){
					ans+=(bil2-sebelum1+1);
				}else{
					ans+=(sebelum2-sebelum1+1);
				}
			}
			jawaban[indeks] = n-ans;
		}else{
			int sebelum1 = pas[i-1].l, sebelum2 = pas[i-1].r;
			int next1 = pas[i+1].l, next2 = pas[i+1].r;
			int gabungan1 = -1, gabungan2 = -1;
			if(next1<=sebelum2){
				gabungan1 = sebelum1; gabungan2 = next2;
			}
			if(gabungan1==-1 && gabungan2==-1){
				if(sebelum1<=bil1){
					if(sebelum2>=bil2){
						ans+=(bil2-bil1+1);
						jawaban[indeks] = n-ans; continue;
					}else{
						ans+=(sebelum2-bil1+1);
						
					}
				}else{
					if(sebelum2>=bil2){
						ans+=(bil2-sebelum1+1);
						
					}else{
						ans+=(sebelum2-sebelum1+1);
					}
				}
				if(next1<=bil1){
					if(next2>=bil2){
						ans+=(bil2-bil1+1);
						jawaban[indeks] = n-ans; continue;
					}else{
						ans+=(next2-bil1+1);
					}
				}else{
					if(next2>=bil2){
						ans+=(bil2-next1+1);
					}else{
						ans+=(next2-next1+1);
					}
				}
				jawaban[indeks] = n-ans;
			}else{
				printf("masuk sini\n");
				printf("i: %d idx: %d\n",i,indeks);
				printf("gabungan1: %d gabungan2: %d\n",gabungan1,gabungan2);
				if(gabungan1<=bil1){
					printf("masuk sini kan\n");
					if(gabungan2>=bil2){
						ans+=(bil2-bil1+1);
						jawaban[indeks] = n-ans; continue;
					}else{
						printf("ans awal: %d\n",ans);
						if(gabungan1==bil1){
							ans+=(gabungan2-bil1);
						}else{
							ans+=(gabungan2-bil1+1);	
						}
						
						printf("ans jd: %d\n",ans);
					}
				}else{
					if(gabungan2>=bil2){
						ans+=(bil2-gabungan1+1);
						
					}else{
						ans+=(gabungan2-gabungan1+1);
					}
				}
				jawaban[indeks] = n-ans;
			}
			
		}

	}
	for(i=0;i<m;i++){
		printf("%d\n",jawaban[i]);
	}
	return 0;
};