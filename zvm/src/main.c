#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "zlist.h"
#include "zobject.h"
#include "zop.h"


int main(int argc, char *argv[]) {

  int fd;
  struct stat fs;
  size_t size;
  const char *mapped;

  fd = open("test.znc", O_RDONLY);
  fstat(fd, &fs);
  size = fs.st_size;
  mapped = mmap(0, size, PROT_READ, MAP_SHARED, fd, 0);

  z_run(mapped, size);

  return 0;
}
