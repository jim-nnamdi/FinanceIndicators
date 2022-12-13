#include<iostream>
#include<cstdarg>

using namespace std;

template<class T> 
class Accounts{
    public:
        T accountsCreated(int num, ...)
};

template<class T>
T Accounts<T>::accountsCreated(int num, ...){
    va_list user_accounts;
    T i;
    double sum  = 0.0;
    for(i = 0; i < num; i++){
        sum += va_arg(user_accounts, int);
    }
    va_end(user_accounts);
    avg_created_accounts = sum/num;
    return avg_created_accounts;
}

int main(){
    Accounts<double> a;
    cout << "average of created accounts" <<  
    a.accountsCreated(4,5,6,7,8,8,9) << endl;
}