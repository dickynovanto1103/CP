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

bool isSSudahDiawalSemua(string kata, int banyakS){
	int i;
	for(i=0;i<banyakS;i++){
		if(kata[i]=='C'){return false;}
	}
	return true;
}



int main(){
	int tc,i,j;
	ll d;
	ll charge[40];
	
	string kata;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		memset(charge,0,sizeof charge);
		printf("Case #%d: ",tt);
		scanf("%lld",&d);
		cin>>kata;
		ll curCharge = 1LL;
		ll totalDamage = 0;
		int banyakS = 0;
		for(i=0;i<kata.length();i++){
			char kar = kata[i];
			if(kar=='C'){curCharge*=2LL;}
			else{
				charge[i] = curCharge;
				totalDamage += curCharge;
				banyakS++;
			}
		}

		// printf("charge awal:\n");
		// for(j=0;j<kata.length();j++){
		// 	if(j){printf(" ");}
		// 	printf("%lld",charge[j]);
		// }
		// printf("\n");
		// printf("totalDamage awal: %lld\n",totalDamage);
		if(totalDamage <= d){printf("0\n");}
		else{
			int ans = 0;
			if(banyakS>d){printf("IMPOSSIBLE\n");continue;}
			while(true){
				if(isSSudahDiawalSemua(kata, banyakS)){ //can't do no more swap
					if(totalDamage <= d){
						printf("%d\n",ans);
					}else{
						printf("IMPOSSIBLE\n"); 	
					}
					break;
				}else {
					if(totalDamage <= d){
						printf("%d\n",ans);
						break;
					}else{
						//tuker
						bool sudahSelesai = false;
						for(i=kata.length()-1; i>=1;i--){
							if(kata[i] == 'S' && kata[i-1] == 'C'){
								swap(kata[i], kata[i-1]);

								ll sekarang = charge[i];
								charge[i]/=2LL;
								ll selisih = sekarang - charge[i];
								totalDamage-=selisih;

								ans++;
								swap(charge[i], charge[i-1]);
								//tabel charge
								// printf("charge:\n");
								// for(j=0;j<kata.length();j++){
								// 	if(j){printf(" ");}
								// 	printf("%lld",charge[j]);
								// }
								// printf("\n");
								// printf("totalDamage: %lld\n",totalDamage);
								if(totalDamage <= d){
									printf("%d\n",ans);
									sudahSelesai = true;
									break;
								}

								
								break;
							}
						}
						if(sudahSelesai){break;}
					}
				}
			}
		}
	}
	return 0;
};