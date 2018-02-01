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
const int N = 1e6 + 5;
ll cnt[N*4];
string kata;

ll solve(int n){
	ll ans = 0;
	int idx = N;
	cnt[idx] = 1;
	//printf("cnt[%d] awal jd: %lld\n",idx,cnt[idx]);
	for(int i=0;i<n;i++){
		char kar = kata[i];
		//printf("kar: %c\n",kar);
		if(kata[i]=='('){
			idx++;
			cnt[idx] = 1;
			//printf("cnt[%d] jd: %lld\n",idx,cnt[idx]);
		}else{
			idx--;
			ans+=cnt[idx];
			//printf("ans jd: %lld setelah ditambah dengan cnt[%d] = %lld\n",ans,idx,cnt[idx]);
			cnt[idx]++;
			//printf("cnt[%d] ditambah 1 jd: %lld\n",idx,cnt[idx]);
		}
	}
	return ans;
}


int main() {
	int n,i;
	cin.tie(NULL);
	cin>>n;
	cin>>kata;
	cout<<solve(n)<<endl;
	return 0;
}
/*#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int cnt[3 * N];
string kata;
int n;

long long solve() {
	long long ret = 0;
	int total = N;
	cnt[total] = 1;
	printf("cnt[%d] awal jd: %lld\n",total,cnt[total]);
	char kar;
	for(int i = 0 ; i < kata.length() ; i++)
		kar = kata[i];
		printf("i: %d kar: %c\n",i,kar);
		if(kar == '(') {
			total++;
			cnt[total] = 1;
			printf("cnt[%d] jd: %lld\n",total,cnt[total]);
		}
		else {

			total--;
			ret += cnt[total];
			printf("ret ditambah cnt[%d] = %lld jd %lld\n",total,cnt[total],ret);
			cnt[total]++;
			printf("cnt[%d] ditambah jd: %lld\n",total,cnt[total]);
		}

	return ret;	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;
	cin >> kata;
	cout<<"kata: "<<kata<<endl;
	cout << solve() << endl;
	return 0;
}*/