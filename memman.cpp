#include "memman.h"

void* memman::add( std::size_t size, uint id )
{
	memhead *head = (memhead*)malloc( (size + sizeof(memhead)) );
	head->id 	= id;
	head->size	= size;
	head->next	= 0;
	head->prev	= this->end;
	this->end	= head;
	this->size[id] += size;
	this->tsize[id]+=size;
	this->num[id]	 += 1;
	this->tnum[id] += 1;
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
	this->size[head->id]	-= head->size;
	this->num [head->id]	-= 1;
	free( head );
}


memman::~memman()
{
	memhead *next = this->start;
	while( next )
	{
		memhead* cur = next;
		next = next->next;
		this->del(cur+1);
	}
}
