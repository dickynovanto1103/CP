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

int strToInt(string kata){
	int ans = 0;
	int pjg = kata.length();
	for(int i=0;i<pjg;i++){
		int bil = kata[pjg - 1-i] - '0';
		ans += ((1<<(i))*bil);

	}
	return ans;
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		string kata;
		cin>>kata;
		kata += '/';
		n = kata.length();
		int cnt = 0;
		string ans = "";
		for(i=0;i<n;i++){
			char kar = kata[i];

			cnt++;
			if(kar == '/'){
				int bil = strToInt(ans);
				// printf("ans: "); cout<<ans<<endl;
				// printf("bil: %d\n",bil);
				char kar = bil - 1 + 'a';
				printf("%c",kar);
				ans = "";
				continue;
			}else{
				ans += kar;	
			}			

		}

		printf("\n");
	}
	
	return 0;
};