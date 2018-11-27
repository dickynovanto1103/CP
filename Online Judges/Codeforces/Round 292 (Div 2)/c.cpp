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

int cnt[10];

bool isPrime(int bil){
	return bil == 2 || bil == 3 || bil == 5 || bil == 7;
}
string ans;

void factorize(int bil){
	if(isPrime(bil)){
		ans += (bil + '0');
	}
	else{
		int i;
		if(bil == 4){
			cnt[2]+=2;
			for(i=3;i>=2;i--){
				if(isPrime(i)){ans += (i + '0'); return;}
			}
		}
		else if(bil == 6){
			ans  += '3';
			for(i=5;i>=2;i--){
				if(isPrime(i)){ans += (i + '0'); return;}
				if(i==4){cnt[2]+=2;}
				else{cnt[i]++;}
			}
		}else if(bil == 8){
			ans += "222";
			for(i=7;i>=2;i--){
				if(isPrime(i)){ans += (i + '0'); return;}
				if(i==6){cnt[2]++; cnt[3]++;}
				else if(i==4){cnt[2]+=2;}
				else{cnt[i]++;}
			}
		}
		else if(bil == 9){
			cnt[3]+=2;
			for(i=8;i>=2;i--){
				if(isPrime(i)){ans += (i + '0'); return;}
				if(i==8){cnt[2]+=3;}
			}
		}
	}
}

int main(){
	int n,i,j;
	string kata;
	cin>>n>>kata;
	
	memset(cnt, 0, sizeof cnt);
	ans = "";
	for(i=0;i<n;i++){
		char kar = kata[i];
		int bil = kar - '0';
		if(bil == 0 || bil == 1){
			continue;
		}else{
			factorize(bil);
		}
	}
	
	int banyak3 = min(cnt[2], cnt[3]);
	cnt[2] -= banyak3;
	cnt[3] -= banyak3;
	for(i=0;i<banyak3;i++){
		ans += '3';
	}
	for(i=9;i>=2;i--){
		char kar = i + '0';
		for(j=0;j<cnt[i];j++){
			ans += kar;
		}
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	cout<<ans<<endl;


	return 0;
};