#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n, x, y, t;
vector<int> cur;

void gen(int i, int q){
    int pos = t-q;
    if (i == n){
        for (int j = pos; j < t; ++j) cur[j] = n;
        cout << "{";
        for (int j = 0; j < cur.size(); ++j) cout << (j == 0 ? "" : ",") << cur[j];
        cout << "}\n";
    }
    else{
        for (int k = max(x, q-(n-i)*y); q-k >= (n-i)*x and k <= y; ++k){
            fill(cur.begin() + pos, cur.begin() + pos + k, i);
            gen(i+1, q-k);
        }
    }
}

int main(){
    cin >> n >> x >> y >> t;
    cur = vector<int> (t);
    gen(1, t);
}

//Si teniu algun dubte sobre el que fa, aquest codi l'ha escrit el Miquel Ortega