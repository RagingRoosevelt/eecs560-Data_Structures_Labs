#include "hash_open.h" 
#include "hash_chain.h"
#include "timer.h"
#include <iostream>
#include <fstream>

using namespace std;

int menu(int type);

int main()
{// read in data file, then display menu.  from menu selection, perform corresponding action.
    ofstream logFile ("log.csv");

    const int prime = 600011;
    const long int NUMMAX = 2147483647;
    int seedMax = 100;
    Timer timer;
    
    double timesOpen[6];
    double timesChaining[6];
    
    double loadFactor;
    int dataCount;
    long int value;
    double time;
    logFile << "type, load factor, time" << endl;
    for (int lf = 0; lf <6; lf += 1)
    {
        for (int seed = 0; seed < seedMax; seed++)
        {
            HashTableOpen  *hashTableOpen  = new HashTableOpen(prime);
            HashTableChain *hashTableChain = new HashTableChain(prime);
        
            loadFactor = 0.2 + lf / 10.0;
            dataCount = loadFactor * prime;
            
            srand(seed);
            timer.start();
            for (int datum = 1; datum <= dataCount; datum++)
            {
                value = rand() % NUMMAX; 
                hashTableOpen->insert(value);
            }
            time = timer.stop();
            timesOpen[lf] += time;
            logFile << "open" << ", " << loadFactor << ", " << time << endl;
            
            srand(seed);
            timer.start();
            for (int datum = 1; datum <= dataCount; datum++)
            {
                value = rand() % NUMMAX; 
                hashTableChain->insert(value);
            }
            time = timer.stop();
            timesChaining[lf] += time;
            logFile << "chin" << ", " << loadFactor << ", " << time << endl;
            
            delete hashTableOpen;
            delete hashTableChain;
        }
        
        timesChaining[lf] /= seedMax;
        timesOpen[lf] /= seedMax;
        cout << "For a load factor of " << loadFactor << ", " << endl;
        cout << "    open hashing finished in average time of " << timesOpen[lf] << endl;
        cout << "    chaining finished in average time of     " << timesChaining[lf] << endl;
        
    }
    
    logFile.close();
    return 0;
}
