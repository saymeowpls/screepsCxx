#include <emscripten.h>

extern "C" {
  EMSCRIPTEN_KEEPALIVE
  int addTwo() {
    return 999;
  }
}