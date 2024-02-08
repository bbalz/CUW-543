#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string longestCommonSubstring(const std::string& str1, const std::string& str2) {
    int len = str1.length();
    std::vector<std::vector<int>> dp(len + 1, std::vector<int>(len + 1));
    int maxLength = 0, endIdx = 0;

    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= len; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIdx = i;
                }
            }
        }
    }

    for (int i = 0; i <= len; ++i) {
        for (int j = 0; j <= len; ++j) {
            std::cout << dp[i][j] << " ";
        }
        std::cout << "\n";
    }

    return str1.substr(endIdx - maxLength, maxLength);
}

int main() {
    std::string str1 = "ABAB";
    std::string str2 = "BABA";

    std::cout << "Input strings: \"" << str1 << "\" and \"" << str2 << "\"\n";
    std::string lcs = longestCommonSubstring(str1, str2);
    std::cout << "Longest Common Substring: " << lcs << "\n";

    return 0;
}
