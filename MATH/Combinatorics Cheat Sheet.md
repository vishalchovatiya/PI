## General pointers
- Permutation = Arrangement, order does not matter
- Combination = Selection, order matters(that's why permutation formula is divided by r!)
## Permutation
```
nPr = n! / (n-r)!
```
#### Permutation cheats
- Create blank boxes as many as no of digit of outputs
- Start filling boxes from most significant digits upon selecting no of choices.

#### Permutation with repetitions
- If we have `N` objects out of which `N1` objects are of type `1`, `N2`  objects are of type `2`, ... `Nk` objects are of type `k` , then number of ways of arrangement of these `N` objects are given by:
```
(n)P(r) = N! / (N1! x N2! x N3! x ... Nk!)
```

#### Example 

#### Permutation questions(Difficulty in incremental order)
1. How many 4 digit numbers are possible with digits 1,2,3,6,7,8,9 ?
  - Digit can not be repeated
  - Digit can be repeated
2. How many 3 digit numbers greater than 400 can be made with the digits 2,3,4,0,5,6 ? (Digit can not be repeated).
3. How many 3 digit numbers between 200 and 500 can be made with the digits 2,3,4,0,5,6 ? (Digit can not be repeated).
4. How many 4 digit numbers can be made with the digits 1,2,3,4,5,6 if number is divisible by 5 ?
  - Digit can not be repeated
  - Digit can be repeated
5. How many 4 digit odd/even numbers can be made with the digits 0,1,2,3,4,5,6?
6. In how many different ways word "EQUATION" can be arranged ?
7. In how many different ways word "EQUATION" can be arranged if it starts with letter 'Q'?
8. In how many different ways word "EQUATION" can be arranged if it starts with consonant ?
9. In how many different ways word "EQUATION" can be arranged if it starts with consonant & ends with vowel ?
10. In how many different ways word "BANKING" can be arranged ?
11. In how many different ways word "ASSASINATION" can be arranged so that all 'S' are together ?

## Combination
```
nCr = n! / (r! . (n-r)!)
```
Note: Why there is `r!` in combination formula & rest is same as permutation?
#### Combination cheats
- 
#### Combinations with repetition:
- If we have `N` elements out of which we want to choose `K` elements and it is allowed to choose one element more than once, then number of ways are given by:
```
(n+k-1)C(k) = (n+k-1)! / (k)!(n-1)!
```


#### Example 
- 
#### Combination questions(Difficulty in incremental order)
- 

## Pascal's Triangle = triangular array of the binomial coefficients

#### Concept
```
 0|            01             = 2^(0)     (x+y)^0 = 1.x^0.y^0 = 1                                                                  
 1|          01  01           = 2^(1)       o                                                                                      
 2|        01  02  01         = 2^(2)     (x+y)^2 = 1.x^2.y^0 + 2.x^1.y^1 + 1.x^0.y^2 = x^2 + 2xy + y^2                            
 3|      01  03  03  01       = 2^(3)     (x+y)^3 = 1.x^3.y^0 + 3.x^2.y^1 + 3.x^1.y^2 + 1.x^0.y^3 = = x^3 + 3.x^2.y + 3.x.y^2 + y^3
 4|    01  04  06  04  01     = 2^(4)       o                                                                                      
 5|  01  05  10  10  05  01   = 2^(5)       o                                                                                      
```
#### 2D array arragement

```
0|  1 
1|  1 1 
2|  1 2 1 
3|  1 3 3 1 
4|  1 4 6 4 1 
5|  1 5 10 10 5 1 
```
- As you can see, in the line number `line` there are `line + 1` elements.
- Each cell value represent number of ways you can reach to that cell from line 0, row 0.
- If you observe the value, then `i`th entry in a line number `line` is Binomial Coefficient(i.e. nCr) `(line)C(i)` . Technically pascal's triangle is
```
0|  0C0 
1|  1C0 1C1 
2|  2C0 2C1 2C2 
3|  3C0 3C1 3C2 3C3 
4|  4C0 4C1 4C2 4C3 4C4 
5|  5C0 5C1 5C2 5C3 5C4 5C5
```
- Formula: for time & space complexity O(N^2)
```
f(0,0) = 1
f(line,i) = f(line-1,i-1) + f(line-1,i)
```
- Formula: for time complexity O(N^2), space O(1)
```
C(line, i)   = line! / ( (line-i)! * i! )
C(line, i-1) = line! / ( (line - i + 1)! * (i-1)! )
We can derive following expression from above two expressions.
Just substitute value of line! from expression 2 to expression 1

C(line, i) = C(line, i-1) * (line - i + 1) / i

So C(line, i) can be calculated from C(line, i-1) in O(1) time
```

- Facts:
  - Diagonal summation of no in pascal triangle also generate fibonacci sequence
  - Hocky Stick Rule of pascal's triangle

#### nCr is binomial coefficient of polynomial equations like
- If you pick any equation from above like as `(x+y)^2`:
```
 (x+y)^2 = 1.x^2.y^0 + 2.x^1.y^1 + 1.x^0.y^2 
 (x+y)^2 = (nCr).x^2.y^0 + (nCr).x^1.y^1 + (nCr).x^0.y^2 
 (x+y)^2 = (2C0).x^2.y^0 + (2C1).x^1.y^1 + (2C2).x^0.y^2 
 
(2C0) = 1
(2C1) = 2
(2C2) = 1

 (x+y)^2 = x^2 + 2xy + y^2     
```
