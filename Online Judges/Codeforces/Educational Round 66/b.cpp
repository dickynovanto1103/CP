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
// #define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

const ll maksVal = (1LL<<32) - 1;

int main(){
	int n,i,j;
	scanf("%d",&n);
	stack<int> st;
	ll kali = 1;
	ll ans = 0;
	ll hasilKali[maxn];
	hasilKali[0] = 1;
	bool isOver[maxn];
	memset(isOver, false, sizeof isOver);
	int idx = 0;
	for(i=0;i<n;i++){
		string s;
		cin>>s;
		if(s == "for"){
			int nilai;
			cin>>nilai;
			st.push(nilai);
			idx++;
			hasilKali[idx] = hasilKali[idx-1]*nilai;
			if(hasilKali[idx] > maksVal){
				isOver[idx] = true;
			}else{
				if(isOver[idx-1]){
					isOver[idx] = true;
				}else{
					isOver[idx] = false;	
				}
			}
		}else if(s == "end"){
			st.pop();
			idx--;
		}else{
			if(isOver[idx]){
				printf("OVERFLOW!!!\n");
				return 0;
			}
			ll selisihOverflow = maksVal - ans;
			if(hasilKali[idx] > selisihOverflow){
				printf("OVERFLOW!!!\n");
				return 0;
			}
			ans += hasilKali[idx];

			// printf("i: %d ans jd: %lld\n",i, ans);
			// if(ans > maksVal){
			// 	printf("OVERFLOW!!!\n");
			// 	return 0;
			// }
		}
	}
	printf("%lld\n",ans);
	return 0;
};