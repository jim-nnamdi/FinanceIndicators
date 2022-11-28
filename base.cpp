#include<iostream>

/*
* Sample algorithm for calculating the mean average
* used to see and predict finance trends and conversion
* in trading
*/

class MovingAverage {
    public:
        static const int meanavgsize = 5;
        double determineAverageValues(double pricetrends[meanavgsize], int meanperiods);
        int pricesOverCertainPeriods();
};

double MovingAverage::determineAverageValues(double pricetrends[meanavgsize],int meanperiods) {
    double avg = 0;
    for(int o = 0; o < meanavgsize - meanperiods; o++){
        int sum = 0;
        for (int j = o; j < o + meanperiods; j ++){
            sum += (int)pricetrends[j];
            std::cout << pricetrends[j] << std::endl;
        }
        double avg = (double) sum/meanperiods;
        std::cout << "moving average: " << avg << std::endl; 
    }
    return avg;
}


int main(){
    MovingAverage ma;
    double prices[5] = {1.56,2.0,3.54,4.0,5.93};
    ma.determineAverageValues(prices, 3);
    
    return 0;
}
