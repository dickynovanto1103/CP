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
	string kata;
	int banyak8 = 0;
	int banyakKataTidak8 = 0 ;
	scanf("%d",&n);
	cin>>kata;
	vi listTidak8, list8;
	for(i=0;i<n;i++){
		if(kata[i] == '8'){banyak8++; list8.pb(8);}
		else{banyakKataTidak8++; listTidak8.pb(kata[i] - '0');}
	}
	
	int ans = 0;
	while(list8.size()>0){

		if(listTidak8.size() >= 10){
			list8.pop_back();
			for(i=0;i<10;i++){
				listTidak8.pop_back();
			}
			ans++;
		}else{
			list8.pop_back();
			int ukuran = listTidak8.size();
			int butuh = 10 - ukuran;
			if(list8.size() >= butuh){
				for(i=0;i<butuh;i++){list8.pop_back();}
				listTidak8.clear();
				ans++;
			}else{
				break;
			}
			
		}
	}
	printf("%d\n",ans);
	return 0;
};