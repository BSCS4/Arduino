#include <IRRemoteDIY.h>

long IRRemoteDIY::map(long code) {
  code = (0x0FFFF & code) >> 8;
  switch(code) {
  }

  return 0l;//KEY_NONE;
}
