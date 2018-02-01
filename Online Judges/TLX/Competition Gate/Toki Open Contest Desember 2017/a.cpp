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
 
string solve(ll pembilang, ll penyebut)
{
    string res; // Initialize result
    map <ll,ll> mapper;
    map <ll,ll>::iterator it;
    ll sisa = pembilang%penyebut;
 
    while ((sisa!=0)&&(mapper.find(sisa)==mapper.end()) )
    {
        mapper[sisa] = res.length();
        sisa = sisa*10;
        ll res_part = sisa / penyebut;
        res += to_string(res_part);
        sisa = sisa % penyebut;
    }
    mapper.clear();
    if(sisa==0){
        return "";
    }else{
        return res.substr(mapper[sisa]);
    }
    
}

int main()
{
    ll a,b,c,i;
    string ans = to_string(103993/33102);
    printf("ans: "); cout<<ans<<endl;
    string result = solve(103993,33102);
    printf("result: "); cout<<result<<endl;
    scanf("%lld %lld",&a,&b);
    char kar = c+'0';
    

    for(i=0;i<ans.length();i++){
        //cari ,
        printf("%c",ans[i]);
        if(ans[i]=='.'){break;}
    }
    if(result==""){
        
        for(i=0;i<11;i++){printf("0");}
        printf("\n");
        // int idx = i+1;
        // int counter = 1;
        // //printf("idx: %d\n",idx);
        // for(i=idx;i<ans.length();i++){
        //     if(ans[i]==kar){
        //         printf("%d\n",counter);
        //         return 0;
        //     }
        //     else{counter++;}
        // }
        // printf("-1\n");
    }else{
    	i=0;
        while(true){
        	bool selesai = false;
        	for(int j=0;j<result.length();j++){
        		printf("%c",result[j]);
        		i++;
        		if(i==11){
        			selesai = true;
        			break;
        		}
        	}
        	if(selesai){break;}
        }
        printf("\n");
    }
    return 0;
}