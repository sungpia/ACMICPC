#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void getInput();
void solve(int, int, vector<int> []);

int main(void) {
    getInput();
}

void getInput() {
    int T;
    cin >> T;
    while(T--) {
        int val, colNum;
        cin >> val >> colNum;
        vector<int> canoes[4];

        for(int i=0; i<4; ++i) {
            for(int j=0; j<colNum; ++j) {
                int v;
                cin >> v;
                canoes[i].push_back(v);
            }
        }

        solve(val, colNum, canoes);
    }
}

void solve(int val, int colNum, vector<int> data[4]) {
    //TODO: preprocess four rows
    vector<int> a;
    vector<int> b;

    for(int i=0; i<colNum; ++i) {
        for(int j=0; j<colNum; ++j) {
            a.push_back(data[0][i] + data[1][j]);
            b.push_back(data[2][i] + data[3][j]);
        }
    }


    int closest = -2100000000;
    sort(b.begin(), b.end());

    for(int i=0; i<a.size(); ++i) {
        auto searchValue = val - a[i];
        auto lowerBound = lower_bound(b.begin(), b.end(), searchValue);
        if(lowerBound == b.end()) lowerBound--;
        auto upperWeight = *lowerBound;
        auto lowerWeight = lowerBound==b.begin() ? *lowerBound : *(--lowerBound);
//        cout << lowerWeight << " : " << upperWeight << endl;
        if( abs( lowerWeight - searchValue) <= abs(upperWeight - searchValue) ){
            if( abs(lowerWeight - searchValue) <= abs(closest - a[i] - searchValue) ) closest = lowerWeight + a[i];
        }
        else {
            if( abs(upperWeight - searchValue) < abs(closest - a[i] - searchValue)) closest = upperWeight + a[i];
        }
    }

    cout << closest << endl;

}
