#include<iostream>

/*
* Sample algorithm for calculating the mean average
* used to see and predict finance trends and conversion
* in trading
*/

class MovingAverage {
    public:
        static const int meanavgsize = 5;
        int determineAverageValues(int pricetrends[meanavgsize],int meanperiods);
        int pricesOverCertainPeriods();
};

// declare the functions from inside the class
int MovingAverage::determineAverageValues(int pricetrends[meanavgsize],int meanperiods) {
    int avg = 0;
    for(int o = 0; o < meanavgsize - meanperiods; o++){
        int sum = 0;
        for (int j = o; j < o + meanperiods; j ++){
            sum = sum + pricetrends[j];
            std::cout << pricetrends[j] << std::endl;
        }
        int avg = sum/meanperiods;
        std::cout << "moving average: " << avg << std::endl; 
    }
    return avg;
}


int main(){
    MovingAverage ma;

    int prices[5] = {1,2,3,4,5};
   ma.determineAverageValues(prices, 3);
}
