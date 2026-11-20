#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>
class Bill { public: virtual ~Bill()=default; virtual double total()const=0; virtual const char* type()const=0; };
class OutPatient:public Bill { double c,t; public:OutPatient(double a,double b):c(a),t(b){} double total()const override{return c+t;} const char* type()const override{return "OP";} };
class MaternityPackage:public Bill { double rate; public:explicit MaternityPackage(double r):rate(r){if(r<0)throw std::invalid_argument("negative package");} double total()const override{return rate;} const char* type()const override{return "Maternity";} };
class Payer { public:virtual ~Payer()=default;virtual double covered(const Bill&)const=0; };
class SelfPay:public Payer { public:double covered(const Bill& b)const override{return b.total();} };
class CorporatePayer:public Payer { double percent; public:explicit CorporatePayer(double p):percent(p){if(p<0||p>100)throw std::invalid_argument("invalid percentage");} double covered(const Bill& b)const override{return b.total()*percent/100.0;} };
int main() {
    std::vector<std::unique_ptr<Bill>> bills;
    bills.push_back(std::make_unique<OutPatient>(500,1200));
    bills.push_back(std::make_unique<MaternityPackage>(65000));
    SelfPay self; CorporatePayer corporate(75);
    for(const auto& b:bills) std::cout<<b->type()<<" total="<<b->total()<<" self="<<self.covered(*b)<<" corporate="<<corporate.covered(*b)<<'\n';
    try { MaternityPackage invalid(-10); (void)invalid; }
    catch(const std::exception& e) { std::cout<<"caught: "<<e.what()<<'\n'; }
}
