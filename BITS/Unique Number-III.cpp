/*
Q: Given a list of numbers where every number is occuring thrice except one number we have to find out the unique number which is occuring just one time.

Explanation:
Since all other numbers are occuring thrice, we need to cancel all the bits occuring thrice(contriubted by repeating numbers) - so we take sum of bits at every positions(in all numbers) and take mod by 3 for every position. We maintain a array of size 64 to handle 64 bit integers. Watch the video to learn more.

*/
