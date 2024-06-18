#ifdef DEBUG

#include <iostream>
#define TRACE std::cerr << "TRACE line: " << __LINE__ << std::endl;
#define TRACK(x) std::cerr << "TRACK line: " << __LINE__ << "; " << #x << " is " << x << std::endl;

#else

#define TRACE 
#define TRACK(x)

#endif