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

ll cnt[2][27];

void parse(const string& kata, int id) {
	int i,j;
	int pjg = kata.length();
	char curKar = 'd';
	int num = 0;
	for(i=0;i<pjg;i++){
		char kar = kata[i];
		if(kar >= 'A' && kar <= 'Z'){
			if(curKar == 'd')
				num = 0;
			else{

				num = max(num, 1);

				cnt[id][curKar-'A'] += num;

			}
			num = 0;
			curKar = kar;
		}else{
			num *= 10;
			num += (kar - '0');
		}
	}
	num = max(num, 1);
	// printf("num: %d\n",num);
	cnt[id][curKar-'A'] += num;
	// printf("cnt[%d][%c]: %lld\n",id,curKar, cnt[id][curKar-'A']);
}

int main(){
	string kata, tujuan;
	int banyak,i,j;
	cin>>kata>>banyak>>tujuan;
	parse(kata, 0); parse(tujuan, 1);
	for(i=0;i<26;i++){
		cnt[0][i] *= (ll)banyak;
	}

	ll ans = inf;
	for(i=0;i<26;i++){
		if(cnt[1][i] > cnt[0][i]){ans = 0; break;}
		else{
			if(cnt[1][i] == 0){continue;}
			ans = min(ans, (ll)cnt[0][i] / cnt[1][i]);
			// printf("ans jd: %lld\n",ans);
		}
	}
	printf("%lld\n",ans);
	return 0;
};