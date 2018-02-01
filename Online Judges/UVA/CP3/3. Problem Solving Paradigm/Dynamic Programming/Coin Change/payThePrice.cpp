#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int a[301];
int angka[3], cnt, counter;
ll memo[301][301];

ll solve(int id, int val, int total){
	if(val==0){
		if(total>=angka[1] && total<=angka[2]){return 1;}
		return 0;
	}
	if(val<0){return 0;}
	if(id==300){return 0;}
	
	if(memo[id][val]!=-1){return memo[id][val];}
	ll ans1 = solve(id+1,val,total,ans);
	ans.push_back(a[id]);
	ll ans2 = solve(id,val-a[id],total+1, ans);
	ans.pop_back();

	return memo[id][val] = solve(id+1,val,total) + solve(id,val-a[id],total+1);
}

int main() {
	int n,i,j;
	string kata;
	
	for(i=0;i<300;i++){a[i] = i+1;}
	//for(i=0;i<300;i++){printf("%d\n",a[i]);}		
	while(getline(cin,kata)){
		//cout<<kata<<endl;
		int ukuran = kata.length();
		int cnt = 0, bil = 0;
		for(i=0;i<ukuran;i++){
			if(kata[i]==' '){angka[cnt] = bil; bil=0; cnt++;}
			else{bil*=10; bil+=kata[i]-'0';}
		}
		angka[cnt] = bil; cnt++;
		if(cnt==1){angka[1] = 1; angka[2] = angka[0];}
		else if(cnt==2){ angka[2] = angka[1]; angka[1]= 1;}
		//printf("angka: %d batas bawah: %d batasatas: %d\n",angka[0], angka[1], angka[2]);
		memset(memo,-1,sizeof memo);
		vi b;
		counter = 0;
		ll ans = solve(0,angka[0], 0, b);
		b.clear();
		printf("jawaban: %lld\n",ans);

	}
	return 0;
}