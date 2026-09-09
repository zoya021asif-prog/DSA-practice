#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int i) {

        
        if (i >= s.size() / 2) {
            return true;
        }

       
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }

        
        return isPalindrome(s, i + 1);
    }
};

int main() {

    string s;

    cout << "Enter a string: ";
    cin >> s;

    Solution obj;

    if (obj.isPalindrome(s, 0)) {
        cout << "Palindrome";
    } else {
        cout << "Not Palindrome";
    }

    return 0;
}