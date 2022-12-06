#include<iostream>
#include<vector>
#include<string>
#include<cmath>

template<class T>
class LoanPredictor {
    // amount -> duration -> interest
    const T& amount;
    const T& duration;
    const T& interest;

    const T loantime = 1;
    const T minamount = 100;

    public:
    T simpleInterest(T principal, T rate, T time);
};

template<class T>
T LoanPredictor<T>::simpleInterest(T principal, T rate, T time){
        T loan_duration = [](duration) {
            if(duration < time){
                std::cout<<"please extend loan payment period"<< std::endl;
                return rate;
            }
            return loantime;
        };

        T loan_amount = [](){
            if (amount <= principal) {
            std::cout << "min amount of loan not taken" << std::endl;
            return minamount;
            }
            return amount;
        };

        T interest  = loan_amount * rate * time;
        return T;
    }

int main(){
    LoanPredictor<int> loan;
    int paymentPlanAfterSixMonths = loan.simpleInterest(1000,25,6);
    std::cout<<paymentPlanAfterSixMonths<<std::endl;
    return 0;
}