/* colors.h: terminal color definitions */
// from https://misc.flogisoft.com/bash/tip_colors_and_formatting
// colors are wrapped in \\[ and \\] to avoid characters being counted by bash

#define RESET   "\\[\x1B[0m\\]"

#define BOLD        "\\[\x1B[1m\\]"
#define DIM         "\\[\x1B[2m\\]"
#define ITALIC      "\\[\x1B[3m\\]"
#define UNDERLINE   "\\[\x1B[4m\\]"
#define BLINK       "\\[\x1B[5m\\]"
#define FASTBLINK   "\\[\x1B[6m\\]"
#define INVERT      "\\[\x1B[7m\\]"
#define HIDDEN      "\\[\x1B[8m\\]"
#define CROSSOUT    "\\[\x1B[9m\\]"
#define FRAMED      "\\[\x1B[51m\\]"
#define ENCIRCLE    "\\[\x1B[52m\\]"

#define DEFAULT     "\\[\x1B[39m\\]"
#define BLACK       "\\[\x1B[30m\\]"
#define RED         "\\[\x1B[31m\\]"
#define GREEN       "\\[\x1B[32m\\]"
#define YELLOW      "\\[\x1B[33m\\]"
#define BLUE        "\\[\x1B[34m\\]"
#define MAGENTA     "\\[\x1B[35m\\]"
#define CYAN        "\\[\x1B[36m\\]"
#define LI_GRAY     "\\[\x1B[37m\\]"

#define DARKGRAY    "\\[\x1B[90m\\]"
#define LI_RED      "\\[\x1B[91m\\]"
#define LI_GREEN    "\\[\x1B[92m\\]"
#define LI_YELLOW   "\\[\x1B[93m\\]"
#define LI_BLUE     "\\[\x1B[94m\\]"
#define LI_MAGENTA  "\\[\x1B[95m\\]"
#define LI_CYAN     "\\[\x1B[96m\\]"
#define WHITE       "\\[\x1B[97m\\]"

// bg colors
#define BG_DEFAULT  "\\[\x1B[49m\\]"
#define BG_BLACK    "\\[\x1B[40m\\]"
