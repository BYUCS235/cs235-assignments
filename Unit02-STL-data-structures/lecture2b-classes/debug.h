#ifdef DEBUG

#define TRACE std::cerr << "line: " << __LINE__ << std::endl;
#define TRACK(x) std::cerr << "line: " << __LINE__ << "; " << #x << " is " << x << std::endl;

#else

#define TRACE 
#define TRACK(x)

#endif