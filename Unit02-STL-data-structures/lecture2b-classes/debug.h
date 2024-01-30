#ifdef DEBUG

#define TRACE std::cerr << "TRACE " << __FILE__ << ": " << __LINE__ << std::endl;
#define TRACK(x) std::cerr << "TRACK line: " << __LINE__ << "; " << #x << " is " << x << std::endl;

#else

#define TRACE 
#define TRACK(x)

#endif