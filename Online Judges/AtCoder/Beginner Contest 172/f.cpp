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
typedef pair<uint64,uint64> ii;
typedef vector<ii> vii;

uint64 a[301];

uint64 firstPile;

ii findAB(ll sum, ll sor) {
	if(sum < sor){
		printf("-1\n");
		exit(0);
	}
    ll A = (sum - sor + 1)/2LL;
  
    ll a = 0, b = 0;
    // printf("sum: %lld sor: %lld\n",sum, sor);

    for(int i=50;i>=0;i--){
    	uint64 Xi = (sor & (1LL << i)); 
        uint64 Ai = (A & (1LL << i));
    	if(Xi == 0 && Ai > 0) {
        	a = ((1LL << i) | a);
        	b = ((1LL << i) | b);
        	// printf("a jadi: %lld\n", a);
        }
    }

    for(int i=50;i>=0;i--){
    	uint64 Xi = (sor & (1LL << i)); 
        uint64 Ai = (A & (1LL << i));
    	if(Xi == 0 && Ai == 0){

        }else if(Xi == 0 && Ai > 0) {

        }
        else if (Xi > 0 && Ai == 0) { 
        	if((a | (1LL<<i)) > firstPile) {
        		b = ((1LL << i) | b);
        		continue;
        	}
            a = ((1LL << i) | a);  
            // printf("a disini: %lld firstPile: %lld\n",a, firstPile);
        } else{
        	// printf("sini\n");
        	printf("-1\n");
        	exit(0);
        }
 
    }
  
    return ii(a,b);
} 

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		cin>>a[i];
		// scanf("%lld",&a[i]);
	}

	uint64 sor = 0;
	for(i=2;i<n;i++){
		sor ^= a[i];
	}
	// printf("sor: %lld\n",sor);

	uint64 sum = a[0] + a[1];
	firstPile = a[0];
	ii ans = findAB(sum, sor);
	uint64 pertama = ans.first, kedua = ans.second;
	if((a[0] ^ a[1]) == sor){
		printf("0\n");
		return 0;
	}
	// cout<<pertama << " "<<kedua<<endl;
	if (pertama == 0 || pertama > a[0]) {
		printf("-1\n");
	}else{
		cout << a[0] - pertama << endl;
	}
	// printf("%lld %lld\n",pertama, kedua);
	// if(pertama <= a[0] && kedua <= a[0]){
	// 	uint64 maks = max(pertama, kedua);
	// 	if(maks == 0){
	// 		printf("-1\n");
	// 	}else{
	// 		cout<<a[0] - maks<<endl;
	// 		// printf("%lld\n",a[0] - maks);	
	// 	}
	// }else if(pertama > a[0] && kedua <= a[0]){
	// 	if(kedua == 0) {
	// 		printf("-1\n");
	// 	}else{
	// 		cout<<a[0] - kedua<<endl;
	// 		// printf("%lld\n",a[0] - kedua);	
	// 	}
		
	// }else if(pertama <= a[0] && kedua > a[0]){
	// 	if(pertama == 0) {
	// 		printf("-1\n");
	// 		return 0;
	// 	}
	// 	cout<<a[0] - pertama<<endl;
	// 	// printf("%lld\n",a[0] - pertama);
	// }else{
	// 	printf("-1\n");
	// }

	// //2 pertama klo dixor harus sor
	// ll temp = 1000000000000LL;
	// ll bil = temp;
	// string ans;
	// while(bil){
	// 	int mod = bil % 2LL;
	// 	bil /= 2LL;
	// 	if(mod & 1){ans += "1";}
	// 	else{ans += "0";}
	// }
	// reverse(ans.begin(), ans.end());
	// cout<<ans<<" "<<ans.length()<<endl;

	return 0;
};