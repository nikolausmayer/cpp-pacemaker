
/// System/STL
#include <cstdlib>
#include <iostream>
#include <random>
#include <sstream>
#include <thread>
/// Local files
#include "pacemaker.h"


int main(int argc, char** argv) {

  if ( argc < 2 ) {
    std::cout << "\n  Usage: " << argv[0] << " <beats per second>"
              << std::endl;
    return EXIT_SUCCESS;
  }

  float target_fps  = atof(argv[1]);
  std::cout << "Constructing pacemaker with " << target_fps << "fps."
            << std::endl;


  Pacemaker::Pacemaker clock(target_fps, false);

  unsigned int counter{0};
  std::ostringstream oss;
  for (;;) {
    if (clock.IsDue()) {
      oss.str("");
      for (unsigned int i = 0; i < counter; ++i)
        oss << " ";
      oss << "Tick!";
      std::cout << oss.str() << std::endl;
      counter = (counter+1)%20;
    }
  }

  return EXIT_SUCCESS;
}

