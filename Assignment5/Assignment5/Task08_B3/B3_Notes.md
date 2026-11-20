# B3 experimental record
Run `B3.cpp` with `-O2`. Change `N` to 1000, 1000000 and 10000000 and record each measured time in the table below. Run multiple times and compare medians; use the same compiler, machine and data for each method.

| N | switch ms | virtual ms | variant ms | compiler / CPU notes |
|---:|---:|---:|---:|---|
| 1,000 | | | | |
| 1,000,000 | | | | |
| 10,000,000 | | | | |

For exceptions vs return codes, add a separate benchmark with 1,000,000 claims at 0%, 1% and 50% invalid. Do not invent timing values. Complexity is O(n) for each full pass; constants differ due to dispatch, branch prediction, allocation and exception unwinding. `std::variant` stores enough space for its largest alternative plus a discriminator (exact layout implementation-dependent).

Engineering decision: use virtual dispatch for an extensible mixed collection; switch/variant can be competitive when the set of alternatives is closed and data locality matters. Use exceptions for exceptional failures, not routine invalid-record outcomes.
