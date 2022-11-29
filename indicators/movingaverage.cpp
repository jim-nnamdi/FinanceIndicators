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

// this is at a minimal level ...
template <typename T>
void MovingAverage::pricesOverCertainPeriods(vector<T> prices) {
    for(auto& it : prices){
        cout << it << endl;
    }
}


int main(){

    vector<double> vecarr = {1.435,2.9923,3.2332,4.009,5.0091};
    double prices[5] = {1.56,2.0,3.54,4.0,5.93};

    MovingAverage ma;
    ma.determineAverageValues(prices, 3);
    ma.pricesOverCertainPeriods(vecarr);
    
    return 0;
}
