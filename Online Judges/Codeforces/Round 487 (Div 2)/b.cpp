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

int main(){
	int n,p,i,j;
	string kata;
	scanf("%d %d",&n,&p);
	cin>>kata;
	vi listIdxTitik;
	for(i=0;i<n;i++){
		char kar = kata[i];
		if(kar == '.'){listIdxTitik.pb(i);}
	}
	int isSama = true;
	for(i=0;i<p;i++){
		char karAwal = kata[i];
		set<char> s;
		s.insert(karAwal);
		int cnt = 0;
		for(j=i;j<n;j+=p){
			s.insert(kata[j]);
			cnt++;
		}
		if(s.size()==1){
			if(*s.begin() == '.'){
				if(cnt>1){
					isSama = false;
					char sebelum = '0';
					for(j=i;j<n;j+=p){
						if(kata[j] == '.'){
							if(sebelum=='0'){
								kata[j] = '1';
								// printf("kata[%d] jd: %c\n",j,kata[j]);
								sebelum = kata[j];
							}else{
								kata[j] = '0';
								// printf("kata[%d] jd: %c\n",j,kata[j]);
								sebelum = kata[j];
							}
							
						}
					}
					break;
				}
			}
		}else{
			if(s.count('1') && s.count('0')){

			}else{
				if(s.count('1') && s.count('.')){
					for(j=i;j<n;j+=p){
						if(kata[j] == '.'){kata[j] = '0';}
					}
				}else if(s.count('.') && s.count('0')){
					for(j=i;j<n;j+=p){
						if(kata[j] == '.'){kata[j] = '1';}
					}
				}
			}
			isSama = false;
			break;
		}
	}

	if(!isSama){
		// printf("masuk sini\n");
		// printf("n: %d\n",n);
		for(i=0;i<n;i++){
			if(kata[i]=='.'){kata[i] = '1';}
			printf("%c",kata[i]);
		}
		printf("\n");
		
	}else{
		printf("No\n");
	}
	return 0;
};