#include<iostream>
#include<vector>
#include<string>
#include<cmath>

template<class T>
class LoanPredictor {
    // amount -> duration -> interest
    // initialize class values <private>
     const T amount = 100;
     const T duration = 8;
     const T interest = 10;

    const T loantime = 1;
    const T minamount = 100;

    public:
    T simpleInterest(T principal, T rate, T time);
};

template<class T>
T LoanPredictor<T>::simpleInterest(T principal, T rate, T time){
        //duration -> [this can be relative]
            if(duration < time){
                std::cout<<"please extend loan payment period"<< std::endl;
                return time;
            }

            if (principal <= amount) {
            std::cout << "min amount of loan not taken" << std::endl;
            return minamount;
            } else {
                return principal;
            }

        T interest  = (principal * rate * time)/100;
        return interest;
}

int main(){
    LoanPredictor<int> loanclass;
    int paymentPlanAfterSixMonths = loanclass.simpleInterest(1000,25,6);
    std::cout<<paymentPlanAfterSixMonths<<std::endl;
    return 0;
}