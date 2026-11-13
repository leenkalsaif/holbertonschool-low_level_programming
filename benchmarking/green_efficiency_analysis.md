# Green Efficiency Analysis

## Measurement Methodology

All programs were compiled with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long` and run in the same sandbox environment, so the conditions were consistent across every measurement. Execution time was measured with `clock()` from `<time.h>`, converted to seconds by dividing by `CLOCKS_PER_SEC`. The baseline loop (100,000,000 iterations) was run three times, the algorithm comparison (ARRAY_SIZE 50000) was run [N] times, and the instrumented program was run [N] times. I did not modify the algorithm logic, the input data, or the provided timing logic. In the instrumentation lab, I took one timestamp before the first phase and one after each phase, so each phase is measured between shared boundaries with no gaps or overlaps. Printing happens after the last timestamp so it does not distort the results.

## Observed Performance Differences

The baseline loop produced [T1], [T2], and [T3] seconds across three runs. These are close but not identical, with a spread of about [SPREAD] seconds, which shows that timing varies even for a deterministic computation.

In the algorithm comparison, the naive implementation averaged [NAIVE_AVG] seconds and the single-pass implementation averaged [SINGLE_AVG] seconds. The naive version was therefore about [RATIO] times slower while returning the same kind of result. This matches the algorithmic difference: the naive version performs roughly n(n+1)/2 operations (O(n²)), about 1.25 billion for n = 50000, while the single-pass version performs n operations (O(n)).

In the instrumentation lab, TOTAL was about [TOTAL] seconds, split into BUILD_DATA [BUILD] seconds, PROCESS [PROCESS] seconds, and REDUCE [REDUCE] seconds. The largest share of time was spent in [PHASE], and TOTAL was always at least as large as each individual phase, as expected because TOTAL spans all three.

## Relation Between Runtime and Energy Consumption

A program that runs longer keeps the CPU active longer, and active CPU time generally consumes more energy than idle time. Using this proxy, the naive algorithm's average of [NAIVE_AVG] seconds compared with [SINGLE_AVG] seconds suggests it keeps the CPU busy about [RATIO] times longer for the same task. If such code runs thousands or millions of times in a data center, that difference is multiplied accordingly. This is an inference from runtime, not a direct energy measurement.

## Limitations of the Experiment

This project measures time, not power in watts, so energy conclusions are indirect. CPU power draw differs between workloads, so equal runtimes do not necessarily mean equal energy. `clock()` has limited resolution: some phases in the instrumentation lab were extremely short ([EXAMPLE: e.g. REDUCE reported as X seconds]), so their values are less reliable. The runs happened in a sandbox shared with other processes, which explains part of the variation between runs (for example the baseline spread of [SPREAD] seconds). The number of runs was small, and results on another machine could differ.

## Practical Engineering Takeaway

Choosing a better algorithm had a far larger effect on runtime ([RATIO] times) than the run-to-run noise (about [SPREAD] seconds in the baseline). Developers should measure before drawing conclusions, repeat measurements to understand variability, and compare implementations under identical conditions. Where a simple linear approach solves the problem, it is preferable to a repeated-scan approach, since it reduces CPU time and, by extension, likely energy use. Instrumenting phases separately, as in the lab, also shows where effort is best spent.
