#include <cstdio>
#include <string>
#include <type_traits>

#include "hashes.h"

int main() { 
    
  std::string s{"Hello World!"};

  printf("fnv1a_32:\t0x%08x\n", fnv1a_32(s.begin(), s.end()));
  printf("fnv1a_64:\t0x%016lx\n", fnv1a_64(s.begin(), s.end()));

  printf("djb2a_32:\t0x%08x\n", djb2a_32(s.begin(), s.end()));
  printf("djb2a_64:\t0x%016lx\n", djb2a_64(s.begin(), s.end()));

  printf("sdbm_32:\t0x%08x\n", sdbm_32(s.begin(), s.end()));
  printf("sdbm_64:\t0x%016lx\n", sdbm_64(s.begin(), s.end()));

  return 0;
};