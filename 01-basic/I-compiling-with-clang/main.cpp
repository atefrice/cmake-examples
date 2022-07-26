#include <iostream>

#ifdef CHINA
std::string country = "china";
#else
std::string country = "english";
#endif

// will error, because not in preprocessor
std::string life22 = LIFE;

#ifdef LIFE
std::string life = LIFE;
#else
std::string life = "no_life";
#endif

int robot_type = ROBOT_TYPE;

int main(int argc, char *argv[])
{
   std::cout << "Hello CMake!  ---->" <<  country << " ---> "  << life << std::endl;
   std::cout << robot_type << std::endl;
   return 0;
}