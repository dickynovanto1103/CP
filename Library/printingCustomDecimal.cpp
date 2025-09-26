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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

// Custom numpunct facet to define thousands separator and grouping
struct CommaNumpunct : public std::numpunct<char> {
protected:
    char do_thousands_sep() const override { return ','; } // Define the thousands separator
    std::string do_grouping() const override { return "\003"; } // Define grouping (e.g., 3 digits)
};



void solve(){
	double balances[13];
	for(int i=0;i<12;i++){
		scanf("%lf",&balances[i]);
	}
	double sum = 0;
	for(int i=0;i<12;i++){
		sum += balances[i];
	}

	// Create a new locale with the custom numpunct facet
    std::locale custom_locale(std::cout.getloc(), new CommaNumpunct());

    // Imbue the custom locale into the output stream
    std::cout.imbue(custom_locale);

    // Print the floating-point number with thousands separators
    std::cout << std::fixed << std::setprecision(2) << sum/12.0 << std::endl;
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	for(int i=1;i<=tc;i++){
		printf("%d $", i);
		solve();
	}

	return 0;
};