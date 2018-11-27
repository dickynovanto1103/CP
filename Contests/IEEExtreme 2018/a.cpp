#include <bits/stdc++.h>

using namespace std;
#define NMAX 200000

long long sz[NMAX+5];
long long tz[NMAX+5];
long long s_tz[NMAX+5];
int par[NMAX+5];
int s_par[NMAX+5];
int s_chi[NMAX+5];
int s_lca[NMAX+5];
int d[NMAX+5];
string names[NMAX+5];

vector <int> C[NMAX+5];
map <string,int> M;
stack <int> S;
int NN,QQ;

void PopNode () {
    int i = S.top();
    if (tz[i] != 0) s_tz[par[i]] += tz[i];
    else s_tz[par[i]] += s_tz[i];
    if (s_lca[par[i]] != par[i] && tz[i] == 0 && s_lca[i] != -1) {
        if (s_lca[par[i]] != -1)
        	s_lca[par[i]] = par[i];
       	else s_lca[par[i]] = s_lca[i];
    }
    S.pop();
}

void PushNode (int i) {
    S.push(i);
    if (tz[i] != 0) {
        s_par[i] = i;
    } else s_par[i] = s_par[par[i]];

    if (sz[i] != 0) {
        s_tz[i] = sz[i];
        s_lca[i] = -1;
    } else {
        ++s_chi[s_par[i]];
        s_tz[i] = 1;
        s_lca[i] = i;
    }
}

int indeks = 0;

void dfs(int node){
    d[indeks++] = node;
    for(int i=0;i<C[node].size();i++){
        int v = C[node][i];
        dfs(v);
    }
}

int main () {
    cin >> NN >> QQ;
    M["NONE"] = 0;
    sz[0] = 0;
    tz[0] = 6000000001;
    par[0] = 0;
    s_tz[0] = 0;
    int cnt = 1;
    for (int i = 1; i <= NN; ++i) {
        string name, parent;
        long long ukuran, semua;
        cin >> name >> parent >> ukuran >> semua;
        
        if(M.find(name) == M.end()){
            M[name] = cnt++;
        }
        if (M.find(parent) == M.end())
            M[parent] = cnt++;
        
        int indeksName = M[name];
        names[indeksName] = name;
        sz[indeksName] = ukuran;
        tz[indeksName] = semua;
        par[indeksName] = M[parent];
        C[par[indeksName]].push_back(indeksName);
        //printf("yang dipush: %d ke %d\n",par[i],indeksName);
    }
    //printf("map dari company: %d\n",M["company"]);

    dfs(0);
    //printf("indeks: %d\n",indeks);
    // for(int i=0; i<indeks;i++){
    //     printf("d[%d]: %d\n",i,d[i]);
    // }
    //printf("halo\n");

    PushNode(0);
    //printf("wou");
    for (int i = 1; i <= NN; ++i) {
        while (!S.empty() && S.top() != par[d[i]])
            PopNode();
        PushNode(d[i]);
    }
    //printf("gan\n");
    while (!S.empty() && S.top() != 0) PopNode();
    //printf("halo halo\n");

    // for (int i = 0; i <= NN; ++i)
    //     cout << i << ' ' << names[i] << ' ' << sz[i] << ' ' << tz[i] << ' ' << s_tz[i] << ' ' << par[i] << ' ' << s_par[i] << ' ' << s_chi[i] << ' ' << s_lca[i] << '\n';

    for (int i = 0; i < QQ; ++i) {
        string query;
        int query1;
        cin >> query >> query1;
        int k = M[query];
        if (query1 == 1) {
            if (sz[k] != 0) cout << sz[k] << ' ' << sz[k] << '\n';
            else {
                int l = s_par[k];
                if (s_chi[l] == 1) {
                    cout << tz[l]-s_tz[l]+1 << ' ' << tz[l]-s_tz[l]+1 << '\n';
                } else {
                    cout << 1 << ' ' << tz[l]-s_tz[l]+1 << '\n';
                }
            }
        } else {
            if (tz[k] != 0) cout << tz[k] << ' ' << tz[k] << '\n';
            else {
            	//cout << names[k] << ' ' << names[s_lca[k]] << '\n';
                int l = s_par[k];
                if (s_lca[k] == -1) {
                	cout << s_tz[k] << ' ' << s_tz[k] << '\n';
                } else if (s_lca[k] == s_lca[l]) {
                    cout << s_tz[k]+tz[l]-s_tz[l] << ' ' << s_tz[k]+tz[l]-s_tz[l] << '\n';
                } else {
                	//printf("halo\n");
                    cout << s_tz[k] << ' ' << s_tz[k]+tz[l]-s_tz[l] << '\n';
                }
            }
        }
    } 
}
