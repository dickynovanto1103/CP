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
typedef pair<ii, int> iii;
typedef pair<ii,iii> iiii;
typedef vector<ii> vii;

vector<iiii> ver, hor;

bool cmp(iiii a, iiii b){
    if(a.first.first == b.first.first){
        return a.second.second < b.second.second;
    }
    return a.first.first < b.first.first;
}

bool cmpHor(iiii a, iiii b){
    return a.first.second < b.first.second;
}

bool isInside(int a, int b, int c){
    return b <= a && a <= c;
}

bool isCompletelyInside(ii a, ii b) {
    int y1 = a.first, y2 = a.second, y3 = b.first, y4 = b.second;
    if(isInside(y1, y3, y4) && isInside(y2, y3, y4)){
        return true;
    }
    if(isInside(y3, y1, y2) && isInside(y4, y1, y2)){
        return true;
    }
    return false;
}

bool isCompletelyInsideHor(ii a, ii b) {
    int y1 = a.first, y2 = a.second, y3 = b.first, y4 = b.second;
    if(isInside(y1, y3, y4) && isInside(y2, y3, y4)){
        return true;
    }
    if(isInside(y3, y1, y2) && isInside(y4, y1, y2)){
        return true;
    }
    return false;
}

bool isIntersect(ii a, ii b){
    int y1 = a.first, y2 = a.second, y3 = b.first, y4 = b.second;
    // int x1 = a.first.first, y1 = a.first.second, x2 = a.second.first, y2 = a.second.second;
    // int x3 = b.first.first, y3 = b.first.second, x4 = b.second.first, y4 = b.second.second;
    if(isCompletelyInside(a, b)){return false;}
    if(isInside(y1, y3, y4) || isInside(y2, y3,y4)){return true;}
    if(isInside(y3, y1,y2) || isInside(y4, y1,y2)){return true;}
    return false;
    // if(x1 == x2 && x3 == x4 && x1 == x3) {
    //  if(y3 <= y1 && y1 <= y4){return true;}
    //  else if(y3 <= y2 && y2 <= y4){return true;}
    //  else if(y1 <= y3 && y3 <= y2){return true;}
    //  else if(y1 <= y4 && y4 <= y2){return true;}
    //  else{return false;}
    // }else if(y1 == y2 && y3 == y4 && y1 == y3) {
    //  if()
    // }
}

int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        ver.pb(iiii(ii(x1,y1), iii(ii(x1,y2), 0)));

        ver.pb(iiii(ii(x2,y1), iii(ii(x2,y2), 1)));
        hor.pb(iiii(ii(x1,y1), iii(ii(x2,y1), 0)));
        hor.pb(iiii(ii(x1,y2), iii(ii(x2,y2), 1)));
    }
    sort(ver.begin(), ver.end(), cmp);
    sort(hor.begin(), hor.end(), cmpHor);
    set<ii> s;
    set<ii>::iterator it;
    for(i=0;i<ver.size();i++){
        iiii a = ver[i];
        int y1 = a.first.second, y2 = a.second.first.second, x = a.first.first;
        int isEnd = a.second.second;
        // printf("x: %d y1: %d y2: %d isEnd: %d\n",x, y1,y2,isEnd);
        //cari apakah ada yang intersect
        it = s.lower_bound(ii(y1,y2));
        if(it != s.end()){
            ii a = *it;
            ii b = ii(-1,-1);
            if(it != s.begin()){
                it--;
                b = *it;
            }
            // printf("ga end\n");
            // printf("a: %d %d b: %d %d\n",a.first, a.second, b.first, b.second);
            if(isIntersect(ii(y1,y2), a)){printf("1\n"); return 0;}
            if(isIntersect(ii(y1,y2), b)){printf("1\n"); return 0;}
        }else{
            // printf("masuk sini\n");
            ii a = ii(-1,-1);
            if(it != s.begin()){
                it--;
                a = *it;
            }
            // printf("a: %d %d\n",a.first, a.second);
            if(isIntersect(ii(y1,y2), a)){printf("1\n"); return 0;}
        }
        //kalo ga ada insert / delete
        if(isEnd){
            s.erase(ii(y1,y2));
        }else{
            s.insert(ii(y1,y2));

        }
        
    }
    s.clear();
    for(i=0;i<hor.size();i++){
        iiii a = hor[i];
        int x1 = a.first.first, x2 = a.second.first.first, y = a.first.second;
        int isEnd = a.second.second;
        // printf("x: %d y1: %d y2: %d isEnd: %d\n",x, y1,y2,isEnd);
        //cari apakah ada yang intersect
        it = s.lower_bound(ii(x1,x2));
        if(it != s.end()){
            ii a = *it;
            ii b = ii(-1,-1);
            if(it != s.begin()){
                it--;
                b = *it;
            }
            // printf("ga end\n");
            // printf("a: %d %d b: %d %d\n",a.first, a.second, b.first, b.second);
            if(isIntersect(ii(x1,x2), a)){printf("1\n"); return 0;}
            if(isIntersect(ii(x1,x2), b)){printf("1\n"); return 0;}
        }else{
            // printf("masuk sini\n");
            ii a = ii(-1,-1);
            if(it != s.begin()){
                it--;
                a = *it;
            }
            // printf("a: %d %d\n",a.first, a.second);
            if(isIntersect(ii(x1,x2), a)){printf("1\n"); return 0;}
        }
        //kalo ga ada insert / delete
        if(isEnd){
            s.erase(ii(x1,x2));
        }else{
            s.insert(ii(x1,x2));

        }
    }
    printf("0\n");
    return 0;
};