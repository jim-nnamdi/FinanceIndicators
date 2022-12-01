/**
 * @file linear-regression.cpp
 * @author Jim Samuel (jim@coldfinance.co)
 * @brief  Personal Algorithm for linear regression for financial analysis
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<cmath>
#include<vector>
#include <iomanip>

class LinearRegressionAnalysis {

    // y = a + bx
    // b(slope) = cou(Sy/Sx)
    // Sy = sqrt(sum(x-meanx)/n-1) same with Sx
    // a(y intercept) = meany-slope(meanx)

    // solve for x for all values of x
    // solve for y for all values of y
    // solve for the mean of x and y
    // solve for the standard deviation of x and y
    // in solving for the SD -> (x-_X) ^ 2 same as y

    double y = 0.0;
    double a = 0.0;
    double b = 0.0;
    double x = 0.0;

   public:
   void solveForSlope();
};

void LinearRegressionAnalysis::solveForSlope(){
     // using a dummy dataset
    static const int firstarraysize = 5;
    static const int secondarraysize = 5;

    int sumSds  = 0;
    int sumFds  = 0;
    int meanSds = 0;
    int meanFds = 0;

    int firstDataset[firstarraysize] = {1,2,3,4,5};

    double secondDataset[secondarraysize] = {1.2, 1.3, 1.4, 1.5, 1.6};
   
    for(int o = 0; o < firstarraysize; o++){
        sumFds += firstDataset[o];
    }
    meanFds = sumFds/firstarraysize;

    for (int i = 0; i < secondarraysize; i++ ){
        sumSds += (int)secondDataset[i];
    }
    meanSds = sumSds/secondarraysize;

    int resultofxmean, squareofxmean = 0;
    for(int xmean = 0; xmean < firstarraysize; xmean++){
        int xx = xmean - meanFds;
        resultofxmean = resultofxmean + pow(xx,2);
        squareofxmean = pow(resultofxmean, 2);
    }

    int resultofymean, squareofymean = 0;
    for(int ymean = 0; ymean < secondarraysize; ymean++){
        int yy = ymean - meanSds;
        resultofymean = resultofymean + pow(yy, 2);
        squareofymean = pow(resultofymean, 2);
    }

    int productOfxyresult, productOfxySquareResult = 0;
    productOfxyresult = resultofxmean * resultofymean;
    productOfxySquareResult = squareofxmean * squareofymean;

    // pension covariance coefficient
    float cou = (float)(productOfxyresult/productOfxySquareResult);

    // standard deviation

    int sdx = sqrt(resultofxmean/(firstarraysize-1));
    int sdy = sqrt(resultofymean/(secondarraysize-1));

    b = (double) (cou * (sdx/sdy));

    std::cout  << cou << std::endl;
}

int main(){
    std::cout << "Hello" << std::endl;
    LinearRegressionAnalysis lra;
    lra.solveForSlope();
}