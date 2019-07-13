

## Number Theory

> **Prime number**
- Its whole number unlike composite number which made up different factors.
- Even nos can't be prime except 2.
- If you plot the fibonacci numbers in spiral form, all diagonals are prime nos.
- Primes are used in cryptography coz you can not generate combination or patterns out of it so wont be decrypted easily.

> **What is mean by square root of any no?**
- It means that one of its factor will be less than square root of no & one will be larger.
- For example: N = 36, square root of N = 6; all the factor of 36 are

1. 18 x 2  = 36
2. 12 x 3  = 36
3. 9 x 4   = 36
4. 6 x 6   = 36
  
So, square root is wokring like partition of two factor of given N.

> **Sieve of eratosthenes**
1. Brute force 
2. Square root optimization
3. Square of no optimization

> **Segmented Sieve**
- For example: All primes b/w 25 to 36
- Step 1: Find all primes upto square root of ‘n’(upper bound)  
- Step 2: Cancell all no b/w 25 to 36 which are divisible by prime found in step 1

> **Euclid's algo for GCD**
- GCD(a,b) = GCD(b, a%b)
- GCD(a,0) = a

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

> **LCM**
- GCD(a,b) x LCM(a,b) = a x b

> **Misc**
- coprime = gcd is 1
