#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define negatif 0
#define positif 1
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
	int tc,i,j,n;
	scanf("%d",&tc);
	string kata;

	int status[256];
	while(tc--){
		string ans = "mungkin";
		memset(status,-1,sizeof status);
		cin>>kata;
		n = kata.length();
		for(i=0;i<n;i++){
			if(kata[i]=='^'){continue;}
			
			if(kata[i]=='~'){
				char kar = kata[i+1];
				// printf("karSelanjutnya: %c\n",kar);
				if(kata[i+1]>=97 && kata[i+1]<=122){
					if(status[kar]==positif){
						ans = "salah";break;
					}
					status[kar] = negatif;
					

				}else{
					if(kar=='B'){ans = "salah"; break;}
					else{ans = "benar";}

				}
				i++;
			}else{
				char kar = kata[i];
			
				if(kar>=97 && kar<=122){
					if(status[kar]==negatif){//mau di positif ternyata udah negatif dulu
						ans = "salah"; break;
					}
					status[kar] = positif;
					i++;
				}else{
					if(kar=='B'){ans = "benar";}
					else{ans="salah"; break;}
				}
			}
		}

		if(ans=="benar" || ans=="mungkin"){
			//cek dari array status
			for(i=97;i<=122;i++){
				if(status[i]!=-1){
					ans = "mungkin"; break;
				}
			}
		}else{
			cout<<ans<<endl; continue;
		}
		cout<<ans<<endl;
	}
	return 0;
};