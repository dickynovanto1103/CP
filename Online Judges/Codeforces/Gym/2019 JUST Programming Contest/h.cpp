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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		string kata;
		cin>>kata;
		int angka = -1;
		bool valid = true;
		for(i=0;i<kata.length();i++){
			if(angka == -1){angka = kata[i] - 'a';}
			else if(angka == 25){
				if(kata[i] == 'a'){angka = 0;}
				else{valid = false; break;}
			}else{
				if(kata[i] - 'a' - angka == 1){

				}else{
					// printf("halo angka: %d\n");
					valid = false; break;
				}
			}
			angka = kata[i] - 'a';
		}
		if(valid){printf("YES\n");}
		else{printf("NO\n");}
	}
	return 0;
};