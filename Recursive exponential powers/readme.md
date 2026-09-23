# Power of a Number: Normal vs Recursive Method

This program calculates the power of a number using two different methods:

1. Normal iterative method
2. Recursive fast-power method

It also measures and compares the execution time of both approaches.

## Problem Statement

Given a base `x` and a non-negative exponent `n`, calculate:

```text
xⁿ
```

The program calculates the result using both a normal loop and a recursive optimized approach.

## Methods Used

### 1. Normal Power Method

The normal method multiplies the base `x` by itself `n` times.

```c
int normalPower(int x, int n)
{
    int result = 1;

    for (int i = 0; i < n; i++)
    {
        result = result * x;
    }

    return result;
}
```

For example:

```text
2⁵ = 2 × 2 × 2 × 2 × 2 = 32
```

### 2. Recursive Fast Power Method

The recursive method uses exponentiation by squaring.

Instead of multiplying `x` a total of `n` times, it squares the base and divides the exponent by `2` in each recursive call.

```c
int recursivePower(int x, int n)
{
    if (n == 0)
        return 1;

    if (n % 2 == 0)
        return recursivePower(x * x, n / 2);
    else
        return x * recursivePower(x * x, (n - 1) / 2);
}
```

The mathematical logic behind the recursive method is:

```text
If n is even:

xⁿ = (x²)ⁿ/²

If n is odd:

xⁿ = x × (x²)(n-1)/2

Base case:

x⁰ = 1
```

This is the standard recursive exponentiation-by-squaring formula. [18][20]

## Example

```text
Input:
Base = 2
Power = 5
```

```text
Normal Method Result = 32
Recursive Method Result = 32
```

### Recursive Calculation

```text
recursivePower(2, 5)

5 is odd:
2 × recursivePower(2 × 2, (5 - 1) / 2)

2 × recursivePower(4, 2)

2 is even:
recursivePower(4 × 4, 2 / 2)

recursivePower(16, 1)

1 is odd:
16 × recursivePower(16 × 16, 0)

16 × 1 = 16

Final answer:
2 × 16 = 32
```

## Time Complexity

| Method | Time Complexity | Space Complexity |
|---|---:|---:|
| Normal iterative method | `O(n)` | `O(1)` |
| Recursive fast-power method | `O(log n)` | `O(log n)` |

The recursive method is faster for large values of `n` because the exponent is divided by `2` during every recursive call. [20][21]

## Performance Measurement

The program uses the `clock()` function from the `time.h` library to calculate CPU execution time.

To make the time difference easier to observe, both methods run `1,000,000` times.

```c
start = clock();

/* Function execution */

end = clock();

timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
```

## Important Notes

- The program accepts only non-negative powers.
- `int` values can overflow for large bases or exponents.
- For larger results, use `long long int`.
- The actual execution time may vary depending on the computer, compiler, and optimization settings.
- The normal method may be competitive for very small powers because function-call overhead exists in recursion, but the recursive method scales much better as `n` becomes large.

## How to Compile and Run

```bash
gcc power.c -o power
./power
```

## Sample Output

```text
Enter base: 2
Enter power: 10

Normal Method Result = 1024
Recursive Method Result = 1024

Time taken by Normal Method = 0.020000 seconds
Time taken by Recursive Method = 0.010000 seconds
```

> Note: The displayed timing values are only examples and will be different on different systems.
