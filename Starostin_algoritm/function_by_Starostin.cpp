
#include <iostream>
#include "function_by_Starostin.h"
#include <vector>
#include <string>

using namespace std;

void create_Zarr(const string& str, vector<int>& Z) {
    int n = str.length();
    int left = 0, right = 0;

    Z.resize(n, 0);

    for (int i = 1; i < n; ++i) {
        if (i > right) {
            left = right = i;
            while (right < n && str[right] == str[right - left])
                right++;
            Z[i] = right - left;
            right--;
        }
        else {
            int k = i - left;
            if (Z[k] < right - i + 1) {
                Z[i] = Z[k];
            }
            else {
                left = i;
                while (right < n && str[right] == str[right - left])
                    right++;
                Z[i] = right - left;
                right--;
            }
        }
    }
}

bool z_algoritm(const string& text, const string& pattern) {
    string concat = pattern + "$" + text;
    int l = concat.length();
    vector<int> Z;
    bool u;

    create_Zarr(concat, Z);

    int count = 0;

    for (int i = 0; i < l; ++i) {
        if (Z[i] == pattern.length() && pattern.length() != 0) {
            u = true;
            break;
            //count++;
        }
        else {
            u = false;
        }
    }
    return u;
}

//// Driver program
//int main() {
//    string text = "aaabbbvvvggg";
//    string pattern = "bbb";
//    z_algoritm(text, pattern);
//    return 0;
//}
