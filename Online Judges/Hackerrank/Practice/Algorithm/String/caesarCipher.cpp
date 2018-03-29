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

bool isLetter(int kar) {
    return (kar>=0 && kar<=25);
}

bool isUpper(int kar) {
    return (kar>='A' && kar<='Z');
}

int main() {
    int n,i,j;
    string kata;
    int k;
    scanf("%d",&n);
    cin>>kata;
    scanf("%d",&k);
    string ans = "";
    for(i=0;i<n;i++){
    	char kar = kata[i];
    	if(!isLetter(kar)){ans+=kar; continue;}
    	if(isUpper(kar)){
    		kar-='A';
    		ans+=kar;
    	}else{
    		kar+='a';
    		ans+=kar;
    	}
    }

    for(i=0;i<n;i++){
        int kar = (int)kata[i];
        
        if(isUpper(kar)) {
            kar+=k;
            if(kar>=26) {
                kar%=26;
                kar+='A';
            }
        }else {
            kar+=k;
            // printf("kar jd: %d\n",kar);
            if(kar>'z') {
                kar%='z';
                kar+='a';
                kar--;
            }
        }
        ans+=kar;
    }
    cout<<ans<<endl;
    return 0;
}
