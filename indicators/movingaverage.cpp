#include<iostream>
#include<vector>

using namespace std;

class MovingAverage {
    public:
        static const int meanavgsize = 5;
        double determineAverageValues(double pricetrends[meanavgsize], int meanperiods);
        double determineMAOnMarketShift(vector<int> initialMovingPrices, int meanperiod, int movingPricesSize);
        template <typename T>
        void pricesOverCertainPeriods(vector<T> prices);
};

double MovingAverage::determineAverageValues(double pricetrends[meanavgsize],int meanperiods) {
    double avg = 0;
    for(int o = 0; o < meanavgsize - meanperiods; o++){
        int sum = 0;
        for (int j = o; j < o + meanperiods; j ++){
            sum += (int)pricetrends[j];
            cout << pricetrends[j] << endl;
        }
        double avg = (double) sum/meanperiods;
        cout << "moving average: " << avg << endl; 
    }
    return avg;
}

double MovingAverage::determineMAOnMarketShift(vector<int> initialMovingPrices, int meanperiod, int movingPricesSize){

    int sum; 
    double avg;
    
    vector<int>::iterator vit;
    for(vit = initialMovingPrices.begin(); vit != initialMovingPrices.end(); ++vit){
        cout << &initialMovingPrices << endl;
    }

    if(initialMovingPrices.size() <= movingPricesSize) {
        for(int x = 0; x < initialMovingPrices.size(); x++){
            sum = 0;
            for(int y = x; y < x + meanperiod; y++){
                sum += initialMovingPrices[y];
                avg = (double) sum/meanperiod;
            }
        }
    }
    cout << "moving average is: "<< avg << endl;
    return avg;
}

// this is at a minimal level ...
template <typename T>
void MovingAverage::pricesOverCertainPeriods(vector<T> prices) {
    for(auto& it : prices){
        cout << it << endl;
    }
}


int main(){

    vector<double> vecarr = {1.435,2.9923,3.2332,4.009,5.0091};
    vector<int> arr = {1,2,3,4,5};
    double prices[5] = {1.56,2.0,3.54,4.0,5.93};

    MovingAverage ma;
    ma.determineAverageValues(prices, 3);
    ma.pricesOverCertainPeriods(vecarr);
    ma.determineMAOnMarketShift(arr, 2, 5);
    
    return 0;
}
