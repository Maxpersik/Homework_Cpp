#include <iostream>
#include <vector>

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

void find(const string& text, const string& pattern) {
    string concat = pattern + "$" + text;
    int l = concat.length();
    vector<int> Z;

    create_Zarr(concat, Z);

    int count = 0;

    for (int i = 0; i < l; ++i) {
        if (Z[i] == pattern.length() and pattern.length() != 0) {
            count++;
            //cout << "Pattern found at index " << i - pattern.length() - 1 << endl;
        }
    }

    //std::cout << "len Z = " << Z.size() << std::endl;
    //std::cout << "count = " << count << std::endl;

    if (count > 0) {
        std::cout << "true" << std::endl;
    }
    else {
        std::cout << "false" << std::endl;
    }
}

// Driver program
int main() {
    string text = "aaabbbvvvggg";
    string pattern = "bbb";
    find(text, pattern);
    return 0;
}
