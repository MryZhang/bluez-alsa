/*
 * test.inc
 * vim: ft=c
 *
 * Copyright (c) 2016 Arkadiusz Bokowy
 *
 * This file is a part of bluez-alsa.
 *
 * This project is licensed under the terms of the MIT license.
 *
 * This file contains definitions of log functions for testing purposes. It
 * should be included as is in the test program.
 *
 */

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

static int test_error_count;
static int test_warn_count;
static int test_info_count;

static char test_error_msg[512];
static char test_warn_msg[512];
static char test_info_msg[512];

#define test_run(f) \
	test_error_count = test_warn_count = test_info_count = 0; \
	*test_error_msg = *test_warn_msg = *test_info_msg = '\0'; \
	assert(!f())

void error(const char *format, ...) {
	va_list ap;
	va_start(ap, format);
	vsprintf(test_error_msg, format, ap);
	va_end(ap);
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	fputc('\n', stderr);
	va_end(ap);
	test_error_count++;
}

void warn(const char *format, ...) {
	va_list ap;
	va_start(ap, format);
	vsprintf(test_warn_msg, format, ap);
	va_end(ap);
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	fputc('\n', stderr);
	va_end(ap);
	test_warn_count++;
}

void info(const char *format, ...) {
	va_list ap;
	va_start(ap, format);
	vsprintf(test_info_msg, format, ap);
	va_end(ap);
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	fputc('\n', stderr);
	va_end(ap);
	test_info_count++;
}

void _debug(const char *format, ...) {
	va_list ap;
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	fputc('\n', stderr);
	va_end(ap);
}
