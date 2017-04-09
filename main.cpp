#include "memman.h"
using namespace std;

int main()
{
	int* i = (int*) memman.add( sizeof(int), memman.getid() );
        int* p = (int*) memman.add( sizeof(int), memman.getid() );
	int* o = (int*) memman.add( sizeof(int), 3 );
         memman.add( sizeof(int), 3 );
         memman.add( sizeof(int), 3 );
         memman.add( sizeof(int), 3 );
         memman.add( sizeof(int), 3 );
}
