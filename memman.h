#ifndef MEMMAN
	#define uint unsigned int	//Dont judge me (for alignment, neatness and laziness reasons)
	#define MAX 1024		//Maximum number of ids
	#define TAG 16			//Characters allocated for a tag detailing alloc reason

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
			~memman();

		//Public Functions
			void*	add	( std::size_t , uint = 0);	//New allocation in id group
			void	del	( void* );			//Free specified object
		inline 	void	print	();				//Prints current stats
	private:
		//Data
			memhead	*start;			//First header
			memhead	*end;			//Last header
			uint	nextid;			//Next free id number
			uint	size [MAX];		//Current size of allocations per id
			uint	num  [MAX];		//Current number of allocs per id
                        uint    tsize[MAX];             //Total size
                        uint    tnum [MAX];             //Total number of allocs
			char	tag  [MAX][TAG];	//Name specified when recieving an id
	} 	static memman;


	//Inline functions
	inline void memman::print()		{ 	for( uint i = 1; i != nextid; i++ )
							std::cout << i << "\t" << tag[i] << "\t" << num[i] << "\\" << tnum[i] << "\t" << size[i] << "\\" << tsize[i] << "\n"; }
	#define MEMMAN
#endif
