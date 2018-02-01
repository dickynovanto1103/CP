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

bool cmp(int a, int b){return a>b;}

int main() {
	int n,i,last, counter = 0;
	int bil;
	scanf("%d",&n);
	string kata;
	vi listbil;
	int expected = 1, tot = 0;
	bool issorted = true;
	bool kondisi = true;
	for(i=0;i<2*n;i++){

		cin>>kata;
		//printf("kata: "); cout<<kata<<" "<<bil<<endl;
		

		if(kata=="add"){
			cin>>bil; listbil.pb(bil);
		}else{
			if(listbil.empty()){listbil.pb(expected);}
			if(listbil.back()!=expected){
				tot++;
				listbil.clear();
			}else{listbil.pop_back();}
			expected++;
		}
	}
	printf("%d\n",tot);
	return 0;
}