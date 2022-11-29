#include<iostream>
#include<vector>
#include<string>

using namespace std;

class MovingAverageInteractive {
    public:
        double determineMovingAverage();

        template<typename T>
        void pricesOverDiffPeriods(vector<T> arr);
};

double MovingAverageInteractive::determineMovingAverage() {
    static const int arrsize = 5;
    int arr[arrsize];
    int meanperiod;

    cout << "add prices to the moving average price stack"<<endl;
    for(int o=0; o < arrsize; o++){
        cin >> arr[o];
    }
    cout << "input the mean moving period"<<endl;
    cin >> meanperiod;
    
    double avg = 0.0;
    int size = sizeof(arr)/sizeof(int);
    if(size <= 5){
        for(int i=0; i < size-meanperiod; i++){
            double sum = 0;
            cout << arr[i] << endl;
            for(int j = i; j < i + meanperiod; j++){
                sum += arr[j];
                avg = sum / (double)meanperiod;
                cout << "moving average: "<< avg << endl;
            }
        }
    }
    return avg;
}

template<typename T>
void pricesOverDiffPeriods(vector<T> arr) {
    for(auto& it : arr){
        cout << it << endl;
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5};

    MovingAverageInteractive interactiveTradeview;
    interactiveTradeview.determineMovingAverage();
    interactiveTradeview.pricesOverDiffPeriods(arr);

}