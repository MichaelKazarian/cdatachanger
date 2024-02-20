#include <stdio.h>
#include <unistd.h>

void printHelp() {
  printf("Program to emulate termostat data sender.\n");
  printf("Usage:\ndatasender -I val [-htseED][-TI val]\n\n");
  printf("Options:\n-I value  Device ID\n");
  printf("-t        Query current temperature\n");
  printf("-T value  Set the water temperature\n");
  printf("-d        Query desired temperature\n");
  printf("-s        Query current status\n");
  printf("-e        Query current error\n");
  printf("-E        Enable heater\n");
  printf("-D        Disable heater\n");
  printf("Output:\nMessage like :ID~QUERY~CRC;\n");
  printf("where : is a message start, ~ is a data separator and ; message end \n");
}

int parseArgs(int argc, char *argv[]) {
  if (argc == 1) {
    printHelp();
    return -1;
  }
  int opt;
  int isIdFound = 0;
  while((opt = getopt(argc, argv, "I:")) != -1) {
    switch(opt) {
    case 'h':
      printHelp();
      return -1;
    case 'I':
      isIdFound = 1;
      break;
    case ':':
      printf("Option needs a value\n");
      break;
    case '?':
      printf("Error found: %c\n", optopt);
      break;
    }
  }

  if (!isIdFound) {
    printf("Device Id not found\n");
    return -1;
  }
  // optind is for the extra arguments which are not parsed
  for(; optind < argc; optind++) {
    printf("extra arguments: %s\n", argv[optind]);
  }

  return 0;
}

int main(int argc, char *argv[]) {
  parseArgs(argc, argv);
  return 0;
}
