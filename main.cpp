#include "memman.h"
using namespace std;

int test()
{
	uint i = GETID;
}


int main()
{
	test();

	uint i = memman.getid("test1");
	memman.add( sizeof(int), i );
        memman.add( sizeof(int), i );
        memman.add( sizeof(int), i );

        i = GETID;
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
	cout << "\n";
	memman.delall(p);
	memman.del(l);
	memman.print();
}
