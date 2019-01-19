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

const ll mod = 998244353;

int main(){
	int n,i,j;
	vi listBil;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		listBil.pb(i);
	}
	vi a;
	do{

		for(i=0;i<n;i++){
			printf("%d ",listBil[i]);
			a.pb(listBil[i]);
		}

	}while(next_permutation(listBil.begin(), listBil.end()));
	printf("\n");
	int pref[100000];
	memset(pref, 0, sizeof pref);
	for(i=0;i<a.size();i++){
		pref[i] = a[i];
		if(i > 0){pref[i] += pref[i-1];}
	}
	int kiri = 0, kanan = n-1;
	int harapan = (n*(n+1))/2;
	printf("harapan: %d\n",harapan);
	int cnt = 0;
	vector<string> listString;
	for(i=0;i<a.size();i++){
		if(kiri > 0){
			if(pref[kanan] - pref[kiri-1] == harapan){
				if(kiri%n != 0){
					printf("%d %d -> ",kiri, kanan);
					string kata = "";
					for(j=kiri;j<=kanan;j++){printf("%d ",a[j]); kata += (a[j] + '0'); kata += " ";}
					listString.pb(kata);
					printf("\n");
					
				}
				cnt++;	
			}
		}else{
			if(pref[kanan] == harapan){
				if(kiri%n != 0){
					printf("%d %d\n",kiri, kanan);	
					string kata = "";
					for(j=kiri;j<=kanan;j++){printf("%d ",a[j]);kata += (a[j] + '0'); kata += " ";}
					listString.pb(kata);
					printf("\n");
					
				}
				cnt++;
				
			}
		}
		kiri++; kanan++;
		if(kanan >= a.size()){break;}
	}

	sort(listString.begin(), listString.end());
	set<string> s;
	string cur = "";
	int counter = 0;
	for(i=0;i<listString.size();i++){
		if(cur != listString[i]){
			printf("ada: %d\n", counter);
			counter = 1;
			cur = listString[i];
			cout<<listString[i]<<" ";	

		}else{
			counter++;
		}
		// cout<<listString[i]<<endl;
	}
	int fac[12];
	fac[0] = 1;
	for(i=1;i<=n;i++){
		fac[i] = i*fac[i-1];
	}
	printf("ada: %d\n",counter);
	printf("tot %d\n",cnt);

	return 0;
};