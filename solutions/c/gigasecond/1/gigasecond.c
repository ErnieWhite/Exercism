#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size)
{
    time_t aged = input + 1000000000; // one gigasecond
    struct tm *timeinfo = gmtime(&aged);
    strftime(output, size, "%Y-%m-%d %H:%M:%S", timeinfo);
}
