#include <iostream>
#include <vector>
#include <cmath>
#include "utils.hpp"

using namespace std;

using arr = vector<u32>;

u32 digits(u64 n) {
  return floor(log10(n) + 1);
}

u64 karatsuba_multiply(const u64& num1, const u64& num2){
    if(num1 < 10 & num2 < 10) return num1 * num2;

    u64 half = max(digits(num1), digits(num2)) / 2;
    u64 power = pow(10, half);

    u64 a = num1 / power;
    u64 b = num1 % power;
    u64 c = num2 / power;
    u64 d = num2 % power;

    u64 ac = karatsuba_multiply(a, c);
    u64 bd = karatsuba_multiply(b, d);
    u64 ad_plus_bc = karatsuba_multiply(a+b, c+d) - ac - bd;

    return ac * pow(10, 2*half) \
            + ad_plus_bc * pow(10, half) \
            + bd;
}

u64 karatsuba_square(const u64& num){
    if(num < 10) return num * num;

    u64 n = digits(num);
    u64 power = pow(10, (n / 2));

    u64 a = num / power;
    u64 b = num % power;

    u64 aa = karatsuba_square(a);
    u64 bb = karatsuba_square(b);
    u64 _2ab = karatsuba_square(a+b) - aa - bb;

    return aa * pow(10, n) \
            + _2ab * pow(10, (n/2)) \
            + bb;
}

int main() {
    
    DEBUG(karatsuba_multiply(100, 15));
    DEBUG(karatsuba_square(12));
    DEBUG(karatsuba_square(13));
    DEBUG(karatsuba_square(14));
    DEBUG(karatsuba_square(100));

    return 0;
}
