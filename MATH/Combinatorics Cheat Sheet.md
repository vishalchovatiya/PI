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

## Pascal's Triangle
```
 0|            01             = 2^(0)     (x+y)^0 = 1.x^0.y^0 = 1                                                                  
 1|          01  01           = 2^(1)       o                                                                                      
 2|        01  02  01         = 2^(2)     (x+y)^2 = 1.x^2.y^0 + 2.x^1.y^1 + 1.x^0.y^2 = x^2 + 2xy + y^2                            
 3|      01  03  03  01       = 2^(3)     (x+y)^3 = 1.x^3.y^0 + 3.x^2.y^1 + 3.x^1.y^2 + 1.x^0.y^3 = = x^3 + 3.x^2.y + 3.x.y^2 + y^3
 4|    01  04  06  04  01     = 2^(4)       o                                                                                      
 5|  01  05  10  10  05  01   = 2^(5)       o                                                                                      
```
Note: Diagonal summation of no in pascal triangle also generate fibonacci sequence
- 

