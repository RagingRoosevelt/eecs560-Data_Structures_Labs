// main.cpp
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 02

#include "heap_leftist.h"
#include "heap_skew.h"
#include "timer.h"
#include <fstream>
#include <iostream>

#include <cstdlib>
#include <ctime>

long int randi(long int max);
void log(ofstream &file, char type, int seed, int n, double time);

using namespace std;
int main() {
    Timer timer;
    ofstream file;
    file.open("log.csv");
    file << "type,seed,n,time" << endl;
    
    int n[] = {50000, 100000, 200000, 400000};
    int resultsL[5];
    int resultsS[5];
    double time;
    long int value;
    
    for (int n_index=0; n_index < 4; n_index++)
    {
        for (int seed = 0; seed <= 5; seed++)
        {
            HeapLeftist heapL = HeapLeftist();
            HeapSkew heapS = HeapSkew();
            
            // leftist heap
            srand(seed);
            timer.start();
            for (int datum = 0; datum < n[n_index]; datum++)
            {
                value = randi(4 * n[n_index]);
                heapL.insert(value);
            }
            time = timer.stop();
            resultsL[seed] = time;
            log(file, 'l', seed, n[n_index], time);
            
            
            // skew heap
            srand(seed);
            timer.start();
            for (int datum = 0; datum < n[n_index]; datum++)
            {
                value = randi(4 * n[n_index]);
                heapS.insert(value);
            }
            time = timer.stop();
            resultsS[seed] = time;
            log(file, 's', seed, n[n_index], time);
        }
    }
    
    file.close();
    return 0;
}

void log(ofstream &file, char type, int seed, int n, double time)
{
    if (type == 'l')
    {
        file << "Leftist,"; 
    }
    else if (type == 's')
    {
        file << "Skew,"; 
    }
    file << seed << "," << n << ",";
    
    file << time << endl;
}

double avg(double times[])
{
    double sum = 0;
    for (int i=0; i<5; i++)
    {
        sum += times[i];
    }
    return sum / 5;
}

long int randi(long int max)
{
    return rand() % max;
}
