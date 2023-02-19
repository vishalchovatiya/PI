#include <iostream>
#include <vector>
#include "utils.hpp"

using namespace std;

using s64 = int64_t;
using u64 = uint64_t;
using arr = vector<s64>;

// Horner’s method evaluates polynomial in O(n) time
s64 horner_poly_eval(const arr &coeff, const s64 x) {
    s64 result = coeff[0];

    for (size_t i = 1; i < coeff.size(); i++)
        result = result*x + coeff[i];

    return result;
}

s64 horner_poly_eval_recursive(const arr &coeff, const s64 x) {
    if(coeff.size()==1) return coeff[0];

    auto it = end(coeff)-1;
    return horner_poly_eval_recursive({begin(coeff), it}, x)*x + *it;
}

int main() {
    // 2x^3 + 6x^2 + 2x + 1 = ((2x + 6)x + 2)x + 1
    arr poly = {1, 1, 1, 1};

    DEBUG(horner_poly_eval_recursive(poly, 2));

    return 0;
}
