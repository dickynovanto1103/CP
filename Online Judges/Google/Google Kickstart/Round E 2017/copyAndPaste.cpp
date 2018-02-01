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

int main() {
	int tc,i,j;
	string kata,temp;

	cin>>tc;
	ll step;
	cin>>ws;
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		getline(cin,kata);
		printf("kata: "); cout<<kata<<endl;
		temp = "";
		step = 2;
		string sisa;
		temp+=kata[0]; temp+=kata[1];
		sisa = kata.substr(2,kata.length()-2);
		//printf("sisa: "); cout<<sisa<<endl;
		if(kata.length()==2){break;}
		int idxAwal = 2;
		int pjg = temp.length(), pjgAsli = kata.length();
		string tempkata;
		string anstemp="~",curanstemp = "ASDFADS";
		bool ketemu;
		while(true){
			ketemu = false;
			int idx = sisa.find(anstemp);
			pjg = temp.length();
			//printf("pjg menjadi: %d\n",pjg);
			for(i=0;i<pjg;i++){
				for(j=2;j<=pjg;j++){
					//printf("i: %d,j: %d,i+j: %d\n",i,j,i+j);
					if((i+j) > pjg){
						//printf("i+j: %d pjg: %d\n",i+);
						break;
					}//ngambil substring out of bound
					tempkata = temp.substr(i,j);
					int found = sisa.find(tempkata);
					/*printf("diambil %d karakter dari tempkata: ",j); cout<<tempkata<<endl;
					printf("found: %d\n",found);*/
					if(found!=0){break;}
					else{
						if(tempkata==curanstemp){
							//printf("sama\n");
							ketemu = true;
							continue;
						}
						if(tempkata.length()<=anstemp.length()){continue;}
						anstemp = tempkata; 
						//printf("anstemp menjadi: "); cout<<anstemp<<endl;
						ketemu = true;
					}
				}
			}	
			if(!ketemu){
				//printf("ditambahkan karakter: %c\n",kata[idxAwal]);
				temp+=kata[idxAwal]; idxAwal++; step++;

			}
			else{	
				//cout<<"anstemp = "<<anstemp<<endl;

				temp+=anstemp; idxAwal+=(anstemp.length());
				if(anstemp==curanstemp){
					//printf("clipboard sama seperti sebelumnya\n");
					step++;
				}
				else{
					//printf("clipboard beda\n");
					step+=2; curanstemp = anstemp;
					//printf("curanstemp jd: "); cout<<curanstemp<<endl;
				}
				
			}
			// printf("idxAwal jadi: %d\n",idxAwal);
			// printf("step jadi: %lld\n",step);
			sisa = kata.substr(idxAwal,kata.length()-idxAwal);
			// printf("sisa: "); cout<<sisa<<endl;
			// printf("temp: "); cout<<temp<<endl;
			if(idxAwal>=pjgAsli){break;}
			if(temp.length()==pjgAsli){break;}
		}
		
		printf("%lld\n",step);	
	}
	
	return 0;
}