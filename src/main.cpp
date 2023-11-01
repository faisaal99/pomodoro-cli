/*******************************************************************************
Copyright (C) 2023 Faisal A.

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the “Software”), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*******************************************************************************/

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
