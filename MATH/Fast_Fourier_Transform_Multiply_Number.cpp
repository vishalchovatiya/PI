#include "utils.hpp"
#include <iostream>
#include <cmath> // exp, acos
#include <complex>

/* 
    Multiplying two numbers with Fast Fourier Transform(FFT)

    FFT = polynomial to point value representation
    Inverse-FFT/Interpolation = point value representation to polynomial 

*/

using cd = complex<double>;
const double PI = acos(-1);

void FFT(vector<cd>& p, bool inverse=false) {
    u64 n = p.size();
    if (n == 1)
        return;

    vector<cd> even_terms(n / 2), odd_terms(n / 2);
    for (u64 i = 0; 2 * i < n; i++) {
        even_terms[i] = p[2*i];
        odd_terms[i] = p[2*i+1];
    }
    FFT(even_terms, inverse);
    FFT(odd_terms, inverse);

    const double angle = 2 * PI / n * (inverse ? -1 : 1);
    cd w(1), wn(cos(angle), sin(angle));
    for (u64 i = 0; 2 * i < n; i++) {
        p[i] = even_terms[i] + w * odd_terms[i];
        p[i + n/2] = even_terms[i] - w * odd_terms[i];
        if (inverse) {
            p[i] /= 2;
            p[i + n/2] /= 2;
        }
        w *= wn;
    }
}

// Horner’s method evaluates polynomial in O(n) time
s64 horner_poly_eval(const vector<s64> &coeff, const s64 x) {
    s64 result = coeff[0];

    for (size_t i = 1; i < coeff.size(); i++)
        if(coeff[i]) 
            result = result*x + coeff[i];

    return result;
}

s64 multiply(const vector<s64>& a, const vector<s64>& b) {
    vector<cd> fa(ALL(a));
    vector<cd> fb(ALL(b));

    // Make n to power of 2
    u64 n = 1;
    while ( n < (a.size() + b.size()) ) n <<= 1;
    fa.resize(n);
    fb.resize(n);

    // Convert polynomial to point value representation
    FFT(fa);
    FFT(fb);

    // Multiply the point value representation
    for (u64 i = 0; i < n; i++) fa[i] *= fb[i];
    
    // Convert point value to polynomial representation
    FFT(fa, true);

    // Round the complex number to intgral 
    vector<s64> result(n);
    for (u64 i = 0; i < n; i++)
        result[i] = round(fa[i].real());

    return horner_poly_eval(result, 10);
}

int main() {
    vector<s64> polynomial = {1, 2, 3};

    DEBUG(multiply(polynomial, polynomial));

    return 0;
}
