#include <math.h>
#include <iostream>
#include <chrono>
#include <random>
using namespace std;

double eCalc(int num_sims){
    double sum = 0;
    int count = 0;
    
    // Random Number Generator using this implementation of a uniform random distribution (runif): https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(0.0,1.0);
    
    // What is the expected value when counting the number of random numbers between 0 and 1 of which have a sum greater than 1?
    // Surprisingly, the answer is e (Euler's Number!)

    // We will be counting the number of random variables need to be added to exceed 1, N times
    // Then will divide by N at the end to get an average
    for(int i = 0; i<num_sims; ++i){
        while(sum<=1){
            sum+=distribution(generator);
            count++;
        }
        sum = 0;
    }
    return (double) count/num_sims;
}

int main(){
    int sims;
    cout << "Enter Number of Simulations: "; // The larger the number of simulations, the closer the approximation will be to the exact value
    cin >> sims;
    //cout << endl;
    double e = eCalc(sims);
    cout << "Approximation of e using Monte Carlo Simulation: " << e << endl;
    return 0;
}
