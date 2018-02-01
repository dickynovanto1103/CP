#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define inf 2000000000
int main(){
	int tc,n,i,a[1000],uang,cnt;
	ll total;
	map <int,int> mapper;
	map <int,int>::iterator it;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		total=0;
		for(i=0;i<n;i++){scanf("%d",&a[i]);total+=a[i];}
		cnt=0;
		for(i=n-1;i>=0;i--){
			if(total-a[i]>=0){
				it=mapper.find(a[i]);
				if(it==mapper.end()){mapper[a[i]]=cnt++;}
				total-=a[i];
				i++;//biar keulang lg nanti
			}
		}
		printf("%d\n",cnt);
		mapper.clear();
	}
	return 0;
}

/*#include <iostream>
#include <vector>
using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

int main(void) {
    int t, n, coin;

    cin >> t;

    rep (case_number, t) {
        cin >> n;

        vector<int> coins;

        rep (i, n) {
            cin >> coin;
            coins.push_back(coin);
        }

        int result = 1;
        int sum = 1;

        REP (i, 1, n) {
            if (i == n-1) {
                result++;
            } else {
                if (sum + coins[i] < coins[i+1]) {
                    result++;
                    sum += coins[i];
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}*/