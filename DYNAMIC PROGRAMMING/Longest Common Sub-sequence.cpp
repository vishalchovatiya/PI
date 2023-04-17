#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define DEBUG(X) cout << #X << " = " << X << endl;
#define ALL(X) begin(X), end(X)

using sequence_t = vector<uint64_t>;


// longest common subsequence dynamic programming - iterative approach (bottom up - tabulation)
sequence_t longest_common_subsequence_tabulation(const sequence_t& s1, const sequence_t& s2) {
    const uint64_t n1 = s1.size();
    const uint64_t n2 = s2.size();
    vector<vector<sequence_t>>      tab(n1 + 1, vector<sequence_t>(n2 + 1));

    for (uint64_t i = 1; i <= n1; ++i) {
        for (uint64_t j = 1; j <= n2; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                tab[i][j] = tab[i - 1][j - 1];
                tab[i][j].push_back(s1[i - 1]);
            } else {
                auto lcs1 = tab[i - 1][j];
                auto lcs2 = tab[i][j - 1];
                tab[i][j] = lcs1.size() > lcs2.size() ? lcs1 : lcs2;
            }
        }
    }

    return tab[n1][n2];
}

// longest common subsequence using dynamic programming - recursive approach (top down - memoization)
sequence_t longest_common_subsequence_memoization(const sequence_t& s1, const sequence_t& s2, uint64_t n1, uint64_t n2, vector<vector<sequence_t>>& memo) {
    if (n1 == 0 || n2 == 0) { return {}; }

    if (memo[n1][n2].size() != 0) { return memo[n1][n2]; }

    if (s1[n1 - 1] == s2[n2 - 1]) {
        auto lcs = longest_common_subsequence_memoization(s1, s2, n1 - 1, n2 - 1, memo);
        lcs.push_back(s1[n1 - 1]);
        memo[n1][n2] = lcs;
        return lcs;
    }

    auto lcs1 = longest_common_subsequence_memoization(s1, s2, n1 - 1, n2, memo);
    auto lcs2 = longest_common_subsequence_memoization(s1, s2, n1, n2 - 1, memo);
    memo[n1][n2] = lcs1.size() > lcs2.size() ? lcs1 : lcs2;
    return memo[n1][n2];
}

int main() {
    uint64_t n1;
    cin >> n1;
    sequence_t s1(n1);
    for (auto& n : s1) { cin >> n; }

    uint64_t n2;
    cin >> n2;
    sequence_t s2(n2);
    for (auto& n : s2) { cin >> n; }

    // recursive approach (top down - memoization)
    vector<vector<sequence_t>>      memoization(n1 + 1, vector<sequence_t>(n2 + 1)) ;
    auto lcs = longest_common_subsequence_memoization(s1, s2, n1, n2, memoization);

    // print the longest common subsequence
    cout << lcs.size() << endl;
    for (auto& n : lcs) { cout << n << " "; }

    return 0;
}

/*
/CP/build/main < ../input.txt > ../output.txt

Test Case 1:
5
0 1 5 3 4
4
1 5 3 8

3
1 5 3

Test Case 2:

4
1 2 3 4
4
2 4 6 8

2
2 4

Test Case 3:

5
1 2 3 4 5
3
3 2 1

1
3 

Test Case 4:

3
1 2 3
3
3 2 1

1
3 


Test Case 5:

6
1 2 3 4 5 6
4
4 5 6 7

3
4 5 6 

Test Case 6:

5
1 3 5 7 9
6
2 4 6 8 10 12

Expected output: None (There is no common subsequence)
 */
