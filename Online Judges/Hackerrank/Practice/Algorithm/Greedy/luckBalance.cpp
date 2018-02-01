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

struct contest{
	int luck, importance;
};

bool cmp(contest a, contest b){
	if(a.importance==b.importance){
		return a.luck < b.luck;
	}
	return a.importance > b.importance;
}

int main(){
	int n,k;
	contest a[110];
	int i,j;
	scanf("%d %d",&n,&k);
	int counterPenting = 0;
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i].luck, &a[i].importance);
		if(a[i].importance==1){counterPenting++;}
	}
	sort(a,a+n,cmp);
	int jumlahMenang = counterPenting-k;
	int sum = 0;
	if(jumlahMenang<=0){
		for(i=0;i<n;i++){
			sum+=a[i].luck;
			//printf("%d %d\n",a[i].luck, a[i].importance);
		}	
	}else{
		for(i=0;i<n;i++){
			if(jumlahMenang==0){break;}
			jumlahMenang--;
			sum-=a[i].luck;
		}
		int idx = i;
		for(i=idx;i<n;i++){
			//if(jumlahMenang==0){break;}
			sum+=a[i].luck;
		}
	}
	printf("%d\n",sum);

	return 0;
};