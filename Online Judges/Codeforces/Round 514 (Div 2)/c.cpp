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

bool isVisited[1000010];

int main(){
	int n;
	scanf("%d",&n);
	
	if(n == 1){printf("1\n");}
	else if(n==2){printf("1 2\n");}
	else if(n==3){printf("1 1 3\n");}
	else{
		memset(isVisited, false, sizeof isVisited);
		int kali = 2;
		int bil = 1;
		vi ans;
		int sisa = n;
		vi bilSisa;
		vi kandidatJawaban1, kandidatJawaban2;
		while(bil <= n){
			// printf("bil: %d\n",bil);
			if(isVisited[bil]){bil++; continue;}
			vi ansTambahan;
			vi harusnya;
			for(int i=bil;i<=n;i+=kali){
				if(isVisited[i]){continue;}
				if(sisa <= 3){
					bilSisa.pb(i);
					isVisited[i] = true;
					kandidatJawaban1.pb(bil);
					continue;
				}
				isVisited[i] = true;
				// printf("i: %d\n",i);
				printf("%d ",bil);
				sisa--;
				// ans.pb(bil);
			}

			kali*=2;
			bil++;
			if(bil > n){break;}
		}
		sort(bilSisa.begin(),bilSisa.end());

		if(bilSisa.size() <= 3){
			for(int i=0;i<bilSisa.size();i++){
				// printf("bilSisa: %d\n",bilSisa[i]);
				int gcd = 0;
				for(int j=i;j<bilSisa.size();j++){
					gcd = __gcd(gcd, bilSisa[j]);
				}
				kandidatJawaban2.pb(gcd);
				// printf("%d ",gcd);
			}
		}
		bool pilih1 = true;
		int i,j;
		for(i=0;i<kandidatJawaban1.size();i++){
			if(kandidatJawaban1[i] > kandidatJawaban2[i]){
				pilih1 = true;
				break;
			}else if(kandidatJawaban1[i] < kandidatJawaban2[i]){
				pilih1 = false;
				break;
			}
		}
		if(pilih1){
			for(i=0;i<kandidatJawaban1.size();i++){
				printf("%d ",kandidatJawaban1[i]);
			}
		}else{
			for(i=0;i<kandidatJawaban2.size();i++){
				printf("%d ",kandidatJawaban2[i]);
			}
		}
		printf("\n");
	}
	
	return 0;
};
