#include <chrono>
#include <iostream>
#include <memory>
#include <variant>
#include <vector>
struct Data { int type; double x,y; int n; };
double bySwitch(const Data& b) {
    switch(b.type) { case 0:return b.x+b.y; case 1:return b.n*b.x+b.y; case 2:return b.x; default:return b.x+b.y*b.n; }
}
struct Base { virtual ~Base()=default; virtual double total() const=0; };
struct OP:Base { double x,y; OP(double a,double b):x(a),y(b){} double total()const override{return x+y;} };
struct IP:Base { int n; double x,y; IP(int d,double a,double b):n(d),x(a),y(b){} double total()const override{return n*x+y;} };
struct DC:Base { double x; explicit DC(double a):x(a){} double total()const override{return x;} };
struct EM:Base { int n; double x,y; EM(int h,double a,double b):n(h),x(a),y(b){} double total()const override{return x+y*n;} };
using Var=std::variant<OP,IP,DC,EM>;
template<class F> void run(const char* label,F f) {
    auto t=std::chrono::steady_clock::now(); double s=f();
    auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-t).count();
    std::cout<<label<<" sum="<<s<<" time_ms="<<ms<<'\n';
}
int main() {
    // Set N to 1000, 1000000, then 10000000 and record each run.
    constexpr std::size_t N=1000000;
    std::vector<Data> data; std::vector<std::unique_ptr<Base>> poly; std::vector<Var> vars;
    data.reserve(N); poly.reserve(N); vars.reserve(N);
    for(std::size_t i=0;i<N;++i) {
        switch(i%4) {
        case 0:data.push_back({0,500,1200,0});poly.push_back(std::make_unique<OP>(500,1200));vars.emplace_back(OP(500,1200));break;
        case 1:data.push_back({1,2500,40000,3});poly.push_back(std::make_unique<IP>(3,2500,40000));vars.emplace_back(IP(3,2500,40000));break;
        case 2:data.push_back({2,25000,0,0});poly.push_back(std::make_unique<DC>(25000));vars.emplace_back(DC(25000));break;
        default:data.push_back({3,2000,500,3});poly.push_back(std::make_unique<EM>(3,2000,500));vars.emplace_back(EM(3,2000,500));break;
        }
    }
    run("switch",[&]{double s=0;for(const auto& b:data)s+=bySwitch(b);return s;});
    run("virtual",[&]{double s=0;for(const auto& b:poly)s+=b->total();return s;});
    run("variant",[&]{double s=0;for(const auto& b:vars)s+=std::visit([](const auto& v){return v.total();},b);return s;});
    std::cout<<"Repeat with N=1000 and N=10000000; timings depend on your machine/compiler.\n";
}
