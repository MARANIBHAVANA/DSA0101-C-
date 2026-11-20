#include <iostream>
#include <stdexcept>
#include <new>

class ClaimError : public std::runtime_error {
public: using std::runtime_error::runtime_error;
};
double approve(double billed,double cover) {
    if(billed<0 || cover<0) throw std::invalid_argument("negative amount");
    if(billed>cover) throw ClaimError("exceeds cover");
    return billed;
}
double settle(double billed,double cover) {
    try { return approve(billed,cover); }
    catch(const ClaimError& e) { std::cout<<"audit: "<<e.what()<<'\n'; throw; }
}
void validate(double amount) {
    if(amount<0) throw std::invalid_argument("negative");
    if(amount>1e6) throw std::out_of_range("too large");
    std::cout<<"ok ";
}
void process(double amount) {
    try { validate(amount); }
    catch(const std::out_of_range& e) { std::cout<<"[log "<<e.what()<<"] "; throw; }
}
int main() {
    double cases[][2]={{40000,50000},{60000,50000},{-1,50000}};
    for(const auto& c:cases) {
        try { std::cout<<"approved "<<settle(c[0],c[1])<<'\n'; }
        catch(const ClaimError& e) { std::cout<<"claim rejected: "<<e.what()<<'\n'; }
        catch(const std::exception& e) { std::cout<<"error: "<<e.what()<<'\n'; }
    }
    std::cout<<"Validation: ";
    for(double a:{100.0,-5.0,2e6}) {
        try { process(a); std::cout<<"done "; }
        catch(const std::exception& e) { std::cout<<"caught "<<e.what()<<' '; }
    }
    std::cout<<'\n';
    try { int* p=new int[10]; delete[] p; }
    catch(const std::bad_alloc&) { std::cout<<"allocation failed\n"; }
}
