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
 
string solve(int pembilang, int penyebut)
{
    string res; // Initialize result
    map <int,int> mapper;
    map <int,int>::iterator it;
    int sisa = pembilang%penyebut;
 
    while ((sisa!=0)&&(mapper.find(sisa)==mapper.end()) )
    {
        mapper[sisa] = res.length();
        sisa = sisa*10;
        int res_part = sisa / penyebut;
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
    int a,b,c,i;
    scanf("%d %d %d",&a,&b,&c);
    char kar = c+'0';
    string ans = to_string((double)a/(double)b);
    //printf("ans: "); cout<<ans<<endl;
    string result = solve(a, b);
    //printf("result: "); cout<<result<<endl;
    if(result==""){
        for(i=0;i<ans.length();i++){
            //cari ,
            //printf("kar: %c\n",ans[i]);
            if(ans[i]=='.'){break;}
        }

        int idx = i+1;
        int counter = 1;
        //printf("idx: %d\n",idx);
        for(i=idx;i<ans.length();i++){
            if(ans[i]==kar){
                printf("%d\n",counter);
                return 0;
            }
            else{counter++;}
        }
        printf("-1\n");
    }else{
        for(i=0;i<result.length();i++){
            if(result[i]==kar){printf("%d\n",i+1);return 0;}
        }
        printf("-1\n");
    }
    return 0;
}