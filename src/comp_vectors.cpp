#include "comp_vectors.h"

#include <chrono>
#include <cmath>
#include <ctime>
#include <iostream> 
#include <vector>

/**
 * @brief run operations on vectors with different architecture and display execution times
 * 
 */
void comp_vectors()
{
        //-- Build 2D vector with large indices first
        std::vector<std::vector<double>> large_first;
        for (int i = 0; i < 1000000; i++)
        {
            std::vector<double> row;
            for (int j = 0; j < 2; j++)
            {
                row.push_back(1.);
            }
            large_first.push_back(row);
        }
        //== Build 2D vector with large indices first
    
        //-- Build 2D vector with small indices first
        std::vector<std::vector<double>> small_first;
        for (int i = 0; i < 2; i++)
        {
            std::vector<double> row;
            for (int j = 0; j < 1000000; j++)
            {
                row.push_back(1.);
            }
            small_first.push_back(row);
        }
        //== Build 2D vector with small indices first
    
        //-- Build two 1D vectors
        std::vector<double> sep_1;
        std::vector<double> sep_2;
        for (int j = 0; j < 1000000; j++)
        {
            sep_1.push_back(1.);
            sep_2.push_back(1.);
        }
        //== Build two 1D vectors
    
        //--- Compute time on loops
        //-- 2D vector with large first
        auto start_1 = std::chrono::system_clock::now();
        for (int k = 0; k < 1000000; k++)
        {
            large_first[k][0] = 2.;
            large_first[k][1] = 2.;
        }
        auto end_1 = std::chrono::system_clock::now();
        std::chrono::duration<double> duration_1 = end_1 - start_1;
        double large_first_time = duration_1.count();
        //== 2D vector with large first
    
        //-- 2D vector with small first
        auto start_2 = std::chrono::system_clock::now();
        for (int k = 0; k < 1000000; k++)
        {
            small_first[0][k] = 2.;
            small_first[1][k] = 2.;
        }
        auto end_2 = std::chrono::system_clock::now();
        std::chrono::duration<double> duration_2 = end_2 - start_2;
        double small_first_time = duration_2.count();
        //== 2D vector with small first
    
        //-- 1D separated vectors
        auto start_3 = std::chrono::system_clock::now();
        for (int k = 0; k < 1000000; k++)
        {
            sep_1[k] = 2.;
            sep_2[k] = 2.;
        }
        auto end_3 = std::chrono::system_clock::now();
        std::chrono::duration<double> duration_3 = end_3 - start_3;
        double sep_time = duration_3.count();
        //== 1D separated vectors
        //--- Compute time on loops
    
        // Display results
        std::cout << "Vectors comparison " << std::endl;
        std::cout << "   Time on loop with large indices first : " << large_first_time << " seconds" << std::endl;
        std::cout << "   Time on loop with small indices first : " << small_first_time << " seconds" << std::endl;
        std::cout << "   Time on loop with separated vectors :   " << sep_time << " seconds" << std::endl;
        std::cout << std::endl;
}