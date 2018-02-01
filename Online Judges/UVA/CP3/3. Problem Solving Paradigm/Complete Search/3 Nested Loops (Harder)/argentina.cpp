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

struct pas{
	string nama;
	int attack, defend;
};

bool cmp(pas a, pas b){return a.nama < b.nama;}

int main() {
	int tc,i,j,k,l,m,n,test=1;
	pas a[11];
	string att[6],deff[6];
	scanf("%d",&tc);
	while(tc--){
		for(i=0;i<10;i++){
			cin>>a[i].nama;
			scanf("%d %d",&a[i].attack,&a[i].defend);
		}
		sort(a,a+10,cmp);
		/*printf("list:\n");
		for(i=0;i<10;i++){
			cout<<a[i].nama;
			printf(" %d %d\n",a[i].attack,a[i].defend);
		}*/
		int maxAtt = -1, maxDeff = -1;
		map<string,int> mapper;
		for(i=0;i<10;i++){
			for(j=i+1;j<10;j++){
				for(k=j+1;k<10;k++){
					for(l=k+1;l<10;l++){
						for(m=l+1;m<10;m++){
							//printf("i: %d j: %d k: %d l: %d m: %d\n",i,j,k,l,m);
							int totalAttack = a[i].attack + a[j].attack + a[k].attack + a[l].attack + a[m].attack;
							int totalDeff;
							//printf("totalAttack: %d maxAtt: %d maxDeff = %d\n",totalAttack,maxAtt,maxDeff);
							if(totalAttack>maxAtt){
								maxAtt = totalAttack;
								totalDeff = 0;
								for(n=0;n<10;n++){
									if(n!=i && n!=j && n!=k && n!=l && n!=m){
										//printf("ditambahkan n: %d\n",n);
										totalDeff+=a[n].defend; 
									}
								}
								//printf("totaldeff: %d\n",totalDeff);
								maxDeff = totalDeff;

								mapper.clear();
								att[0] = a[i].nama; att[1] = a[j].nama; att[2] = a[k].nama; att[3] = a[l].nama; att[4] = a[m].nama; 
								mapper[a[i].nama] = 0; mapper[a[j].nama] = 1; mapper[a[k].nama] = 2; mapper[a[l].nama] = 3; mapper[a[m].nama] = 4;
								//printf("maxAtt: %d maxDeff = %d\n",maxAtt,maxDeff);
								/*printf("nama: \n");
								for(n=0;n<5;n++){
									if(n>0){printf(" ");}
									cout<<a[n].nama;
								}
								printf("\n");*/
								//deff[0] = a[i].nama; deff[1] = a[j].nama; deff[2] = a[k].nama; deff[3] = a[l].nama; deff[4] = a[m].nama; 
							}else if(totalAttack == maxAtt){
								//cari defendernya siapa aja..jumlahin total deff
								totalDeff = 0;
								for(n=0;n<10;n++){
									if(n!=i && n!=j && n!=k && n!=l && n!=m){
										//printf("ditambahkan n: %d\n",n);
										totalDeff+=a[n].defend; 
									}
								}
								//printf("totaldeff: %d\n",totalDeff);
								if(totalDeff > maxDeff){
									mapper.clear();
									maxDeff = totalDeff;
									att[0] = a[i].nama; att[1] = a[j].nama; att[2] = a[k].nama; att[3] = a[l].nama; att[4] = a[m].nama; 
									mapper[a[i].nama] = 0; mapper[a[j].nama] = 1; mapper[a[k].nama] = 2; mapper[a[l].nama] = 3; mapper[a[m].nama] = 4;
									/*printf("masuk total attack sama, maxAtt: %d maxDeff = %d\n",maxAtt,maxDeff);
									printf("nama: \n");
									for(n=0;n<5;n++){
										if(n>0){printf(" ");}
										cout<<a[n].nama;
									}
									printf("\n");*/
								}
							}
						}
					}
				}
			}
		}
		printf("Case %d:\n",test++);
		for(i=0;i<5;i++){

			if(i==0){printf("(");}
			else{printf(", ");}
			cout<<att[i];
			if(i==4){printf(")");}
		}
		printf("\n");
		int cnt = 0;
		for(i=0;i<10;i++){
			if(mapper.find(a[i].nama)==mapper.end()){
				deff[cnt] = a[i].nama; cnt++;
			}
		}

		for(i=0;i<5;i++){

			if(i==0){printf("(");}
			else{printf(", ");}
			cout<<deff[i];
			if(i==4){printf(")");}
		}
		printf("\n");
		mapper.clear();
	}
	return 0;
}