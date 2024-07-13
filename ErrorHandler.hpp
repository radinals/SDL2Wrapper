#ifndef ERRORHANDLER_HPP
#define ERRORHANDLER_HPP

#include <SDL2/SDL_error.h>
#include <cstdlib>
#include <iostream>
#include <string>

class ErrorHandler {

    enum CrashType { SDL_FAILED=-2, GENERIC_FAILED =-1};

    static void die(const std::string& msg, CrashType type=GENERIC_FAILED) {
        std::cerr << "EXITED: " << msg << " - (" << SDL_GetError() << "\n";
        std::exit(type);
    }

    static void warn(const std::string& msg) {
        std::cerr << "WARNING: " << msg << " - (" << SDL_GetError() << "\n";
    }
};

#endif // !ERRORHANDLER_HPP
