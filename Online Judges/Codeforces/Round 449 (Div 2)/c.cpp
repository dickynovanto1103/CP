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

const int maxn = 100010;
//string f[55];

ll panjang[55];
ll listPanjang[55][10];
string kata1 = "What are you doing while sending \"", kata2 = "\"? Are you busy? Will you send \"", kata3 = "\"?";

char solve(int n, ll k){
	int i,j;
	for(i=0;i<5;i++){
		if(listPanjang[n][i]>=k){
			if(i%2==0){
				if(i==0){
					return kata1[k];
				}else if(i==2){
					int idx = k-listPanjang[n][i-1]-1;
					return kata2[idx];
				}
			}
			break;
		}
	}
}

int main(){
	

	int i,j;
	//f[0] = "What are you doing at the end of the world? Are you busy? Will you save us?";
	
	//printf("panjang: %d %d %d\n",kata1.length(),kata2.length(),kata3.length());
	ll panjang1 = (ll)kata1.length();
	ll panjang2 = (ll)kata2.length();
	ll panjang3 = (ll)kata3.length();
	panjang[0] = 75;
	for(i=1;i<=55;i++){
		listPanjang[i][0] = panjang1-1;
		listPanjang[i][1] = listPanjang[i][0] + panjang[i-1];
		listPanjang[i][2] = listPanjang[i][1] + panjang2;
		listPanjang[i][3] = listPanjang[i][2] + panjang[i-1];
		listPanjang[i][4] = listPanjang[i][3] + panjang3;

		panjang[i] = 68 + (2*panjang[i-1]);
		// printf("i: %d %lld\n",i,panjang[i]);
		// for(j=0;j<5;j++){
		// 	if(j){printf(" ");}
		// 	printf("%lld",listPanjang[i][j]);
		// }
		// printf("\n");

		
		//f[i] = "What are you doing while sending \""+f[i-1]+"\"? Are you busy? Will you send \""+f[i-1]+"\"?";
		
	}
	int q,n;
	ll k;
	scanf("%d",&q);
	while(q--){
		scanf("%d %lld",&n,&k);
		k--;
		if(panjang[n]<k){printf(".\n"); continue;}
		else{
			char kar = solve(n,k);
		}
	}

	// for(i=0;i<=3;i++){
	// 	printf("i: %d pjg: %d\n",i,f[i].length());
	// 	cout<<f[i]<<endl;
	// }
	return 0;
};