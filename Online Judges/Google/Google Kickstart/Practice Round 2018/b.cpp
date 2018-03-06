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

string ubah(string &kata){
	for(int i=0;i<kata.length();i++){
		if(kata[i]=='0'){kata[i] = '1';}
		else{kata[i] = '0';}
	}
	return kata;
}

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);
	int pjg = 0;
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		string kata = "0";
		pjg = 1;
		while(pjg<n){
			string reverseKata = "";
			for(i=kata.length()-1;i>=0;i--){
				reverseKata += kata[i];
			}
			
			kata = kata+ "0" + ubah(reverseKata);
			pjg = kata.length();
		}
		printf("%c\n",kata[n-1]);
	}
	return 0;
};