/**
 * Fake reimplementation of libulog using stderr. Has no interest to be used,
 * apart for code publication, until the real one is released.
 * libulog: a minimalistic logging library derived from Android logger
 *
 * Author: Ivan Djelic <ivan.djelic@parrot.com>
 * Author: Nicolas Carrier <carrier.nicolas0@gmail.com>
 * Copyright (C) 2013 Parrot S.A.
 */
#ifndef _FAKE_ULOG_H
#define _FAKE_ULOG_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <inttypes.h>

/*----------------------------------------------------------------------------*/
/* ULOG API */
#define ULOG_DECLARE_TAG(name)

#define ULOG_CRIT    2
#define ULOG_ERR     3
#define ULOG_WARN    4
#define ULOG_NOTICE  5
#define ULOG_INFO    6
#define ULOG_DEBUG   7

#define ULOGC(...)      ULOG_PRI(ULOG_CRIT,   __VA_ARGS__)
#define ULOGE(...)      ULOG_PRI(ULOG_ERR,    __VA_ARGS__)
#define ULOGW(...)      ULOG_PRI(ULOG_WARN,   __VA_ARGS__)
#define ULOGN(...)      ULOG_PRI(ULOG_NOTICE, __VA_ARGS__)
#define ULOGI(...)      ULOG_PRI(ULOG_INFO,   __VA_ARGS__)
#define ULOGD(...)      ULOG_PRI(ULOG_DEBUG,  __VA_ARGS__)

#define ULOG_BUF_SIZE   256
#define ULOG_SET_LEVEL(level) (void)(level)
#define ULOG_GET_LEVEL() do { } while (0)

#ifdef __cplusplus
extern "C" {
#endif
static inline int ulog_set_tag_level(const char *name, int level) {return 0;}
static inline int ulog_get_tag_names(const char **names, int maxlen) {return 0;}

#ifdef __cplusplus
}
#endif

#define ULOG_INIT(name) (void)(name)

/*----------------------------------------------------------------------------*/
#define ULOG_PRI(_prio, ...)        ulog_log(_prio, NULL, __VA_ARGS__)
#define ULOG_PRI_VA(_prio, _f, _a)  ulog_vlog(_prio, NULL, _f, _a)
#define ULOG_STR(_prio, _str)       ulog_log_str(_prio, NULL, _str)
#define ULOG_BUF(_prio, _dat, _sz)  ulog_log_buf(_prio, NULL,_dat,_sz)
#define ULOG_BIN(_prio, _dat, _sz)  \
	ULOG_BUF(((_prio)|(1U << ULOG_PRIO_BINARY_SHIFT)), _dat, _sz)

#define ULOG_PRIO_LEVEL_MASK         0x7
#define ULOG_PRIO_BINARY_SHIFT       7
#define ULOG_PRIO_COLOR_SHIFT        8

#ifdef __cplusplus
extern "C" {
#endif
struct ulog_cookie {
	const char *name;
	int namesize;
	int level;
	struct ulog_cookie *next;
};

extern struct ulog_cookie __ulog_default_cookie;

__attribute__ ((format (printf, 3, 4)))
void ulog_log(uint32_t prio, struct ulog_cookie *cookie, const char *fmt, ...);
void ulog_vlog(uint32_t prio, struct ulog_cookie *cookie, const char *fmt,
		va_list ap);
void ulog_log_buf(uint32_t prio, struct ulog_cookie *cookie, const void *buf,
		int size);
void ulog_log_str(uint32_t prio, struct ulog_cookie *cookie, const char *str);
void ulog_init(struct ulog_cookie *cookie);
void ulog_set_level(struct ulog_cookie *cookie, int level);
int ulog_get_level(struct ulog_cookie *cookie);

#ifdef __cplusplus
}
#endif

#endif /* _FAKE_ULOG_H */
