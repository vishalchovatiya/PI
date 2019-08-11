> **Get right most set bit**

-  Formula:  `n & (-n)` 

> **Check no is even or odd(EFFICIENT)**

-  Formula:  `n & 0x1` 


> **Find no of set bits(EFFICIENT)**

-  Formula:  `n & (n-1)` & count iterations

> **Shift left multiplier**

-  example: `a << 2 = a * 2^2`
 - generalized: `a << n = a * 2^n`

> **Shift right divider**

-  example: `a >> 2 = a / 2^2`
 - generalized: `a >> n = a / 2^n`

> **Convert given decimal number to binary, hexadecimal, octal**

- Use universal method, divide with base and assemble results in char array

> **Checking power of 2**

- `X && !( X & (X - 1) )`
