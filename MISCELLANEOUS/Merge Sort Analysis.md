We have Time Complexity as follows
```
T(1) 	= 1, Step 0th, For Single Element

**T(N) 	= 2T(N/2) + N**, Step 1, 

T(N) 	= Divide Two Array in Equal Halfs takes 2 * O(N/2)  + Merge them takes O(N)

T(N/2) 	= 2( T(N/2) / 2 ) + N/2 = 2( T(N/4) ) + N/2, Step 2

T(N/4) 	= 2( T(N/4) / 2 ) + N/4 = 2( T(N/8) ) + N/4, Step 3
|
|
|
..... And So on till base case
```

So Generalise formala with steps is, T(N) = 8 T(N/8)  + 3N,  for 3 steps

`And T(N) = 2^K T(N/2^K)  + KN, for K steps`

at last divide OR say base case that we handle, N/2^K = 1

`N = 2^K`

So, K = Log N, After considering log with base 2 both size

Now, we put value of K in Generalise formula
```
T(N)  	= 2^K T(N/2^K) + KN
	      = 2^(Log N) T(N/2^(Log N)) + (Log N)N 
	      = N + N (Log N) 
      	= **N(Log N)**, Considering Higher Complexity
```
