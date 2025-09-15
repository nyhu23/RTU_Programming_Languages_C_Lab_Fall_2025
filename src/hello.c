
#include <stdio.h>

int main(int argc, char *argv[]) {
  // this is not my first code
  printf("Hello, my name is nithya!\n");
  printf("You passed %d argument(s).\n", argc - 1);
  for (int i = 1; i < argc; ++i) {
    printf("  arg[%d] = %s\n", i, argv[i]);
  }
  return 0;
}
