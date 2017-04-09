#include "memman.h"

void* memman::add( std::size_t size, uint id )
{
	memhead *head = (memhead*)malloc( size + sizeof(memhead) );
	head->id 	= id;
	head->size	= size;
	head->next	= 0;
	head->prev	= this->end;
	this->end	= head;
	this->idsize[id]+= size;
	this->idnum[id]	+= 1;
	return (void*) head;
}


void memman::del ( void* todel )
{
	free( todel );
}


void memman::delall( uint id, bool all )
{
	memhead *next = this->start;
	while( next )
	{
		if( all || id == next->id )
		{
			memhead* cur = next;
			next = next->next;
			this->del(cur);
		}
		else next = next->next;
	}
}
