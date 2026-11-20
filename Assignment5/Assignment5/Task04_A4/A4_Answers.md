# A4 – Design the Exception Strategy (4 marks)

## A4.1 Errors and hierarchy
Errors: negative charges; claim above cover; unknown package; missing patient record; invalid numeric text (`std::invalid_argument`); out-of-range numeric input (`std::out_of_range`); allocation failure (`std::bad_alloc`).

Conceptual application hierarchy:
```text
std::exception
└── std::runtime_error
    └── BillingError
        ├── InvalidChargeError
        ├── ClaimError
        ├── UnknownPackageError
        └── MissingPatientError
```
Standard exceptions such as `std::bad_alloc` and `std::invalid_argument` can be caught separately; they do not need to derive from `BillingError`.

## A4.2 Exception specification
Validation, parsing, bill/payer calculations, file operations and allocation may throw. Destructors and cleanup should not throw; a destructor throwing during stack unwinding can call `std::terminate`. Mark appropriate destructors `noexcept`.

## Alternative: return status
Return an enum/status or result object containing status, value and message. The normal path avoids exception propagation but every caller must check and forward errors. The result carries status/message storage and adds branching/code. Exceptions keep normal control flow uncluttered but should represent exceptional conditions, not routine outcomes.
