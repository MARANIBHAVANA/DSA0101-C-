# A5 – Design Recovery and Rethrowing (4 marks)

## A5.1 Catch locations
Validation functions throw specific errors. A service layer may catch a known error, log context, and use `throw;` to rethrow the same exception. The application boundary catches `std::exception` and reports a useful message. A top-level `catch(...)` can contain unknown failures, log them and stop or recover safely; it must not claim a failed transaction succeeded.

## A5.2 Stack unwinding and RAII
When an exception leaves a scope, automatic objects are destroyed in reverse construction order. `std::string`, `std::vector`, `std::unique_ptr` and file streams release owned resources in their destructors. RAII avoids missing cleanup on exceptional paths.

## Predict output before running
```text
~f ~main caught 42
```
`g` in `f()` is destroyed first (`~f`); then `m` in `main` is destroyed (`~main`) as the exception exits the try scope. The `catch(int)` handler prints `caught 42`. `not printed` is skipped because the throw transfers control out of the try block.

## Alternative: manual delete in catch blocks
Manual cleanup must be repeated on every error path. Cleanup time remains proportional to resources released, but code and leak opportunities grow with each new branch. RAII centralises release in destructors.
