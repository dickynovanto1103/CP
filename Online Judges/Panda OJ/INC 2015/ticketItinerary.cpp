#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int stringToInt(string kata){
	int bil = 0;
	int i = 0, n = kata.length();
	for(i=0;i<n;i++){
		bil*=10; bil+=kata[i]-48;
	}
	return bil;
}

int main() {
	int n,i;
	string kota[110];
	int gmt[110];
	scanf("%d",&n);
	map<string,int> mapper;
	map<string,int>::iterator it;
	for(i=0;i<n;i++){
		cin>>kota[i]; cin>>ws; scanf("GMT%d",&gmt[i]);
		mapper[kota[i]] = gmt[i];
		//printf("kota: \n");cout<<kota[i]<<" gmt: "<<gmt[i]<<endl;
	}

	int tc,tt;
	scanf("%d",&tc);
	cin>>ws;
	for(tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		string word,kota1,kota2;
		string kata[4],hari="ga ada";
		getline(cin,word);
		int ukuran = word.length();
		int cnt=0, awal = 0;
		//char kar;

		for(i=0;i<ukuran;i++){

			if(word[i]==' '){kata[cnt] = word.substr(awal,i-awal);  cnt++; awal = i+1;}
			//printf("cnt: %d i: %d\n",cnt,i);
			if(cnt==4 && i<ukuran-1){hari = word.substr(awal,2);}
		}
		if(cnt==3){kata[cnt] = word.substr(awal,ukuran-awal); cnt++;}
		/*for(i=0;i<cnt;i++){
			if(i){printf(" ");}
			cout<<kata[i];
		}
		if(hari!="ga ada"){cout<<" "<<hari;}
		printf("\n");*/
		int gmt1 = mapper[kata[0]]; int gmt2 = mapper[kata[2]];
		//printf("gmt1: %d gmt2: %d\n",gmt1,gmt2);
		int h1 = stringToInt(kata[1].substr(0,2)), m1 = stringToInt(kata[1].substr(3,2));
		int h2 = stringToInt(kata[3].substr(0,2)), m2 = stringToInt(kata[3].substr(3,2));
		//printf("%d:%d %d:%d\n", h1,m1,h2,m2);
		h1-=gmt1;
		h2-=gmt2;
		if(hari=="-1"){h2-=24;}
		else if(hari=="+1"){h2+=24;}
		int menit1 = h1*60 + m1, menit2 = h2*60+m2;
		int selisih = menit2-menit1;
		int jam = selisih/60, menit = selisih%60;
		printf("%d hours and %d minutes\n",jam,menit);
		
	}
	return 0;
}