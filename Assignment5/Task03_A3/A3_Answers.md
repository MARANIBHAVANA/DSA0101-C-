# A3 – Design with Abstract Classes (5 marks)

## A3.1 Payer interface
```cpp
class Payer {
public:
    virtual ~Payer() = default;
    virtual double amountCovered(const Bill& bill) const = 0;
};
class SelfPay : public Payer {
public:
    double amountCovered(const Bill& b) const override { return b.total(); }
};
class Insurance : public Payer {
    double coverLimit, patientSharePercent;
public:
    Insurance(double limit, double share)
      : coverLimit(limit), patientSharePercent(share) {}
    double amountCovered(const Bill& b) const override {
        double eligible = std::min(b.total(), coverLimit);
        return eligible * (1.0 - patientSharePercent / 100.0);
    }
};
class GovernmentScheme : public Payer {
    std::unordered_map<std::string,double> rates;
public:
    explicit GovernmentScheme(std::unordered_map<std::string,double> r)
      : rates(std::move(r)) {}
    double amountCovered(const Bill& b) const override {
        auto it = rates.find(b.type());
        if (it == rates.end()) throw std::runtime_error("unknown package");
        return it->second;
    }
};
```
This is an interface sketch; include `<algorithm>`, `<unordered_map>`, `<utility>` and `<stdexcept>` in a complete implementation, and validate percentages/limits.

## A3.2 Extension
Add `CorporateTieUp : public Payer` and override `amountCovered`. Existing payer classes and the common processing loop remain unchanged.

## Alternative: function pointer/std::function
Store a callable policy such as `std::function<double(const Bill&)>`; capture limit and co-payment in the callable. Each call is O(1) for either approach, so n calls are O(n). A payer class groups data and behaviour with named invariants; `std::function` is flexible but may have type-erasure/allocation overhead. Exact storage size is implementation-dependent.
