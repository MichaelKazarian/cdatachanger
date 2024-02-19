// Program to minimal test the getopt() function in C

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("Usage:\ngetoptmin [-d][-gns arg]\n");
  }
  int opt;
  // put ':' in the starting of the string so that program can %"
  // distinguish between '?' and ':'
  while((opt = getopt(argc, argv, "dg:n:s:")) != -1) {
    switch(opt) {
    case 'd':
      printf("Do it\n");
      break;
    case 'g':
      printf("Get: %s\n", optarg);
      break;
    case 'n':
      printf("Next: %s\n", optarg);
      break;
    case 's':
      printf("Set: %s\n", optarg);
      break;
    case ':':
      printf("Option needs a value\n");
      break;
    case '?':
      printf("Unknown option: %c\n", optopt);
      break;
    }
  }
  // optind is for the extra arguments which are not parsed
  for(; optind < argc; optind++) {
    printf("extra arguments: %s\n", argv[optind]);
  }

  return 0;
}
