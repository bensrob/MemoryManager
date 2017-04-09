#include "memman.h"
using namespace std;

int main()
{
	uint i = memman.getid("test1");
	memman.add( sizeof(int), i );
        memman.add( sizeof(int), i );
        memman.add( sizeof(int), i );

        i = memman.getid("test2");
        memman.add( sizeof(int), i );
        memman.add( sizeof(int), i );
        memman.add( sizeof(int), i );

        uint p = memman.getid("test3");
        memman.add( sizeof(int), p );
        memman.add( sizeof(int), p );
        memman.add( sizeof(int), p );

        i = memman.getid("test4");
        memman.add( sizeof(int), i );
        int*l = (int*)memman.add( sizeof(int), i );
        memman.add( sizeof(int), i );

        i = memman.getid("test5");
        memman.add( sizeof(int), i );
        memman.add( sizeof(int), i );
        memman.add( sizeof(int), i );

	memman.print();
	memman.delall(p);
	memman.del(l);
	memman.print();
}
