#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vi primeList;
bool prime[100010];
void sieve(int n){
	int i,j;
	memset(prime,true,sizeof prime);
	for(i=2;i*i<=n;i++){
		if(prime[i]){
			for(j=i+i;j<=n;j+=i){
				prime[j] = false;
			}
			//primeList.push_back(i);
		}
		
	}

	for(i=2;i<=n;i++){
		if(prime[i]){
			//printf("prime: %d\n",i);
			primeList.push_back(i);
		}
	}
	//printf("n: %d\n",n);
}

int main(){
	
	sieve(100000);
	int i,j, ukuran;
	vi ans;
	ukuran = primeList.size();
	/*for(i=0;i<ukuran;i++){
		printf("%d\n",primeList[i]);
	}*/
	for(i=4;i<=100000;i++){
		if(!prime[i]){
			//cek berapa faktornya
			int bil = i;
			int cnt = 0;
			for(j=0;j<ukuran;j++){
				if(bil%primeList[j]==0){
					cnt++;
					if(cnt==3){ans.push_back(bil); break;}
				}
			}
			if(ans.size()==1000){break;}
		}
	}
	int tc,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n); n--;
		printf("%d\n",ans[n]);
	}

	return 0;
}