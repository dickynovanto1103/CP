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

bool isDifferentHand(char kar1, char kar2){
	if(kar1 == 'd'){
		return kar2 == 'j' || kar2 == 'k';
	}else if(kar1 == 'f'){
		return kar2 == 'j' || kar2 == 'k';
	}else if(kar1 == 'j'){
		return kar2 == 'd' || kar2 == 'f';
	}else if(kar1 == 'k'){
		return kar2 == 'd' || kar2 == 'f';
	}
}

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		string kata;
		map<string,ll> mapper;
		ll sum = 0;
		char kar;
		for(i=0;i<n;i++){
			cin>>kata;
			kar = kata[0];
			ll tot = 0;
			if(mapper.find(kata) == mapper.end()){
				tot += 2;
				for(j=1;j<kata.length();j++){
					if(isDifferentHand(kata[j], kar)){
						tot += 2;
						// printf("karakter: %c tot tambah 2: jadi %lld\n",kata[j],tot);
					}else{
						tot += 4;
						// printf("karakter: %c tot tambah 4: jadi %lld\n",kata[j],tot);
					}
					kar = kata[j];
				}
				//map nilai kata
				mapper[kata] = tot;
				sum += tot;
				// printf("sum jadi: %lld\n",sum);
			}else{
				sum += (mapper[kata]/2);
				// printf("sum ditambah setengah yaitu %lld jadi: %lld\n",mapper[kata]/2, sum);
				kar = kata[kata.length()-1];
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
};