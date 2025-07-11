//color test
#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>
#include <ostream>

namespace color {

    using namespace std;

    // ANSI color code
    const string reset  = "\033[0m"; //reset color

    // Foreground color
    const string black  = "\033[30m";
    const string red    = "\033[31m";
    const string green  = "\033[32m";
    const string yellow = "\033[33m";
    const string blue   = "\033[34m";
    const string magenta= "\033[35m";
    const string cyan   = "\033[36m";
    const string white  = "\033[37m";

    // Bright version
    const string bright_black   = "\033[90m";
    const string bright_red     = "\033[91m";
    const string bright_green   = "\033[92m";
    const string bright_yellow  = "\033[93m";
    const string bright_blue    = "\033[94m";
    const string bright_magenta = "\033[95m";
    const string bright_cyan    = "\033[96m";
    const string bright_white   = "\033[97m";

    // Background color
    const string bg_black  = "\033[40m";
    const string bg_red    = "\033[41m";
    const string bg_green  = "\033[42m";
    const string bg_yellow = "\033[43m";
    const string bg_blue   = "\033[44m";
    const string bg_magenta= "\033[45m";
    const string bg_cyan   = "\033[46m";
    const string bg_white  = "\033[47m";

    // Bright background
    const string bg_bright_black   = "\033[100m";
    const string bg_bright_red     = "\033[101m";
    const string bg_bright_green   = "\033[102m";
    const string bg_bright_yellow  = "\033[103m";
    const string bg_bright_blue    = "\033[104m";
    const string bg_bright_magenta = "\033[105m";
    const string bg_bright_cyan    = "\033[106m";
    const string bg_bright_white   = "\033[107m";

    // Estilos adicionale
    const string bold      = "\033[1m";
    const string underline = "\033[4m";
    const string reversed  = "\033[7m";

}

#endif
