#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct a{
	int id;
	int g;
	int c;
};
struct datacantik{
	int id;
	int c;
};
struct datagemas{
	int id;
	int g;
};

int id[50010],g[50010],c[50010];

a dataorang[50010];
datagemas gemas[7];
datacantik cantik[7];
bool gcompare(a lhs, a rhs){return lhs.g > rhs.g;}
bool ccompare(a lhs, a rhs){return lhs.c > rhs.c;}
int main(){
	ios_base::sync_with_stdio(false);
	int n,tc,i,j,k,l,m,b,bil;
	map <string,int> mapper;
	map <string,int>::iterator it;
	map <int,string> mapper2;
	map <int,int> mapper3;
	map <int,int>::iterator it3;
	char kata[50010][10];
	int id1,id2,id3,id4,id5,id6;
	ll ans;
	scanf("%d",&tc);
	while(tc--){
		ans=-1;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			
			scanf("%s %d %d",kata[i],&g[i],&c[i]);
			//printf("test\n");
			mapper[(string)kata[i]]=i; mapper2[i]=(string)kata[i];

			dataorang[i].id=i; dataorang[i].g=g[i]; dataorang[i].c=c[i];
		}
		
		sort(dataorang,dataorang+n,gcompare);
		//ambil 6 terbaik
		for(i=0;i<6;i++){gemas[i].id=dataorang[i].id; gemas[i].g=dataorang[i].g;}
		sort(dataorang,dataorang+n,ccompare);
		for(i=0;i<6;i++){cantik[i].id=dataorang[i].id; cantik[i].c=dataorang[i].c;}
		/*printf("list 6 tergemas:\n");
		for(i=0;i<6;i++){
			printf("id: %d orang: %s tingkat gemas: %d\n",gemas[i].id,mapper2[gemas[i].id].data(),gemas[i].g);
		}
		printf("list 6 tercantik:\n");
		for(i=0;i<6;i++){
			printf("id: %d orang: %s tingkat cantik: %d\n",cantik[i].id,mapper2[cantik[i].id].data(),cantik[i].c);
		}*/
			//i j k data gemas... l m n data cantik
		for(i=0;i<4;i++){
			for(j=i+1;j<5;j++){
				for(k=j+1;j<6;j++){
					for(l=0;l<4;l++){
						for(m=l+1;m<5;m++){
							for(b=m+1;b<6;b++){
								bil = gemas[i].id;
								mapper3[bil]=bil;
								bil = cantik[l].id;
								it3=mapper3.find(bil);
								if(it3!=mapper3.end()){mapper3.clear();continue;}
								else{mapper3[bil]=bil;}
								bil = gemas[j].id;
								it3=mapper3.find(bil);
								if(it3!=mapper3.end()){mapper3.clear();continue;}
								else{mapper3[bil]=bil;}
								bil = cantik[m].id;
								it3=mapper3.find(bil);
								if(it3!=mapper3.end()){mapper3.clear();continue;}
								else{mapper3[bil]=bil;}
								bil = gemas[k].id;
								it3=mapper3.find(bil);
								if(it3!=mapper3.end()){mapper3.clear();continue;}
								else{mapper3[bil]=bil;}
								bil = cantik[b].id;
								it3=mapper3.find(bil);
								if(it3!=mapper3.end()){mapper3.clear();continue;}
								else{mapper3[bil]=bil;}
								//sudah lolos semua
								ll total = (gemas[i].g*gemas[j].g*gemas[k].g)+(cantik[l].c*cantik[m].c*cantik[b].c);

								if(ans < total){
									ans=total;
									id1=gemas[i].id; id2=gemas[j].id; id3=gemas[k].id;
									id4=cantik[l].id; id5=cantik[m].id; id6=cantik[b].id;

								}
								//printf("total: %lld ans: %lld\n",total,ans);
								mapper3.clear();
							}
						}
					}
				}
			}
		}
		printf("%lld\n%s %s %s\n%s %s %s\n",ans,mapper2[id1].data(),mapper2[id2].data(),mapper2[id3].data(),mapper2[id4].data(),mapper2[id5].data(),mapper2[id6].data());
		mapper.clear(); mapper2.clear();
	}
	return 0;
}
