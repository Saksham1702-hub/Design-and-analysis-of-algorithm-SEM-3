# The Celebrity Problem

The Celebrity Problem is a popular Data Structures and Algorithms problem based on finding a special person in a group.

A **celebrity** is a person who:

- Is known by every other person in the party.
- Does not know anyone else in the party.

Given a matrix `M` of size `N × N`:

- `M[i][j] = 1` means person `i` knows person `j`.
- `M[i][j] = 0` means person `i` does not know person `j`.

The task is to find the index of the celebrity. If no celebrity exists, return `-1`. [2][4]

## Example

```text
Input:
M = [
 ,[0][1]
 ,[0]
[1][0]
]

Output:
1
```

### Explanation

Person `1` does not know anyone:

```text
M = 0[1]
M = 0[2][1]
```

Everyone else knows person `1`:

```text
M = 1[1]
M = 1[1][2]
```

Therefore, person `1` is the celebrity.

## Approach

The optimized approach uses two steps:

1. Find a possible celebrity candidate.
2. Verify whether that candidate is actually a celebrity.

### Candidate Elimination

Start with person `0` as the possible celebrity.

For every person `i` from `1` to `N - 1`:

- If the current candidate knows person `i`, the candidate cannot be a celebrity. Update the candidate to `i`.
- Otherwise, person `i` cannot be a celebrity, so keep the current candidate.

After this process, only one possible celebrity candidate remains.

### Verification

To verify the candidate:

- The candidate must not know any other person.
- Every other person must know the candidate.

If both conditions are true, return the candidate index. Otherwise, return `-1`.

## Algorithm

```text
1. Set candidate = 0.

2. For i = 1 to N - 1:
   - If M[candidate][i] == 1:
       candidate = i

3. Verify the candidate:
   - For every person i:
       - If i != candidate and
         (M[candidate][i] == 1 OR M[i][candidate] == 0):
           return -1

4. Return candidate.
```

## Time Complexity

| Approach | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| Brute Force | O(N²) | O(1) |
| Optimized Candidate Elimination | O(N) | O(1) |

## Key Idea

If person `A` knows person `B`, then `A` cannot be a celebrity.

If person `A` does not know person `B`, then `B` cannot be a celebrity.

This allows us to eliminate one person in every comparison and find a possible celebrity in linear time. [6][9]
