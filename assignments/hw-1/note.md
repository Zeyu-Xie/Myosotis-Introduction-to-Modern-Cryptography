# Note

## Testing against small sets of bases

When the number n to be tested is small, trying all a < 2(ln n)2 is not necessary, as much smaller sets of potential witnesses are known to suffice. For example, Pomerance, Selfridge, Wagstaff and Jaeschke have verified that

if n < 2,047, it is enough to test a = 2;

if n < 1,373,653, it is enough to test a = 2 and 3;

if n < 9,080,191, it is enough to test a = 31 and 73;

if n < 25,326,001, it is enough to test a = 2, 3, and 5;

if n < 3,215,031,751, it is enough to test a = 2, 3, 5, and 7;

if n < 4,759,123,141, it is enough to test a = 2, 7, and 61;

if n < 1,122,004,669,633, it is enough to test a = 2, 13, 23, and 1662803;

if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11;

if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13;

if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.

Using the work of Feitsma and Galway enumerating all base 2 pseudoprimes in 2010, this was extended (see OEIS:

A014233), with the first result later shown using different methods in Jiang and Deng:

if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.

if n < 18,446,744,073,709,551,616 = 264, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, and 37.

Sorenson and Webster verify the above and calculate precise results for these larger than 64‐bit results:

if n < 318,665,857,834,031,151,167,461, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, and 37.

if n < 3,317,044,064,679,887,385,961,981, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, and 41.

Other criteria of this sort, often more efficient (fewer bases required) than those shown above, exist. They give very fast deterministic primality tests for numbers in the appropriate range, without any assumptions.

There is a small list of potential witnesses for every possible input size (at most b values for b‐bit numbers). However, no finite set of bases is sufficient for all composite numbers. Alford, Granville, and Pomerance have shown that there exist infinitely many composite numbers n whose smallest compositeness witness is at least (ln n)1/(3ln ln ln n). They also argue heuristically that the smallest number w such that every composite number below n has a compositeness witness less than w should be of order Θ(log n log log n).