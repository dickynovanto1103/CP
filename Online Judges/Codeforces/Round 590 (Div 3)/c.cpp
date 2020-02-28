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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isValid(ii koor, int n) {
	int x = koor.first, y = koor.second;
	return (x >= 0 && x <= 1 && y >= 0 && y < n);
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		string s[2];
		cin>>s[0]>>s[1];
		// printf("n: %d\n",n);
		ii koor = ii(0,0);
		ii sebelum = ii(0,-1);
		bool valid = true;
		while(true){
			ii temp = koor;
			if(koor.first == 0) {//hanya menerima turun atau ke kanan
				char c = s[koor.first][koor.second];
				if(c >= '1' && c <= '2'){
					if(sebelum.first - 1 == koor.first){
						koor.first--;
					}else{
						koor.second++;
					}
				}else{
					if(sebelum.second + 1 == koor.second){//harus turun..soalnya dari kiri
						koor.first++;
					}else{
						koor.second++;
					}
				}

			}else{
				char c = s[koor.first][koor.second];
				if(c >= '1' && c <= '2'){
					if(sebelum.first + 1 == koor.first){
						koor.first++;
					}else{
						koor.second++;
					}
				}else{
					if(sebelum.second + 1 == koor.second){//harus naik..soalnya dari kiri
						koor.first--;
					}else{
						koor.second++;
					}
				}				
			}
			// printf("koor: %d %d\n",koor.first, koor.second);
			sebelum = temp;
			if(koor == ii(1,n)){ //done
				break;
			}
			if(!isValid(koor, n)){
				valid = false;
				break;
			}
			
		}
		if(valid){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
};