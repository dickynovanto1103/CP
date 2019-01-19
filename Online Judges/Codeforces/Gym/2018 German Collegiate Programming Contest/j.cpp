#include <bits/stdc++.h>
using namespace std;

int n;
int ed[300005][5];
int up[300005];
vector<int> edges[300005];

inline int get_up_bridge(int piece) { return ed[piece][(up[piece] + 0) % 4]; }
inline int get_le_bridge(int piece) { return ed[piece][(up[piece] + 1) % 4]; }
inline int get_dn_bridge(int piece) { return ed[piece][(up[piece] + 2) % 4]; }
inline int get_ri_bridge(int piece) { return ed[piece][(up[piece] + 3) % 4]; }

int find_next_bottom(int piece) {
    int bridge = get_dn_bridge(piece);
    if (bridge == 0) return 0;
    assert(edges[bridge].size() == 2);
    return edges[bridge][0] + edges[bridge][1] - piece;
}

int find_next_right(int piece) {
    int bridge = get_ri_bridge(piece);
    if (bridge == 0) return 0;
    assert(edges[bridge].size() == 2);
    return edges[bridge][0] + edges[bridge][1] - piece;
}

int solve() {
    for (int i=0; i<300005; i++) edges[i].clear();
    int next_row = 0;
    for (int i=1; i<=n; i++) {
        int cnt_nol = 0;
        for (int j=0; j<4; j++) {
            scanf("%d", &ed[i][j]);
            if (ed[i][j] != 0) edges[ed[i][j]].push_back(i);
            if (ed[i][j] == 0) cnt_nol++;
        }
        if (cnt_nol >= 2) {
            next_row = i;
            if (ed[i][1] == 0 && ed[i][2] == 0) up[i] = 1;
            if (ed[i][2] == 0 && ed[i][3] == 0) up[i] = 2;
            if (ed[i][3] == 0 && ed[i][0] == 0) up[i] = 3;
            if (ed[i][0] == 0 && ed[i][1] == 0) up[i] = 0;
        }
    }
    if (next_row == 0) {
        printf("impossible\n");
        return 4;
    }

    vector<vector<int> > g;
    while (next_row != 0) {
        int s = next_row;
        next_row = find_next_bottom(s);
        //printf("%d bawahnya %d\n", s, next_row);
        if (next_row != 0) {
            if (ed[next_row][0] == ed[s][(up[s] + 2) % 4]) up[next_row] = 0;
            if (ed[next_row][1] == ed[s][(up[s] + 2) % 4]) up[next_row] = 1;
            if (ed[next_row][2] == ed[s][(up[s] + 2) % 4]) up[next_row] = 2;
            if (ed[next_row][3] == ed[s][(up[s] + 2) % 4]) up[next_row] = 3;
        }
        vector<int> v;
        do {
            v.push_back(s);
            int ns = find_next_right(s);
            if (ed[ns][1] == ed[s][(up[s] + 3) % 4]) up[ns] = 0;
            if (ed[ns][2] == ed[s][(up[s] + 3) % 4]) up[ns] = 1;
            if (ed[ns][3] == ed[s][(up[s] + 3) % 4]) up[ns] = 2;
            if (ed[ns][0] == ed[s][(up[s] + 3) % 4]) up[ns] = 3;
            s = ns;
        } while (s != 0);
        g.push_back(v);
    }

    int row = g.size(), col = g[0].size();

    if (row * col != n) {
        printf("impossible\n");
        return 3;
    }

    for (const vector<int>& v : g) {
        if (v.size() != col) {
            printf("impossible\n");
            return 2;
        }
    }

    bool valid = true;
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            int cell = g[i][j];
            if (i == 0)       { if (get_up_bridge(cell) !=                        0) valid = false; }
            else              { if (get_up_bridge(cell) != get_dn_bridge(g[i-1][j])) valid = false; }
            if (i == row - 1) { if (get_dn_bridge(cell) !=                        0) valid = false; }
            else              { if (get_dn_bridge(cell) != get_up_bridge(g[i+1][j])) valid = false; }
            if (j == 0)       { if (get_le_bridge(cell) !=                        0) valid = false; }
            else              { if (get_le_bridge(cell) != get_ri_bridge(g[i][j-1])) valid = false; }
            if (j == col - 1) { if (get_ri_bridge(cell) !=                        0) valid = false; }
            else              { if (get_ri_bridge(cell) != get_le_bridge(g[i][j+1])) valid = false; }
        }
    }
    if (!valid) {
        printf("impossible\n");
        return 1;
    }

    printf("%d %d\n", row, col);
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            printf("%d%c", g[i][j], (j == col-1 ? '\n' : ' '));
        }
    }
}

int main() {
    while (scanf("%d", &n) == 1) {
//        printf("%d\n",
        solve();
  //      );
        printf("\n");
    }
    return 0;
}