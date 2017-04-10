#ifndef MEMMAN
	#define uint unsigned int	//Dont judge me (for alignment, neatness and laziness reasons)
	#define MAX 1024		//Maximum number of ids
	#define TAG 16			//Characters allocated for a tag detailing alloc reason
	#define GETID memman.getid( __PRETTY_FUNCTION__ )

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
			void	delall	( uint );			//Delete all in group ( 0 for all )
		inline	uint	size	( uint );			//Combined size of group allocs
		inline	uint	num	( uint );			//Number for allocs in group
		inline	uint	getid	( std::string ); //Get next free id number
		inline	char*	id	( uint );			//Get tag for id
		inline	uint	max	();				//Get number of ids
		inline 	void	print	();				//Prints current stats
	private:
		//Data
			memhead	*start;			//First header
			memhead	*end;			//Last header
			uint	nextid;			//Next free id number
			uint	idsize [MAX];		//Current size of allocations per id
			uint	idnum  [MAX];		//Current number of allocs per id
                        uint    idtsize[MAX];           //Total size
                        uint    idtnum [MAX];           //Total number of allocs
			char	idtag  [MAX][TAG];	//Name specified when recieving an id
	} 	static memman;


	//Inline functions
        inline memman::~memman()        	{       this->delall(0);      	   		}
	inline uint memman::getid(std::string s){	s.copy( idtag[nextid], TAG-1 );		\
							return nextid++;  			}
	inline uint memman::size( uint id )	{	return idsize[id];			}
	inline uint memman::num ( uint id )	{	return idnum[id];			}
	inline char* memman::id( uint id )	{	return idtag[id];			}
	inline uint memman::max()		{	return nextid;				}
	inline void memman::print()		{	std::cout << "id\ttag\tnum\tsize\n";	\
							for( uint i = 1; i != nextid; i++ )	\
							std::cout << i << "\t" << id(i) << "\t"	<< num(i) << "\\" << idtnum[i] << "\t" << size(i) << "\\" << idtsize[i] << "\n"; }
#define MEMMAN
#endif
