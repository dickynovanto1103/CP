#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isValid(string kata){
	int i;
	int counterVokal =0, counterKonsonan = 0;
	for(i=0;i<kata.length();i++){
		if(kata[i]=='a' || kata[i]=='i'|| kata[i]=='u'|| kata[i]=='e'|| kata[i]=='o'){counterVokal++;}
		else{counterKonsonan++;}
	}
	return (counterKonsonan>0 && counterVokal>0);
}

int main() {
	int tc,n,i,j,k,l;
	string listKata[50];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		set<ii> s;
		for(i=0;i<n;i++){cin>>listKata[i];}
		for(i=0;i<n;i++){
			string kata = listKata[i];
			for(j=0;j<kata.length()-1;j++){
				int idxAwal = j;
				for(k=1;k<=4;k++){//banyak kata
					//printf("idxawal: %d + %d -1: %d n: %d\n",n);
					if(idxAwal+k-1<kata.length()){
						string panggilan = kata.substr(idxAwal,k);
						//printf("panggilan: "); cout<<panggilan<<endl;
						if(isValid(panggilan)){
							//printf("valid: \n");
							//cek selain i
							for(l=i+1;l<n;l++){
								string kata2 = listKata[l];
								if(kata2.find(panggilan)!=string::npos){
									//printf("cocok dengan kata2: "); cout<<kata2<<endl;
									//if(s.count(ii(i,l))){continue;}
									s.insert(ii(i,l));
								}
							}
						}
					}
					else{break;}
				}	
			}
			
		}
		printf("%d\n",s.size());
	}
	return 0;
}