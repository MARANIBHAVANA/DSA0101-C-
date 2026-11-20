# B2 notes
Completed `approve` and `settle` with `throw;` to rethrow the same exception. Expected first test sequence: approved 40000; audit then claim rejected for exceeds cover; negative amount is reported by the general `std::exception` handler. The validation loop logs only `std::out_of_range` ("too large"); `std::invalid_argument` ("negative") is not caught by that specific handler and is handled at main.

`std::optional<double>` alternative: return a value for success and `nullopt` for rejection (or a richer result type to preserve reason). Both are O(1) per claim. Exceptions have relatively low normal-path overhead in common implementations but expensive propagation on error; optional checks every result and avoids exception unwinding. Benchmark 1,000,000 claims at 0%, 1%, and 50% invalid on your machine. The optional itself stores a value plus a presence flag (implementation-dependent padding).

Do not force a huge allocation on your personal machine: overcommit can cause system instability. Catching `std::bad_alloc` is shown, but a controlled allocator/test harness is safer for demonstrating failure.
