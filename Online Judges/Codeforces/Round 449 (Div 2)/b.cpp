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

bool isPalindrome(int n) {
	vi a;
	int i,j;
	while(n>0){
		int bil = n%10;
		a.pb(bil);
		n/=10;
	}
	int pjg = a.size();
	for(i=0;i<pjg/2;i++){
		j = pjg-i-1;
		if(a[i]!=a[j]){return false;}
	}
	return true;
}

vector<string> a;

ll solve(string kata, int mod) {
	ll bil = 0;
	int i;
	for(i=0;i<kata.length();i++){
		bil=(((bil%mod)*(10%mod))%mod + (kata[i]-'0')%mod)%mod;
		//if(bil>mod){bil%=mod;}
	}
	return bil;
}

int main(){
	int k,p,i,j;
	for(i=2;i<100000;i+=2){
		//printf("i; %d\n",i);
		if(i>10){break;}
		int pjg = i;
		string kata = "";
		string batas="";
		
		for(j=0;j<pjg;j++){
			batas+="9";	
		}
		while(true){
			kata="";
			batas="";
			for(j=0;j<pjg;j++){
				if(j==0 || j==(pjg-1)){kata+="1";}
				else{kata+="0";}
				batas+="9";
			}
			bool done = false;
			int k,l,m,n;
			if(pjg==4){
				for(j=1;j<10;j++){
					int idx1 = 0, idx2 = pjg-1;
					kata[idx1] = j+'0';
					kata[idx2] = j+'0';
					for(k=0;k<10;k++){
						kata[idx1+1] = k+'0';
						kata[idx2-1] = k+'0';

						a.pb(kata);
						// printf("pjg: %d\n", pjg);
						// cout<<kata<<endl;

						if(kata==batas){
							done = true;
							break;
						}
					}
				}
			}else if(pjg==2){
				for(j=1;j<10;j++){
					int idx1 = 0, idx2 = pjg-1;
					kata[idx1] = j+'0';
					kata[idx2] = j+'0';
					// printf("pjg: %d\n", pjg);
					// cout<<kata<<endl;
					// cout<<"batas: "<<batas<<endl;
					a.pb(kata);
					if(kata==batas){
						done = true;
						break;
					}
				}
			}else if(pjg==6) {
				for(j=1;j<10;j++){
					int idx1 = 0, idx2 = pjg-1;
					kata[idx1] = j+'0';
					kata[idx2] = j+'0';
					for(k=0;k<10;k++){
						kata[idx1+1] = k+'0';
						kata[idx2-1] = k+'0';
						for(l=0;l<10;l++){
							kata[idx1+2] = l+'0';
							kata[idx2-2] = l+'0';
							a.pb(kata);	
							// printf("pjg: %d\n", pjg);
							// cout<<kata<<endl;
							if(kata==batas){
								done = true;
								break;
							}
						}
					}
				}
			}else if(pjg==8){
				for(j=1;j<10;j++){
					int idx1 = 0, idx2 = pjg-1;
					kata[idx1] = j+'0';
					kata[idx2] = j+'0';
					for(k=0;k<10;k++){
						kata[idx1+1] = k+'0';
						kata[idx2-1] = k+'0';
						for(l=0;l<10;l++){
							kata[idx1+2] = l+'0';
							kata[idx2-2] = l+'0';
							for(m=0;m<10;m++){
								kata[idx1+3] = m+'0';
								kata[idx2-3] = m+'0';
								a.pb(kata);	
								// printf("pjg: %d\n", pjg);
								// cout<<kata<<endl;
								if(kata==batas){
									done = true;
									break;
								}	
							}
							
						}
					}
				}
			}
			else if(pjg==10){
				for(j=1;j<10;j++){
					int idx1 = 0, idx2 = pjg-1;
					kata[idx1] = j+'0';
					kata[idx2] = j+'0';
					for(k=0;k<10;k++){
						kata[idx1+1] = k+'0';
						kata[idx2-1] = k+'0';
						for(l=0;l<10;l++){
							kata[idx1+2] = l+'0';
							kata[idx2-2] = l+'0';
							for(m=0;m<10;m++){

								kata[idx1+3] = m+'0';
								kata[idx2-3] = m+'0';
								for(int o=0;o<10;o++){
									kata[idx1+4] = o+'0';
									kata[idx2-4] = o+'0';
									a.pb(kata);	
									// printf("pjg: %d\n", pjg);
									// cout<<kata<<endl;
									if(kata==batas){
										done = true;
										break;
									}		
								}
								
							}
							
						}
					}
				}
			}
			if(done){break;}
			
		}
		//printf("i: %d\n",i);
		

	}
	string kata="";
	for(i=0;i<12;i++){
		if(i==0 || i==11){kata+="1";}
		else{kata+="0";}
	}
	a.pb(kata);
	//jawab

	scanf("%d %d",&k,&p);
	ll ans = 0;
	for(i=0;i<k;i++){
		ll jawab = solve(a[i], p);	

		//printf("jawab: %lld\n",jawab);
		ans+=jawab;
		ans%=p;
	}
	
	printf("%lld\n",ans);
	return 0;
};