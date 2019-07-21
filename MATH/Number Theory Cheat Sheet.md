

## Number Theory
> **Divisors**
- **Number divisible by**: Numbers less than 1000 that is divisible by 5 = 1000/5.
- **Number of divisor(prime factorization & power multiply)**:for example, no of divisor of 24 = 1,2,3,4,6,8,12,24 = 8. Prime factorization 2 x 2 x 2 x 3 = 2^(3) x 3^(1) = (3+1) x (1+1) <multiply powers> = 8.

For example, suppose we want to count (or find all of) the divisors of n = 144.

Begin by forming the prime factorization of 144:

144 = 24 . 32.

So any divisor of 144 must be a product of some number of 2's (between 0 and 4) and some number of 3's (between 0 and 2). So here's a table of the possibilities:

|2^0 |	2^1 |	2^2 |	2^3|	2^4|
|3^0 |	1 |	2	  |  4	|8	|16|
|3^1 |	3 |	6	  |  12|	24|	48|
|3^2 |	9 |	18  |	36	|72	|144|

From the table, it's easy to see that there are 5 x 3 = 15 divisors of 144.

> **What is mean by square root of any no?**
- It means that one of its factor will be less than square root of no & one will be larger.
- For example: N = 36, square root of N = 6; all the factor of 36 are
```
1. 18 x 2  = 36
2. 12 x 3  = 36
3. 9 x 4   = 36
4. 6 x 6   = 36
```
So, square root is wokring like partition of two factor of given N.

> **Prime number**
- Its whole number unlike composite number which made up different factors.
- Even nos can't be prime except 2.
- If you plot the fibonacci numbers in spiral form, all diagonals are prime nos.
- Primes are used in cryptography coz you can not generate combination or patterns out of it so wont be decrypted easily.
- Prime with three unique factors = square of prime numbers, for example: 4(1,2,4), 9(1,3,9), 25(1,5,25)

> **Sieve of eratosthenes**
1. Brute force 
2. Square root optimization
3. Square of no optimization

> **Segmented Sieve**
- For example: All primes b/w 25 to 36
- Step 1: Find list of primes upto square root of ‘n’(upper bound) i.e. 36 which comes out to 6.
- Step 2: Cancell all no b/w 25 to 36 which are divisible by list of primes found in step 1


> **Modulo Property**
- `(a + b) % m = ((a % m) + (b % m)) % m`
- `(a * b) % m = ((a % m) * (b % m)) % m`
- `(a - b) % m = ((a % m) - (b % m) + m) % m`
- `(a / b) % m = ((a % m) * (b^-1 % m)) % m`, where `b^-1` is MMI


> **Modular multiplicative inverse(MMI)**
- `ax % m = 1`, here x is mmi(modular multiplicative inverse)
- above equation exist if and only if a & m are coprime(`gcd(a,m) = 1`).
- `a⋅x+m⋅y=1` using extended Euclidean algo.

> **Euclid's algo for GCD**
- GCD(a,b) = GCD(b, a%b)
- GCD(a,0) = a

> **LCM**
- `GCD(a,b) x LCM(a,b) = a x b`

> **Extended Euclid's algo(EE algo)**
- `ax + by = gcd(a, b)`
- `gcd(a,b) = gcd(b, a%b)`
- `bx + (a%b)y = gcd(b, a%b)`
- `(a%b) = a - ⌊a/b⌋b`
- `x = y1 - ⌊b/a⌋ * x1`
- `y = x1`

> **Euclidean algo generate fibonacci sequence in reverse manner for every remainder**
- For example: `GCD(55,34)`
```
GCD(55,34)       = GCD(34,55%34)     = GCD(34, 21)
GCD(34, 21)      = GCD(21,34%21)     = GCD(21, 13)
GCD(21, 13)      = GCD(13,21%13)     = GCD(13, 8)
GCD(13, 8)       = GCD(8,13%8)       = GCD(8, 5)
GCD(8,5)         = GCD(5,8%5)        = GCD(5, 3)
GCD(5,3)         = GCD(3,5%3)        = GCD(3, 2)
GCD(3,2)         = GCD(2,3%2)        = GCD(2, 1)
GCD(2, 1)        = GCD(1,2%1)        = GCD(1, 0)

GCD(55,34) = 1
```
- If you observe all the remainders it generates sequence like 21, 13, 8, 5, 3, 2, 1, 0 whichi is reverse fibonacci

- Relation : GCD(F(m),F(n))=F(GCD(m,n))
- For example: `0,1,1,2,3,5,8,13,21,34,55,89,144,...`
- `GCD(144,22) = 3` which is position in fibonacci sequence.

