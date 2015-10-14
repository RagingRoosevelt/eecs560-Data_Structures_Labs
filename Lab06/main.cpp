#include "hash_open.h"
#include "hash_chain.h"
#include <iostream>

using namespace std;

int menu(int type);

int main()
{// read in data file, then display menu.  from menu selection, perform corresponding action.

    const int prime = 600011;
    const int long NUMMAX = 2147483647;
    
    HashTableOpen  *hashTableOpen  = new HashTableOpen(prime);
    HashTableChain *hashTableChain = new HashTableChain(prime);
}
