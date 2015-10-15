/*
 * ulog.c
 *
 *  Created on: Oct 15, 2015
 *      Author: ncarrier
 */
#include "ulog.h"

#include <stdio.h>

struct ulog_cookie __ulog_default_cookie;

void ulog_log(uint32_t prio, struct ulog_cookie *cookie, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	ulog_vlog(prio, cookie, fmt, ap);
	va_end(ap);
}

void ulog_vlog(uint32_t prio, struct ulog_cookie *cookie, const char *fmt,
		va_list ap)
{
	static const char * const priotab[8] = {
		"  ",
		"  ",
		"\e[7;31mC\e[0m ",
		"\e[1;31mE\e[0m ",
		"\e[1;33mW\e[0m ",
		"\e[1;32mN\e[0m ",
		"\e[1;35mI\e[0m ",
		"\e[1;36mD\e[0m "
	};
	
	fputs(priotab[prio], stderr);
	vfprintf(stderr, fmt, ap); 
	fputs("\n", stderr);
}

void ulog_log_buf(uint32_t prio, struct ulog_cookie *cookie, const void *buf,
		int size)
{

}

void ulog_log_str(uint32_t prio, struct ulog_cookie *cookie, const char *str)
{

}

void ulog_init(struct ulog_cookie *cookie)
{

}

void ulog_set_level(struct ulog_cookie *cookie, int level)
{

}

int ulog_get_level(struct ulog_cookie *cookie)
{
	return ULOG_DEBUG;
}
