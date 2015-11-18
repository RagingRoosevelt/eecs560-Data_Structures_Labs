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
void log(ofstream &file, char type, int seed, int n, double time_v, char op);

using namespace std;
int main() {
    Timer timer;
    ofstream file;
    file.open("log.csv");
    file << "type,action,seed,n,time" << endl;
    
    int n[] = {50000, 100000, 200000, 400000};
    int buildL[5];
    int opsL[5];
    int buildS[5];
    int opsS[5];
    double time_v;
    long int value;
    
    for (int n_index=0; n_index < 4; n_index++)
    {
        double skew_build[5], skew_ops[5], left_build[5], left_ops[5];
        for (int seed = 0; seed <= 5; seed++)
        {
            HeapLeftist heapL = HeapLeftist();
            HeapSkew heapS = HeapSkew();
            
            // leftist heap build
            srand(seed);
            timer.start();
            for (int datum = 0; datum < n[n_index]; datum++)
            {
                value = randi(4 * n[n_index]);
                heapL.insert(value);
            }
            time_v = timer.stop();
            left_build[seed] = time_v;
            log(file, 'l', seed, n[n_index], time_v, 'b');
            
            // leftist heap delete/insert ops
            srand(time(NULL));
            timer.start();
            for (int i=0; i < n[n_index] / 10; i++)
            {
                if (randi(2) == 1)
                {
                    heapL.deleteMin();
                }
                else
                {
                    heapL.insert( randi(4 * n[n_index]) );
                }
            }
            time_v = timer.stop();
            left_ops[seed] = time_v;
            log(file, 'l', seed, n[n_index], time_v, 'o');
            
            
            
            // skew heap build
            srand(seed);
            timer.start();
            for (int datum = 0; datum < n[n_index]; datum++)
            {
                value = randi(4 * n[n_index]);
                heapS.insert(value);
            }
            time_v = timer.stop();
            skew_build[seed] = time_v;
            log(file, 's', seed, n[n_index], time_v, 'b');
            
            // leftist heap delete/insert ops
            srand(time(NULL));
            timer.start();
            for (int i=0; i < n[n_index] / 10; i++)
            {
                if (randi(2) == 1)
                {
                    heapS.deleteMin();
                }
                else
                {
                    heapS.insert( randi(4 * n[n_index]) );
                }
            }
            time_v = timer.stop();
            skew_ops[seed] = time_v;
            log(file, 's', seed, n[n_index], time_v, 'o');
        }
        double sk_b=0, sk_o=0, lf_b=0, lf_o=0;
        for (int i = 0; i < 5; i++)
        {
            sk_b += skew_build[i] / 5.0;
            sk_o += skew_ops[i] / 5.0;
            lf_b += left_build[i] / 5.0;
            lf_o += left_ops[i] / 5.0;
        }
        cout << "For n=" << n[n_index] << ", initial build was performed by:" << endl
             << "    left in " << lf_b << " seconds" << endl
             << "    skew in " << sk_b << " seconds" << endl;
        cout << "For n=" << n[n_index] << ", random inserts and deletemins were performed by:" << endl
             << "    left in " << lf_o << " seconds" << endl
             << "    skew in " << sk_o << " seconds" << endl;
        
    }
    
    file.close();
    return 0;
}

void log(ofstream &file, char type, int seed, int n, double time_v, char op)
{
    if (type == 'l')
    {
        file << "Leftist,"; 
    }
    else if (type == 's')
    {
        file << "Skew,"; 
    }
    if (op == 'b')
    {
        file << "build,";
    }
    else if (op == 'o')
    {
        file << "ops,";
    }
    file << seed << "," << n << ",";
    
    file << time_v << endl;
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
