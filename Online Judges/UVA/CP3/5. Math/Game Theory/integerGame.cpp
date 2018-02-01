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
	int tc,i;
	string kata;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case %d: ",tt);
		cin>>kata;
		int sum =0;
		int pjg = kata.length();
		for(i=0;i<pjg;i++){
			int bil = kata[i]-'0';
			sum+=bil;
		}
		bool found = false;
		for(i=0;i<pjg;i++){
			int bil = kata[i]-'0';
			if((sum-bil)%3==0){found = true; kata[i]='0'; break;}
		}
		if(!found){printf("T\n");}
		else{
			//hitung banyak 3,6,9
			int cnt = 0;
			for(i=0;i<pjg;i++){
				if(kata[i]=='3' || kata[i]=='6' || kata[i]=='9'){cnt++;}
			}
			/*printf("\n");
			cout<<"kata "<<kata<<endl;
			printf("cnt: %d\n",cnt);*/
			if(cnt%2==0){//T ga bs ngambil lg nanti
				printf("S\n");
			}else{
				printf("T\n");
			}
		}
	}
	return 0;
}