#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>

std::vector<std::string> split(std::string s, std::string delim) {
  int i = 1;
  std::vector<std::string> result;

  boost::split(result, s, boost::is_any_of(delim.c_str()));

  std::cout << "NEMA FULL: " << s << "\n";
  for (const auto& item : result) {
	  std::cout << "NEMA DELIM[" << i++ << "]:" << item << "\n";
  }

  return result;
}


int main(int argc, char *argv[])
{
    std::string s = "$GPCHC,0,766.08,0.00,-0.63,-0.73,0.38,-0.04,0.08,0.0127,-0.0111,0.9991,0.00000000,0.00000000,0.00,0.000,0.000,0.000,0.000,0,0,01,0,2*5A";
    std::string delm =",*";

    split(s, delm);		

    std::cout << "Hello Third Party Include!" << std::endl;

    // use a shared ptr
    boost::shared_ptr<int> isp(new int(4));

    // trivial use of boost filesystem
    boost::filesystem::path path = "/usr/share/cmake/modules";
    if(path.is_relative())
    {
        std::cout << "Path is relative" << std::endl;
    }
    else
    {
        std::cout << "Path is not relative" << std::endl;
    }

   return 0;
}
