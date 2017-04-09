#ifndef MEMMAN
	#define uint unsigned int
	struct memhead
	{
		uint	id;	//Optional id for what called allocated the memory
		uint	size;	//Size of allocation
		memhead	*prev;	//Pointer to previous head or null for first element
		memhead	*next;	//Pointer to next header or null for last element
	};

	class memman
	{
		//(Con|De)structor
		public:
		inline	memman():	start(0), end(0), nextid(1){}
		inline	~memman();

		//Public Functions
		public:
			void*	add	( std::size_t , uint = 0);	//New allocation in id group
			void	del	( void* );			//Free specified object
		inline	void	delall	( uint );			//Delete all in group
		inline	uint	size	( uint );			//Combined size of group allocs
		inline	uint	num	( uint );			//Number for allocs in group
		inline	uint	getid	();				//Get next free id number

		//Private functions
		private:
		inline	void	delall	();				//Deletes all allocations
			void	delall	( uint, bool );			//Shared implementation

		//Data
		private:
			memhead	*start;					//First header
			memhead	*end;					//Last header
			uint	nextid;					//Next free id number
			std::map<uint,std::pair<uint,uint>>	stats;	//Numbers and size per id
	};


	//Inline functions
        inline memman::~memman()        	{       this->delall();         	}
	inline uint memman::getid()		{	return nextid++;  		}
	inline uint memman::size( uint id )	{	return stats[id].first; 	}	//Not guarenteed
	inline uint memman::num ( uint id )	{	return stats[id].second;	}	//Not guarenteed
	inline void memman::delall( uint id )	{	this->delall( id, false );	}	//Use shared
	inline void memman::delall()		{	this->delall( 0, true );	}	//Use shared

	#define MEMMAN
#endif
