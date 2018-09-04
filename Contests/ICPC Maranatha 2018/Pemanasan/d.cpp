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

int main(){
	int n,i,j;
	scanf("%d",&n);
	while(n--){
		string kata;
		cin>>kata;
		int ans = 0;
		int ukuran = kata.length();
		for(i=1;i<=ukuran;i++){
			// printf("i: %d\n",i);
			if(ukuran%i==0){
				string wordPertama = kata.substr(0,i);
				// printf("wordPertama: "); cout<<wordPertama<<endl;
				int iterasi = ukuran/i;
				bool isValid = true;
				for(j=0;j<ukuran;j+=i){
					string word = kata.substr(j,i);
					// printf("j: %d\/*n",j);
					// printf("word: */"); cout<<word<<endl;
					if(word == wordPertama){
						continue;
					}else{
						isValid = false;
						break;
					}
					
				}
				if(!isValid){
					continue;
				}else{
					ans = i;
					break;
				}
			}
			

		}
		printf("%d\n",ans);
	}
	return 0;
};