> **Linear Diophantine Equation(LDE)**
- `ax + by = c`, has solution if `c` divisible by `g`. 

> **Application of EE algo**
```
                                                                                                          
                              Extended Euclidean Algo                                                     
                          ax + by = g, where g = gcd(a,b)                                                 
                                                                                                          
                                    --  -\                                                                
                                ---/      ---\                                                            
                             --/              ---\                                                        
                         ---/                     --\                                                     
                     ---/                            ---\                                                 
                   -/                                    ---\                                             
                                                             --                                           
                MMI                                               LDE                                     
  condition: gcd(a,m) = 1, coprime                 condition: c % g = 0                                   
                                                                                                          
  MMI: ax % m = 1                                  LDE: ax + by = c                                       
                                                                                                          
  ax + by = g <= EE                                c % g = 0, c = gk & k = c / g, where k is some constant
  ax + my = gcd(a,m) = 1
                                                                                                          
  taking modulo both side                          multiply both side with k                              
                                                                                                          
  ax % m + 0 = 1                                   EE: ax + by = g                                        
                                                                                                          
  ax % m = 1                                       ax.k + by.k = g.k = c                                  
                                                                                                          
  So here if we find x in                          a.x.(c/g) + b.y.(c/g) = c                              
  ax + by = 1                                                                                             
  which is our MMI                                 X0 = x.(c/g)                                           
                                                   Y0 = y.(c/g)                                           
                                                                                                          
                                                   So here X0 & Y0 is out solution to LDE       
```

> **Fermat's Little Theorm**
- `a^p ≡ a (mod p).`
- `a^(p-1) ≡ 1 (mod p)` or `a^(p-1) % p = 1`, if a is not divisible by p.
- where p = prime number
- Application: 
  1. To find MMI, if p is prime. multiply 2nd equation both side with 1/a. `a^(p-2) % p= a^(-1)`, here `a^(-1)` is MMI.
  2. Primality test: The theorem states that, given a prime number `p`, and any number `a` (where 0 < a < p), then `a^(p-1) % p ≡ 1`. we will select `a` randomly for `x` times, if the statement of Fermat's Little Theorem is accepted for all x time, then `p` is said as a probable prime.

function: FermatPrimalityTesting(int N):
    pick a random integer k     //not too less. not too high.
    LOOP: repeat k times:
        pick a random integer X in range (1,N-1)
        if(X^(N-1)%N != 1):
            return composite
    return probably prime

> **Chinese Remainder Theorm**
- We are given two arrays `num[0..k-1]` and `rem[0..k-1]`. In `num[0..k-1]`, every pair is coprime (gcd for every pair is 1). We need to find minimum positive number x such that:
```
     x % num[0]    =  rem[0], 
     x % num[1]    =  rem[1], 
     .......................
     x % num[k-1]  =  rem[k-1] 
```
- Formula
```
x =  ( (rem[i]*pp[i]*inv[i]) + .... upto n-1) % prod
   Where 0 <= i <= n-1

rem[i] is given array of remainders

prod is product of all given numbers
prod = num[0] * num[1] * ... * num[k-1]

pp[i] is product of all divided by num[i]
pp[i] = prod / num[i]

inv[i] = Modular Multiplicative Inverse of 
         pp[i] with respect to num[i]
```
- Example
```
Let us take below example to understand the solution
   num[] = {3, 4, 5}, rem[] = {2, 3, 1}
   prod  = 60 
   pp[]  = {20, 15, 12}
   inv[] = {2,  3,  3}  // (20*2)%3 = 1, (15*3)%4 = 1
                        // (12*3)%5 = 1

   x = (rem[0]*pp[0]*inv[0] + rem[1]*pp[1]*inv[1] + 
        rem[2]*pp[2]*inv[2]) % prod
     = (2*20*2 + 3*15*3 + 1*12*3) % 60
     = (40 + 135 + 36) % 60
     = 11
```
- Application: to solve system of linear congruences. 

> **Euler’s Totient Function**
- Euler’s Totient Function for an input n is count of numbers in {1, 2, 3, …, n} that are coprime to n.
- `ϕ(n) = n * (1 – 1 / pi) * (1 – 1 / pj) * (1 – 1 / pk) * ... * (1 – 1 / pn)`, where pi, pj, pk... pn are prime factors of n.
- `ϕ(6) = 6 * (1 - 1 / 2) * (1 – 1 / 3) = 2`.
- If you observe `ϕ(n) = n * (1 – 1 / pi) = n - n/pi` we are basically subtracting all numbers that are divisible by pi from n.

> **Misc**
- coprime = gcd is 1
- congruence = a & b when divided by n & produce same remainder then it is said that a & b are congruent.
- Modular arithmetic example = wall clock
