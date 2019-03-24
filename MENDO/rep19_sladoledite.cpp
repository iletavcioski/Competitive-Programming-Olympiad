#include <iostream>
#include <vector>
 
using namespace std;
 
int sladoledi[300000];
int lca[300000][20];
int dep[300000];
 
int lca1(int x, int y) {
    if (dep[x] > dep[y]) {
        for (int i = 19; i >= 0; i--) {
            if (lca[x][i] != -1 && dep[lca[x][i]] >= dep[y]) {
                x = lca[x][i];
            }
        }
        //x = lca[x][0];
    }
    else if (dep[x] < dep[y]) {
        for (int i = 19; i >= 0; i--) {
            if (lca[y][i] != -1 && dep[lca[y][i]] >= dep[x]) {
                y = lca[y][i];
            }
        }
        //y = lca[y][0];
    }
    if (x == y)
        return x;
    for (int i = 19; i >= 0; i--) {
        if (lca[x][i] != lca[y][i]) {
            x = lca[x][i];
            y = lca[y][i];
        }
    }
 
    return lca[x][0];
}
 
void qa(int a, int bs, int bt) {
    int x = sladoledi[a];
    lca[bt][0] = x;
    for (int i = 1; i < 20; i++) {
        if (lca[bt][i - 1] != -1) {
            lca[bt][i] = lca[lca[bt][i - 1]][i - 1];
        }
    }
    sladoledi[bs] = bt;
    dep[bt] = dep[x] + 1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
 
    for (int i = 0; i < 300000; i++) {
        for (int j = 0; j < 20; j++) {
            lca[i][j] = -1;
        }
    }
 
    int n;
    cin >> n;
 
    int bs = 0;
    sladoledi[0] = 0;
    dep[0] = 0;
    int bt = 0;
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
 
        if (ch == 'a') {
            int br;
            cin >> br;
 
            bs++;
            bt++;
            qa(br, bs, bt);
        }
        else if (ch == 'b') {
            int br;
            cin >> br;
            cout << sladoledi[br] << endl;
            bs++;
            bt++;
            sladoledi[bs] = lca[sladoledi[br]][0];
        }
        else {
            int aa, bb;
            cin >> aa >> bb;
            aa = sladoledi[aa];
            bb = sladoledi[bb];
            int x = lca1(aa, bb);
            bs++;
            bt++;
            sladoledi[bs] = aa;
            cout << dep[x] << endl;
        }
    }
    return 0;
}