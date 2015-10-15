#include "hash_open.h"
#include "hash_chain.h"
#include "timer.h"
#include <iostream>

using namespace std;

int menu(int type);

int main()
{// read in data file, then display menu.  from menu selection, perform corresponding action.

    const int prime = 600011;
    const int long NUMMAX = 2147483647;
    int seedMax = 5;
    Timer timer;
    
    double timesOpen[6];
    double timesChaining[6];
    
    double loadFactor;
    int dataCount;
    long int value;
    
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
            timesOpen[lf] += timer.stop();
            
            srand(seed);
            timer.start();
            for (int datum = 1; datum <= dataCount; datum++)
            {
                value = rand() % NUMMAX; 
                hashTableChain->insert(value);
            }
            timesChaining[lf] += timer.stop();
            
            delete hashTableOpen;
            delete hashTableChain;
        }
        
        timesChaining[lf] /= seedMax;
        timesOpen[lf] /= seedMax;
        cout << "For a load factor of " << loadFactor << ", " << endl;
        cout << "    open hashing finished in average time of " << timesOpen[lf] << endl;
        cout << "    chaining finished in average time of     " << timesChaining[lf] << endl;
        
    }
}
