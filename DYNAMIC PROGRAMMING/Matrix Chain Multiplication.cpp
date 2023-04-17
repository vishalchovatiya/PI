#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define DEBUG(X) cout << #X << " = " << X << endl;
#define ALL(X) begin(X), end(X)



uint64_t matrix_chain_multiplication_recursive(const vector<uint64_t>& p, uint64_t i, uint64_t j) {
    if (i == j) return 0; 
    uint64_t min_cost = numeric_limits<uint64_t>::max();
    for (uint64_t k = i; k < j; ++k) {
        uint64_t cost = matrix_chain_multiplication_recursive(p, i, k) 
                        + matrix_chain_multiplication_recursive(p, k+1, j) 
                        + p[i-1] * p[k] * p[j];
        min_cost = min(min_cost, cost);
    }
    return min_cost;
}

// Matrix Chain Multiplication - Dynamic Programming - Top Down - Memoization
uint64_t matrix_chain_multiplication_memoization(const vector<uint64_t>& p, uint64_t i, uint64_t j, vector<vector<uint64_t>>& memo) {
    if (i == j) return 0; 
    if (memo[i][j] != 0) return memo[i][j];
    
    uint64_t min_cost = numeric_limits<uint64_t>::max();
    for (uint64_t k = i; k < j; ++k) {
        uint64_t cost = matrix_chain_multiplication_memoization(p, i, k, memo) 
                        + matrix_chain_multiplication_memoization(p, k+1, j, memo) 
                        + p[i-1] * p[k] * p[j];
        min_cost = min(min_cost, cost);
    }
    memo[i][j] = min_cost;
    return min_cost;
}


int main() {
    uint64_t n;
    cin >> n;
    vector<uint64_t>    matrix_chain_dimentions(n);
    for (uint64_t i = 0; i < n; i++) {
        cin >> matrix_chain_dimentions[i];
    }

    DEBUG(matrix_chain_multiplication_recursive(matrix_chain_dimentions, 1, n-1));

    return 0;
}

/*
/CP/build/main < ../input.txt > ../output.txt

Test Case 1:

Test Case 2:


Test Case 3:

Test Case 4:

 */
