#ifndef MEMMAN
	#define uint unsigned int
	struct memhead
	{
		uint	id;	//Optional id for what called allocated the memory
		uint	size;	//Size of allocation
		void* 	prev;	//Pointer to previous head or null for first element
		void* 	next;	//Pointer to next header or null for last element
	};

	class memman
	{
		//(Con|De)structor
		public:
		inline	memman():	start(0), end(0), nextid(1){}
		inline	~memman();

		//Public Functions
		public:
			void*	add	( std::size_t size, uint );	//New allocation in id group
			void	del	( void* );			//Free specified object
			void	delall	( uint );			//Delete all in group
		inline	uint	size	( uint );			//Combined size of group allocs
		inline	uint	num	( uint );			//Number for allocs in group
		inline	uint	getid	();				//Get next free id number

		//Private functions
		private:
			void	delall	();	//Deletes all allocations

		//Data
		private:
			void*	start;		//First header
			void*	end;		//Last header
			uint	nextid;		//Next free id number
			std::map<uint,std::pair<uint,uint>>	stats;	//Numbers and size per id
	};

	//Inline functions
        inline memman::~memman()        	{       this->delall();         	}
	inline uint memman::getid()		{	return nextid++;  		}
	inline uint memman::size( uint id )	{	return stats[id].first; 	}	//Not guarenteed
	inline uint memman::num ( uint id )	{	return stats[id].second;	}	//not guarenteed

	//DELETE
	inline void memman::delall(){}

	#define MEMMAN
#endif
