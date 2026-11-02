/*
 *          Copyright 2026, Vitali Baumtrok.
 * Distributed under the Boost Software License, Version 1.0.
 *     (See accompanying file LICENSE or copy at
 *        http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef ACA_ALLOCATOR_H
#define ACA_ALLOCATOR_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// cross module

typedef struct {
	const char *name;
	const char *vendor;
	char *data;
	uint32_t major, minor, patch;
} aca_module_t;

typedef struct {
	aca_module_t **modules;
	char *err_str;
	uint32_t modules_len, index, err1, err2;
	int32_t pass;
} aca_batch_run_t;

// public

extern void *aca_allocator_task;

#ifdef __cplusplus
}
#endif

#endif /* ACA_ALLOCATOR_H */
