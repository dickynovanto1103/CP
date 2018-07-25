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

bool isSelangSeling(string kata){
	char karPertama = kata[0];
	if(karPertama == '0'){return false;}
	if(kata.length() == 1 && karPertama=='0'){return false;}
	for(int i=1;i<kata.length();i++){
		if(karPertama==kata[i]){return false;}
		else{
			karPertama = kata[i];
		}
	}
	return true;
}

ii getGanjilGenap(string kata){
	int pjg = kata.length();
	int cntGanjil = 0, cntGenap = 0;
	for(int i=0;i<(1<<pjg);i++){
		string word = "";
		for(int j=0;j<pjg;j++){
			if(i & (1<<j)){
				word+=kata[j];
			}
		}
		// cout<<"word: "<<word<<endl;
		if(word.length()==0){continue;}
		if(isSelangSeling(word)){
			if(word.length()%2==0){
				cntGenap++;
			}else{
				cntGanjil++;
			}
			// printf("cntGanjil jadi: %d cntGenap jadi: %d\n",cntGanjil, cntGenap);
		}else{

		}
	}
	return ii(cntGanjil, cntGenap);
}

int main(){
	string dummy;
	cin>>dummy;
	int a,b,q;
	scanf("%d %d %d",&a,&b,&q);

	int i,j,k;
	string kataAns = "z";
	for(i=2;i<10;i++){
		for(k=0;k<(1<<i);k++){
			string kata = "1";
			for(j=0;j<i;j++){
				if(k & (1<<j)){
					kata+='1';
				}else{
					kata+='0';
				}
			}
			// printf("\n");
			// printf("kata: "); cout<<kata<<endl;
			// printf("\n");
			ii ans = getGanjilGenap(kata);
			
			// printf("cntGanjil: %d cntGenap: %d\n",ans.first, ans.second);
			if(ans.first == a && ans.second == b){
				if(kataAns>kata){
					kataAns = kata;
				}
				// printf("yang diinsert: "); cout<<kata<<endl;
			}
		}	
	}
	if(kataAns == "z"){
		printf("TIDAK MUNGKIN\n");
		return 0;
	}
	
	
	int pjg = kataAns.size();
	printf("MUNGKIN\n");
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		if(r>=pjg){printf("DI LUAR BATAS\n");}
		else{
			for(i=l;i<=r;i++){
				printf("%c",kataAns[i]);
			}
			printf("\n");
		}
	}
	
	return 0;
};