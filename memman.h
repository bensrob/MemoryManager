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
			uint	size	( uint );			//Combined size of group allocs
			uint	num	( uint );			//Number for allocs in group
		inline	uint	getid	();				//Get next free id number

		//Private functions
		private:
			void	delall	();	//Deletes all allocations

		//Data
		private:
			void*	start;		//First header
			void*	end;		//Last header
			uint	nextid;		//Next free id number
	};

	//Inline functions
	inline uint memman::getid()	{	return nextid++;  	}
	inline memman::~memman()	{	this->delall();		}

	//DELETE
	inline void memman::delall(){}

	#define MEMMAN
#endif
