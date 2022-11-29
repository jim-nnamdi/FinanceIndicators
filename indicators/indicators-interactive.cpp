#include<iostream>
#include<vector>
#include<string>

using namespace std;

class MovingAverageInteractive {
    public:
        double determineMovingAverage();
        double determineMAOnMarketShift();
        void pricesOverDiffPeriods(vector<int> arr);
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

double MovingaverageInteractive::determineMAOnMarketShift(){
    vector<int> initialMovingPrices;
    int sum, meanperiod, movingPricesSize; 
    double avg;

    cout << "size of the moving price"<< endl;
    cin >> movingPricesSize;

    cout << "set the initial moving prices"<< endl;
    for (int i =0; i < movingPricesSize; i++) {
        cin >> initialMovingPrices;
    }

    vector<int>::iterator vit;
    for(vit = initialMovingPrices.begin(); vit != initialMovingPrices.end(); ++vit){
        cout << *initialMovingPrices << endl;
    }

    if(initialMovingPrices.size() <= movingPricesSize) {
        for(int x = 0; x < initialMovingPrices.size(); x++){
            sum = 0;
            for(int y = x; y = x + meanperiod; y++){
                sum += initialMovingPrices[y];
                avg = (double) sum/meanperiod;
                cout << "moving average is: "<< avg << endl;
            }
        }
    }
}

void MovingAverageInteractive::pricesOverDiffPeriods(vector<int> arr) {
    vector<int>::iterator iter;
    for(iter = arr.begin(); iter != arr.end(); ++iter){
        cout << *iter << endl;
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5};

    MovingAverageInteractive interactiveTradeview;
    interactiveTradeview.determineMovingAverage();
    interactiveTradeview.pricesOverDiffPeriods(arr);
}