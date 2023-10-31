#include <iostream>
#include <vector>
#include <chrono>

#include <typedef.hpp>


// -----------------------------------------------------------------------------
// MACROS

#define ON 1
#define OFF 0

#define ERROR_AND_EXIT(error_message) { \
  std::cout << error_message << NLC;    \
  std::cout << NLC << "exiting...\n";   \
  exit(1);                              \
}


// -----------------------------------------------------------------------------
// DATA

/// @brief A union that works as a bit-field for the supplied arguments to this
///        application.
union Argument {
  u32 argument;
  struct {
    u32 start_timer : 1;
    u32 configure   : 1;
  };
};

local Argument g_argument_flags{ 0 };
local std::vector<std::string> g_argument_vec;


// -----------------------------------------------------------------------------
// FUNCTIONS | DECL.

/// @brief Parse the arguments passed to this application.
void
parse_arguments(
  int   argc,
  char *argv[]
);

/// @brief TODO:
void
print_application_head();


// -----------------------------------------------------------------------------
// MAIN

int
main(
  int   argc,
  char *argv[]
) {
  print_application_head();

  parse_arguments(argc, argv);

  if (g_argument_flags.start_timer)
    std::cout << "You want to start the timer!\n";
  if (g_argument_flags.configure)
    std::cout << "You want to configure the timer!\n";

exit:
  std::cout << NLC;
  return EXIT_SUCCESS;
}


// -----------------------------------------------------------------------------
// FUNCTIONS | DEF.

void
parse_arguments(
  int   argc,
  char *argv[]
) {
  for (int i{ 1 }; i < argc; i++)
    g_argument_vec.push_back(argv[i]);

  for (std::string const &arg : g_argument_vec) {
    if (arg == "start")
      g_argument_flags.start_timer = ON;
    else if (arg == "config")
      g_argument_flags.configure = ON;
    else {
      std::string exit_message{ "\"" };
      exit_message.append(arg);
      exit_message.append("\" is not a valid argument.");
      ERROR_AND_EXIT(exit_message);
    }
  }
}


void
print_application_head() {
  std::cout << "+--------------+--------+-------+\n"
            << "| pomodoro-cli | v0.0.1 | shell |\n"
            << "+--------------+--------+-------+\n\n";
}
