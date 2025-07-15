#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>
using namespace std;
namespace color {
    // Texto normal
    const string black   = "\033[30m";
    const string red     = "\033[31m";
    const string green   = "\033[32m";
    const string yellow  = "\033[33m";
    const string blue    = "\033[34m";
    const string magenta = "\033[35m";
    const string cyan    = "\033[36m";
    const string white   = "\033[37m";

    // Texto brillante (High Intensity)
    const string bright_black   = "\033[90m";
    const string bright_red     = "\033[91m";
    const string bright_green   = "\033[92m";
    const string bright_yellow  = "\033[93m";
    const string bright_blue    = "\033[94m";
    const string bright_magenta = "\033[95m";
    const string bright_cyan    = "\033[96m";
    const string bright_white   = "\033[97m";

    // Fondos
    const string on_black   = "\033[40m";
    const string on_red     = "\033[41m";
    const string on_green   = "\033[42m";
    const string on_yellow  = "\033[43m";
    const string on_blue    = "\033[44m";
    const string on_magenta = "\033[45m";
    const string on_cyan    = "\033[46m";
    const string on_white   = "\033[47m";

    // Fondos brillantes
    const string bg_bright_black   = "\033[100m";
    const string bg_bright_red     = "\033[101m";
    const string bg_bright_green   = "\033[102m";
    const string bg_bright_yellow  = "\033[103m";
    const string bg_bright_blue    = "\033[104m";
    const string bg_bright_magenta = "\033[105m";
    const string bg_bright_cyan    = "\033[106m";
    const string bg_bright_white   = "\033[107m";

    // Estilos
    const string reset      = "\033[0m";
    const string bold       = "\033[1m";
    const string dim        = "\033[2m";
    const string italic     = "\033[3m";
    const string underline  = "\033[4m";
    const string blink      = "\033[5m";
    const string reverse    = "\033[7m";
    const string hidden     = "\033[8m";
    const string strikethrough = "\033[9m";
}

#endif // COLOR_HPP
