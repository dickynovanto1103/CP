#include <bits/stdc++.h>

using namespace std;

int prime[1010];

void sieve(int bil){
	int i,j;
	prime[1]=false;
	for(i=2;i*i<=bil;i++){
		if(prime[i]){
			for(j=i+i;j<=bil;j+=i){prime[j]=false;}
		}
	}
}

vector <int> a;

int main(){
	int tc,i,x,y,z,bil,j;
	string kata;
	bool found;

	memset(prime,true,sizeof prime);
	sieve(1000);
	for(i=1;i<=1000;i++){
		if(prime[i]){a.push_back(i);}
	}
	//printf("cnt: %d, sizeof a: %d\n",cnt,a.size());
	scanf("%d",&tc);
	while(tc--){
		cin>>kata;
		found=false;
		for(i=a.size()-1;i>=0;i--){
			if(a[i]>99){
				bil=a[i];
				z=bil%10; bil/=10; y=bil%10; bil/=10; x=bil%10;
				//string search
				j=0;
				while(kata[j]-'0'!=x && j < kata.length()){j++;}
				if(j<kata.length()){found=true;}
				if(found){
					j++;
					found=false;
					while(kata[j]-'0'!=y && j < kata.length()){j++;}
					if(j<kata.length()){found=true;}
					if(found){
						j++;
						found=false;
						while(kata[j]-'0'!=z && j < kata.length()){j++;}
						if(j<kata.length()){found=true;}
						if(found){break;}
					}
				}
					
				
			}else if(a[i]>9){
				bil=a[i];
				y=bil%10; bil/=10; x=bil%10;
				j=0;
				while(kata[j]-'0'!=x && j < kata.length()){j++;}
				if(j<kata.length()){found=true;}
				if(found){
					j++;
					found=false;
					while(kata[j]-'0'!=y && j < kata.length()){j++;}
					if(j<kata.length()){found=true;}
					if(found){
						break;
					}
				}
			}else{
				x=a[i];
				j=0;
				while(kata[j]-'0'!=x && j < kata.length()){j++;}
				if(j<kata.length()){found=true;}
				if(found){
					break;
				}
			}

		}
		if(!found){printf("-1\n");}
		else{printf("%d\n",a[i]);}
	}
	return 0;
}
