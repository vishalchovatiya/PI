/*
Q: Given a list of numbers where every number is occuring thrice except one number we have to find out the unique number which is occuring just one time.

Explanation:
Since all other numbers are occuring thrice, we need to cancel all the bits occuring thrice(contriubted by repeating numbers) - so we take sum of bits at every positions(in all numbers) and take mod by 3 for every position. We maintain a array of size 64 to handle 64 bit integers. Watch the video to learn more.

*/
#include <bits/stdc++.h>

#define DEBUG(X) std::cout << #X << " = " << X << std::endl;
#define PRINT(C, WAY)                      \
    do                                     \
    {                                      \
        cout << setw(10) << #C << " : \n"; \
        for (auto &&i : C)                 \
        {                                  \
            WAY;                           \
        }                                  \
        cout << endl;                      \
    } while (0);
#define ALL(C) (C).begin(), (C).end()
#define RALL(C) (C).rbegin(), (C).rend()
#define PRESENT(C, X) ((C).find() != (C).end())

using ll = long long;
using namespace std;

ll getUnique(vector<ll> &v, ll noFreq)
{
    ll bitSetHash[5] = {0};

    for (auto n : v)
    {
        ll bitNo = 0;
        while (n)
        {
            if (n & 1)
            {
                bitSetHash[bitNo]++;
            }
            bitNo++;
            n = n >> 1;
        }
    }

    // PRINT(bitSetHash, cout << i << " ");

    bitset<5> res;
    for (ll bitNo = 0; bitNo < 5; bitNo++)
    {
        if (bitSetHash[bitNo] % noFreq)
            res.set(bitNo);
    }

    return res.to_ullong();
}

int main()
{
    ll N;
    ll firstIter = 0;
    cin >> N;

    vector<ll> v(N);

    for (ll i = 0; i < N; i++)
    {
        ll temp;
        cin >> temp;
        v[i] = temp;
    }

    cout << getUnique(v, 3) << endl;

    return 0;
}
