// Euler_041_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// What is the largest n-digit pandigital prime that exists?

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<int> primes; //vector containing primes
    int n = 10000000;
    primes.push_back(2);
    int maxPrime = 0; // for storing max prime
    int found = 0; // check if solution is found
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
    } //end for loop prime search
    
    while (found == 0) // checking if solution is found, only need one prime
    {
        for (int i = primes.size() - 1; i > -1; i--) // New update! Iterating from the back!!!
        {
            int digits[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            int temp = primes[i];
            vector<int> vect;
            bool exists = true;
            while (temp != 0) //separates ints into digits
            {
                if (find(begin(digits), end(digits), temp % 10) != end(digits) == true && temp % 10 != 0)
                {
                    digits[(temp % 10) - 1] = 0; // removes digits that exist in int
                }
                else //if digit appears twice or is zero, prime is invalid
                {
                    exists = false;
                }
                vect.push_back(temp % 10); //stores digits for # of digits in int
                temp /= 10;
            } //end while loop, temp != 0

            if (exists == true) //for all primes without zeroes and identical digits
            {
                //cout << i << endl;
                //cout << primes[i] << " ";
                for (int j = 1; j < vect.size() + 1; j++)
                {
                    if (find(begin(digits), end(digits), j) != end(digits) == true)
                    {
                        exists = false;
                        break;
                    }
                }
            }
            if (exists == true)
            {
                maxPrime = primes[i];
                found = 1;
                // cout << primes[i] << " "; //prints all viable pandigital primes
                break;
            }
        } // end for loop, for each prime
    } // end of while loop checking if found
    cout << maxPrime << endl;




}
