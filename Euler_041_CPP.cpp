// Euler_041_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// What is the largest n-digit pandigital prime that exists?

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> primes;
    int total = 0; //total num of circular primes
    int n = 100;//primes less than n (1000000)
    primes.push_back(2);
    for (int i = 3; i < n; i++)
    {
        bool prime = true;
        for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++)
        {
            if (i % primes[j] == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
        {
            primes.push_back(i);
            //cout << i << " ";
        }
    } // end for loop, prime search
}

int digits[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };