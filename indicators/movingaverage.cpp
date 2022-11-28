#include<iostream>
#include<vector>

using namespace std;

/*
* Sample algorithm for calculating the mean average
* used to see and predict finance trends and conversion
* in trading
*/

class MovingAverage {
    public:
        static const int meanavgsize = 5;
        double determineAverageValues(double pricetrends[meanavgsize], int meanperiods);
        
        template <typename T>
        T pricesOverCertainPeriods(vector<T> prices[5]);
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

// this is at a minimal level ...
template <typename T>
T MovingAverage::pricesOverCertainPeriods(vector<T> prices[5]) {
    for(auto i : prices){
        cout << i << endl;
    }
}


int main(){

    vector<int> vecarr = {1,2,3,4,5};
    double prices[5] = {1.56,2.0,3.54,4.0,5.93};

    MovingAverage ma;
    ma.determineAverageValues(prices, 3);
    // ma.pricesOverCertainPeriods(vecarr);
    
    return 0;
}
