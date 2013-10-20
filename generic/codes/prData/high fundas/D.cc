#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

vector<string> Tokenize(string s, string ch) {
  vector<string> ret;
  for (int p = 0, p2; p < s.size(); p = p2+1) {
    p2 = s.find_first_of(ch, p);
    if (p2 == -1) p2 = s.size();
    if (p2-p > 0) ret.push_back(s.substr(p, p2-p));
  }
  return ret;
}

vector<int> TokenizeInt(string s, string ch) {
  vector<int> ret;
  vector<string> p = Tokenize(s, ch);
  for( int i = 0; i < p.size(); i++ )
    ret.push_back(atoi(p[i].c_str()));
  return ret;
}

VI Cpos, Cv;
int S, b[100][100];
VVI Cd1, Cd2, Cd3;
bool seen[100][100];

int BipartiteMatch(const VVI &m) {
  int V = m.size() * 2 + 2;
  VVI d(V, VI(V, 1000000000));
  for (int i = 0; i < S; i++) d[V-2][i] = 0;
  for (int i = 0; i < S; i++) d[i+S][V-1] = 0;
  for (int i = 0; i < S; i++)
  for (int j = 0; j < S; j++)
    d[i][j+S] = m[i][j];
  int ret = 0;
  for (int i = 0; i < S; i++) {
    VI dist(V, 1000000000), prev(V, 1000000000);
    dist[V-2] = 0;
    bool change = true;
    while (change) {
      change = false;
      for (int x = 0; x < S*2+2; x++)
      for (int y = 0; y < S*2+2; y++) if (d[x][y] < 1000000000) {
        if (dist[x] + d[x][y] < dist[y]) {
          dist[y] = dist[x] + d[x][y];
          prev[y] = x;
          change = true;
        }
      }
    }
    ret += dist[V-1];
    for (int x = V-1; x != V-2; x = prev[x]) {
      d[x][prev[x]] = -d[prev[x]][x];
      d[prev[x]][x] = 1000000000;
    }
  }
  return ret;
}

main() {
  int N, prob = 1;
  string s;
  getline(cin, s);
  for (N = atoi(s.c_str()); N--;) {
    getline(cin, s);
    Cpos = TokenizeInt(s, " ");
    getline(cin, s);
    Cv = TokenizeInt(s, " ");
    S = Cpos.size();
    memset(b, 0, sizeof(b));
    int cur = 1;
    for (int y = 1; y <= (S+1)/2; y++)
    for (int x = 1; x <= y + S/2; x++)
      b[y][x] = cur++;
    for (int y = 1; y < (S+1)/2; y++)
    for (int x = y+1; x <= S; x++)
      b[y+(S+1)/2][x] = cur++;
    Cd1 = Cd2 = Cd3 = VVI(S, VI(S));
    for (int i = 0; i < S; i++) {
      int y, x;
      for (y = 1; y <= S; y++)
      for (x = 1; x <= S; x++)
        if (b[y][x] == Cpos[i]) goto found;
found:
      memset(seen, 0, sizeof(seen));
      vector<pair<int, int> > q;
      q.push_back(make_pair(x, y));
      int dist = 0;
      while (!q.empty()) {
        vector<pair<int, int> > q2;
        while (!q.empty()) {
          x = q.back().first; y = q.back().second; q.pop_back();
          if (seen[y][x] || !b[y][x]) continue;
          seen[y][x] = true;
          if (y == (S+1)/2) Cd1[i][x-1] = dist * Cv[i];
          if (x == (S+1)/2) Cd2[i][y-1] = dist * Cv[i];
          if (x == y)       Cd3[i][x-1] = dist * Cv[i];
          q2.push_back(make_pair(x+1, y));
          q2.push_back(make_pair(x-1, y));
          q2.push_back(make_pair(x, y+1));
          q2.push_back(make_pair(x, y-1));
          q2.push_back(make_pair(x+1, y+1));
          q2.push_back(make_pair(x-1, y-1));
        }
        q.swap(q2);
        dist++;
      }
    }
    cout << "Case #" << prob++ << ": ";
    cout << (BipartiteMatch(Cd1) <? BipartiteMatch(Cd2) <? BipartiteMatch(Cd3));
    cout << endl;
  }
}
