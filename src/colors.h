// colors.h
#ifndef COLORS_H
#define COLORS_H

// Text Colors
#define TEXT_BLACK   "\033[0;30m"
#define TEXT_RED     "\033[0;31m"
#define TEXT_GREEN   "\033[0;32m"
#define TEXT_YELLOW  "\033[0;33m"
#define TEXT_BLUE    "\033[0;34m"
#define TEXT_PURPLE  "\033[0;35m"
#define TEXT_CYAN    "\033[0;36m"
#define TEXT_WHITE   "\033[0;37m"
#define TEXT_GRAY    "\033[1;30m"
#define TEXT_ORANGE  "\033[0;91m"

// Background Colors
#define BG_BLACK     "\033[40m"
#define BG_RED       "\033[41m"
#define BG_GREEN     "\033[42m"
#define BG_YELLOW    "\033[43m"
#define BG_BLUE      "\033[44m"
#define BG_PURPLE    "\033[45m"
#define BG_CYAN      "\033[46m"
#define BG_WHITE     "\033[47m"
#define BG_GRAY      "\033[100m"
#define BG_ORANGE    "\033[101m"

// Text Styles
#define STYLE_BOLD       "\033[1m"
#define STYLE_UNDERLINE  "\033[4m"
#define STYLE_REVERSED   "\033[7m"
#define STYLE_BLINK      "\033[5m"
#define STYLE_ITALIC     "\033[3m"
#define STYLE_STRIKE     "\033[9m"
#define STYLE_DIM        "\033[2m"
#define STYLE_NORMAL     "\033[22m"
#define STYLE_NO_UNDERLINE "\033[24m"
#define STYLE_NO_BLINK   "\033[25m"

// Reset to default
#define RESET            "\033[0m"

#endif // COLORS_H
