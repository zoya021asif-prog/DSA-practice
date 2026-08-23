#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    int cnt = 0;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cnt++;

            if ((n / i) != i) {
                cnt++;
            }
        }
    }

    // Check after the loop
    if (cnt == 2) {
        cout << n << " is a prime number";
    }
    else {
        cout << n << " is not a prime number";
    }

    return 0;
}