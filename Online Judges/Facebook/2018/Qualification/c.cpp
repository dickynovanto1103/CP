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

bool foundAns;

bool isSama(string& kata1, string& kata2){
	int pjg1 = kata1.length(), pjg2 = kata2.length();
	int pjg = min(pjg1,pjg2);
	for(int i=0;i<pjg;i++){
		if(kata1[i] != kata2[i]){
			if(i!=0){foundAns = true;}
			return false;
		}
	}
	return true;
}

int main(){
	int tc,i,j;

	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		string kata;
		cin>>kata;
		int pjg = kata.length();
		string pattern, kataDicocokkan;
		foundAns = false;
		bool can = true;
		for(i=1;i<pjg;i++){
			pattern = kata.substr(0,i);
			j = i;
			bool isRepeated = true;
			while(j<=pjg){
				int pjgSisa = pjg - j;
				if(pjgSisa==0){
					isRepeated = false;
					break;
				}
				if(pjgSisa<=i){
					kataDicocokkan = kata.substr(j,pjgSisa);
				}else{
					kataDicocokkan = kata.substr(j,i);
				}
				// printf("i: %d j: %d\n",i,j);
				// cout<<"pattern: "<<pattern<<" kataDicocokkan: "<<kataDicocokkan<<endl;
				if(!isSama(pattern, kataDicocokkan)){
					isRepeated = false;
					if(foundAns){
						// printf("j: %d\n",j);
						for(int k=0;k<j;k++){
							printf("%c",kata[k]);
						}
						cout<<kata<<endl;
						break;
					}
					break;
				}

				j+=i;
			}
			if(foundAns){break;}
			if(isRepeated){
				// printf("ternyata isRepeated\n");
				// printf("i: %d\n",i);
				can = false; break;
			}
		}
		if(foundAns){continue;}
		if(!can){
			// printf("masuk sini\n");
			printf("Impossible\n");
		}else{
			//cek apakah ada huruf pertama di setelahnya
			char karPertama = kata[0];
			string penambahan = "";
			penambahan+=karPertama;
			// printf("karPertama: %c\n",karPertama);
			for(i=1;i<pjg;i++){
				// printf("kata[%d]: %c\n",i,kata[i]);
				if(karPertama == kata[i]){
					// printf("masuk snikah?\n");
					// printf("i: %d\n",i);
					break;
				}else{
					penambahan += kata[i];
				}
			}

			// printf("i: %d\n",i);
			// printf("i\n");
			if(i==pjg){
				
				printf("Impossible\n");
			}else{
				cout<<penambahan<<kata<<endl;
			}
		}

	}
	return 0;
};