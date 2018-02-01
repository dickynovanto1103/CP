#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isValid[1000010];
int a[1000010],jumlah[1000010];

int main() {
	int tc,n,k,i,j;
	map<int,int> mapper;
	map<int,int>::iterator it;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		memset(isValid,false,sizeof isValid);
		memset(jumlah,0,sizeof jumlah);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		//tahap pertama dulu
		int cnt = 0;
		ll jumlahValidSegmen = 0, totalValid = 0;
		for(i=0;i<k;i++){
			it=mapper.find(a[i]);
			if(it==mapper.end()){
				mapper[a[i]] = cnt;
				jumlah[cnt]++;
				if(jumlah[cnt]==a[i]){isValid[cnt] = true; jumlahValidSegmen++;} 
				else{
					if(isValid[cnt]){isValid[cnt] = false; jumlahValidSegmen--;}//awalnya valid terus jd ga valid
				}
				cnt++;
			}
			else{
				int idx = mapper[a[i]];
				jumlah[idx]++;
				if(jumlah[idx]==a[i]){isValid[idx] = true; jumlahValidSegmen++;}
				else{
					if(isValid[idx]){isValid[idx] = false; jumlahValidSegmen--;}
				}
			}
		}
		totalValid+=jumlahValidSegmen;
		i=0; j=k;
		while(j<n){
			it=mapper.find(a[j]);
			if(it==mapper.end()){
				mapper[a[j]] = cnt;
				jumlah[cnt]++;
				if(jumlah[cnt]==a[j]){isValid[cnt] = true; jumlahValidSegmen++;}
				else{
					if(isValid[cnt]){isValid[cnt] = false; jumlahValidSegmen--;}
				}
			}else{
				int idx = mapper[a[j]];
				jumlah[idx]++;
				if(jumlah[idx]==a[j]){isValid[idx] = true; jumlahValidSegmen++;}
				else{
					if(isValid[idx]){isValid[idx] = false; jumlahValidSegmen--;}
				}
			}
			int idx = mapper[a[i]];
			jumlah[idx]--;
			if(jumlah[idx]==a[i]){isValid[idx] = true; jumlahValidSegmen++;}
			else{
				if(isValid[idx]){isValid[idx] = false; jumlahValidSegmen--;}
			}
			totalValid+=jumlahValidSegmen;
			i++; j++;
		}
		printf("%lld\n",totalValid);
		mapper.clear();
	}
	return 0;
}