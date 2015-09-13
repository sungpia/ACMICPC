#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

array<int, 1000000> fibo;
void getInput();
void solve(int);
void preprocess() {
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i=2; i<1000000; ++i) {
        fibo[i] = fibo[i-2] + fibo[i-1];
    }
}

int main(void) {
    preprocess();
    getInput();
    return 0;
}

void getInput() {
    int T;
    int num;

    cin >> T;
    while(T--) {
        cin >> num;
        solve(num);
    }
}

void solve(int num) {
    int n=0;
    vector<int> sumElements;
    while(fibo[n++] < num);

    for(int i=n-1; i>=1; i--) {
        if(num >= fibo[i]) {
            num = num - fibo[i];
            sumElements.push_back(fibo[i]);
        }
    }

    reverse(sumElements.begin(), sumElements.end());


    for(auto s : sumElements) {
        cout << s << " ";
    }
    cout << endl;
}
