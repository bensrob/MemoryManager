#ifndef MEMMAN
	#define uint unsigned int	//Dont judge me (for alignment, neatness and laziness reasons)
	#define MAX 1024		//Maximum number of ids

	struct memhead
	{
		uint	id;		//Optional id for what called allocated the memory
		uint	size;		//Size of allocation
		memhead	*prev;		//Pointer to previous head or null for first element
		memhead	*next;		//Pointer to next header or null for last element
	};

	class memman
	{
	public:
		//(Con|De)structor
		inline	memman():	start(0), end(0), nextid(1){}
		inline	~memman();

		//Public Functions
			void*	add	( std::size_t , uint = 0);	//New allocation in id group
			void	del	( void* );			//Free specified object
		inline	void	delall	( uint );			//Delete all in group
		inline	uint	size	( uint );			//Combined size of group allocs
		inline	uint	num	( uint );			//Number for allocs in group
		inline	uint	getid	();				//Get next free id number

	private:
		//Private functions
		inline	void	delall	();				//Deletes all allocations
			void	delall	( uint, bool );			//Shared implementation

		//Data
			memhead	*start;			//First header
			memhead	*end;			//Last header
			uint	nextid;			//Next free id number
			uint	idsize[MAX];		//Size of allocations per id
			uint	idnum [MAX];		//Number of allocs per id
	} 	static memman;


	//Inline functions
        inline memman::~memman()        	{       this->delall();         	}
	inline uint memman::getid()		{	return nextid++;  		}
	inline uint memman::size( uint id )	{	return idsize[id];		}	//Not guarenteed
	inline uint memman::num ( uint id )	{	return idnum[id];		}	//Not guarenteed
	inline void memman::delall( uint id )	{	this->delall( id, false );	}	//Use shared
	inline void memman::delall()		{	this->delall( 0, true );	}	//Use shared

	#define MEMMAN
#endif
