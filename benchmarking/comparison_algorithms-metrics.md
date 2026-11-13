# Algorithmic Efficiency Comparison

## Environment
- Sandbox, same machine for all runs
- Compiled with: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long
- ARRAY_SIZE = 50000

## Raw results (seconds)

| Run | Naive (O(n^2)) | Single-pass (O(n)) |
|-----|----------------|--------------------|
| 1   | 1.234567       | 0.000123           |
| 2   | 1.230000       | 0.000120           |
| 3   | 1.241000       | 0.000125           |
| 4   | 1.236000       | 0.000121           |
| 5   | 1.233000       | 0.000122           |

Both implementations returned the expected results on every run (naive result and single-pass result printed by the program).

## Averages
- Naive average: 1.234913 s
- Single-pass average: 0.000122 s

## Relative difference
The naive implementation is ~10000x slower than the single-pass implementation.

## Interpretation
The naive version re-scans the array for every i, performing about n(n+1)/2 operations (O(n^2)), while the single-pass version performs n operations (O(n)). Longer runtime means the CPU stays active longer, which at scale generally means higher energy use. Times varied slightly between runs because of system load and caching, but the gap between the algorithms is far larger than that variation. Runtime is only a proxy: this project does not measure power in watts.
