# A2 – Understand Runtime Binding (5 marks)

## A2.1 Early and late binding
Early binding selects a function from the declared type at compile time (usual non-virtual calls). Late binding selects the final overrider using the object's dynamic type at runtime. If `Bill* b` points to an `OutPatientBill`, `b->total()` calls `OutPatientBill::total()` when `total` is virtual.

## A2.2 Conceptual vtables
The C++ standard does not mandate vtables; this is a common implementation model.

```text
Bill vtable:             OutPatientBill vtable:       InPatientBill vtable:
- virtual destructor     - derived destructor        - derived destructor
- total (pure slot)      - OutPatientBill::total      - InPatientBill::total
- type (pure slot)       - OutPatientBill::type       - InPatientBill::type
```
A call `b->total()` uses the dynamic object's dispatch metadata to select the correct final overrider.

## A2.3 Virtual destructor
Deleting a derived object through `Bill*` requires a virtual base destructor. Otherwise the behaviour is undefined.

## Predict the output before running
```text
500 ~OPBill ~Bill
```
`show()` is non-virtual, but it calls virtual `total()`. That inner call dispatches using the dynamic type, so `OPBill::total()` returns 500. `delete b` calls the derived destructor then the base destructor.

Removing `virtual` from `~Bill` makes `delete b` undefined behaviour. There is no standard-guaranteed output or sanitizer diagnostic; record what your compiler actually reports.

## Alternative: dynamic_cast
Without virtual `total`, code could test each known derived type using `dynamic_cast` and call its calculation. In the worst case, k casts are tried per bill: O(nk) for n bills and k types, versus O(n) virtual dispatch. A vptr commonly costs one pointer per object, implementation-dependent. Adding a type also requires changing the central cast chain.
