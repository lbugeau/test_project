#include "comp_sqrt.h"

#include <chrono>
#include <cmath>
#include <ctime>
#include <iostream> 
#include <vector>

/**
 * @brief run operations implying square root with sqrt function and exponential function and display execution times
 * 
 */
void comp_sqrt()
{
    std::vector<double> vect_sqrt;
    std::vector<double> vect_exp;

    auto start_1 = std::chrono::system_clock::now();
    for (int i = 0; i < 10000000; i++)
    {
        double ii = i*1.0;
        double val = std::sqrt(ii);
        vect_sqrt.push_back(val);
    }
    auto end_1 = std::chrono::system_clock::now();
    std::chrono::duration<double> duration_1 = end_1 - start_1;
    double sqrt_time = duration_1.count();

    auto start_2 = std::chrono::system_clock::now();
    for (int i = 0; i < 10000000; i++)
    {
        double ii = i*1.0;
        double val = std::exp(0.5 * std::log(ii));
        vect_exp.push_back(val);
    }
    auto end_2 = std::chrono::system_clock::now();
    std::chrono::duration<double> duration_2 = end_2 - start_2;
    double exp_time = duration_2.count();

    std::cout << "sqrt comparison" << std::endl;
    std::cout << "   Time on loop with sqrt : " << sqrt_time << " seconds" << std::endl;
    std::cout << "   Time on loop with exponential : " << exp_time << " seconds" << std::endl;
    std::cout << std::endl;
}