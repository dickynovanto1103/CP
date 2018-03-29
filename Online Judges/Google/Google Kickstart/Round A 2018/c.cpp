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

string kata[20010];
char s[1000010], x[1000010];
int main(){
	int tc,i,j;
	int L;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		// cerr<<"Case "<<tt<<" done"<<endl;
		scanf("%d",&L);
		for(i=0;i<L;i++){
			cin>>kata[i];
		}
		ll n,a,b,c,d;
		char kar1,kar2;
		scanf("\n%c %c %lld %lld %lld %lld %lld",&kar1,&kar2,&n,&a,&b,&c,&d);
		// printf("kar1: %c kar2: %c n: %d a: %d b: %d c: %d d: %d\n",kar1,kar2,n,a,b,c,d);
		x[0] = kar1; x[1] = kar2;
		s[0] = kar1; s[1] = kar2;
		for(i=2;i<n;i++){
			ll bil1 = a*(ll)x[i-1];
			ll bil2 = b*(ll)x[i-2];
			ll bil3 = c;
			
			ll bil = (bil1+bil2+bil3) %d;
			x[i] = bil;
			// printf("bil1: %lld bil2: %lld bil3: %lld bil: %lld dict[%d]: %c, dist[%d]: %c\n",bil1,bil2,bil3,bil,i-1,dict[i-1],i-2,dict[i-2]);
			char kar = 97 + bil%26 ;
			// printf("kar: %c nilai: %d\n",kar,kar);
			s[i] = kar;
		}
		//iterasi kata satu"
		int counter[26], scounter[26];
		int cnt = 0;
		for(i=0;i<L;i++){
			memset(counter,0,sizeof counter); memset(scounter,0,sizeof scounter);
			int pjg = kata[i].length();
			// printf("kata yg diexamine: "); cout<<kata[i]<<endl;
			if(pjg > n){continue;}
			for(j=0;j<pjg;j++){
				char kar = kata[i][j] - 'a';

				counter[kar]++;
			}
			
			int idxAwal = 0, idxAkhir = 0;
			for(j=0;j<pjg;j++){
				idxAkhir = j;
				scounter[s[j]-'a']++;
			}
			
			char karakterAwal = kata[i][0];
			char karakterAkhir = kata[i][pjg-1];
			//cek dulu 26 karakter
			bool isSama = true;

			for(j=0;j<26;j++){

				if(counter[j] != scounter[j]){isSama = false;break;}
			}
			if(isSama){
				// printf("sama ketika diawal\n");
				if(karakterAwal == s[0] && karakterAkhir == s[pjg-1]){
					// printf("kehitung\n");
					cnt++; continue;	
				}
				
			}
			if(pjg==n){continue;}
			for(j=pjg;j<n;j++){

				char karAkhir = s[j] - 'a';
				scounter[karAkhir]++;
				char karAwal = s[idxAwal]-'a';
				scounter[karAwal]--;
				idxAwal++;
				
				// printf("idxAkhir: %d\n",j);
				// printf("idxAwal: %d\n", idxAwal);
				bool isSama = true;

				for(int k=0;k<26;k++){
					if(counter[k] != scounter[k]){isSama = false;break;}
				}
				if(isSama){
					if((karakterAwal == s[idxAwal] && karakterAkhir == s[j])){
						// printf("idxAwal: %d idxAkhir: %d ga masuk\n",idxAwal, j);
						cnt++; break;
					}	
					// printf("sama ketika idxAwal: %d idxAkhir: %d\n",idxAwal, j);
					
				}
			}
		}
		printf("%d\n",cnt);
		int bil = rng();
		printf("bil :%d\n",bil);
		// printf("\n");
	}
	// printf("%d\n",'p');
	return 0;
};
