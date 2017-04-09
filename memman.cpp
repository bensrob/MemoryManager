#include "memman.h"

void* memman::add( std::size_t size, uint id )
{
	memhead *head = (memhead*)malloc( (size + sizeof(memhead)) );
	head->id 	= id;
	head->size	= size;
	head->next	= 0;
	head->prev	= this->end;
	this->end	= head;
	this->idsize[id]+= size;
	this->idnum[id]	+= 1;
	if(head->prev)	head->prev->next = head;
	if(!this->start)this->start = head;
	return (void*)(head+1);
}


void memman::del ( void* todel )
{
	memhead* head = (memhead*)todel-1;
	if( head->prev )		head->prev->next = head->next;
	if( head->next )		head->next->prev = head->prev;
	if( this->start == head )	this->start = head->next;
	if( this->end == head )		this->end   = head->prev;
	this->idsize[head->id]	-= head->size;
	this->idnum [head->id]	-= 1;
	free( head );
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
			this->del(cur+1);
		}
		else next = next->next;
	}
}
