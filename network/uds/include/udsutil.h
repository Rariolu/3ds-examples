#ifndef UDS_UTIL_H
#define UDS_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <errno.h>
#include <stdarg.h>
#include <unistd.h>

#include <3ds.h>

void closeOnInputTrigger(u32 button);
void print_constatus();
void uds_test();

#endif