#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Bill {
protected:
    std::string patient;
public:
    explicit Bill(const std::string& p) : patient(p) {}
    virtual ~Bill() = default;
    virtual double total() const = 0;
    virtual std::string type() const { return "Bill"; }
    void print() const { std::cout << type() << ' ' << patient << ": " << total() << '\n'; }
};
class OutPatient : public Bill {
    double consultation, tests;
public:
    OutPatient(const std::string& p,double c,double t):Bill(p),consultation(c),tests(t){}
    double total() const override { return consultation+tests; }
    std::string type() const override { return "OP"; }
};
class InPatient : public Bill {
    int days; double perDay,surgery;
public:
    InPatient(const std::string& p,int d,double r,double s):Bill(p),days(d),perDay(r),surgery(s){}
    double total() const override { return days*perDay+surgery; }
    std::string type() const override { return "IP"; }
};
class DayCare : public Bill {
    double price;
public:
    DayCare(const std::string& p,double v):Bill(p),price(v){}
    double total() const override { return price; }
    std::string type() const override { return "DayCare"; }
};
class Emergency : public Bill {
    double base, hourly; int hours;
public:
    Emergency(const std::string& p,double b,double h,int n):Bill(p),base(b),hourly(h),hours(n){}
    double total() const override { return base+hourly*hours; }
    std::string type() const override { return "Emergency"; }
};
class Payer { public: virtual ~Payer()=default; virtual double amountCovered(const Bill&) const=0; };
class SelfPay : public Payer {
public: double amountCovered(const Bill& b) const override { return b.total(); }
};
class Insurance : public Payer {
    double limit, patientShare;
public:
    Insurance(double l,double s):limit(l),patientShare(s){}
    double amountCovered(const Bill& b) const override { return std::min(b.total(),limit)*(1.0-patientShare/100.0); }
};
class GovernmentScheme : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        if(b.type()=="DayCare") return 30000;
        if(b.type()=="IP") return 40000;
        throw std::runtime_error("unknown package");
    }
};
int main() {
    std::vector<std::unique_ptr<Bill>> bills;
    bills.emplace_back(std::make_unique<OutPatient>("Ravi",500,1200));
    bills.emplace_back(std::make_unique<InPatient>("Meena",3,2500,40000));
    bills.emplace_back(std::make_unique<DayCare>("Arun",25000));
    bills.emplace_back(std::make_unique<Emergency>("Sara",2000,500,3));
    SelfPay self; Insurance insurance(50000,20); GovernmentScheme government;
    const Payer* payers[]={&self,&insurance,&government};
    double sum=0;
    for(const auto& b:bills) {
        b->print(); sum+=b->total();
        for(const Payer* p:payers) {
            try { std::cout<<"  covered: "<<p->amountCovered(*b)<<'\n'; }
            catch(const std::exception& e) { std::cout<<"  payer error: "<<e.what()<<'\n'; }
        }
    }
    std::cout<<"Total "<<sum<<'\n';
}
