/*
 *          Copyright 2026, Vitali Baumtrok.
 * Distributed under the Boost Software License, Version 1.0.
 *     (See accompanying file LICENSE or copy at
 *        http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef ACA_BATCH_H
#define ACA_BATCH_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	const char *name;
	const char *vendor;
	char *data;
	uint32_t major, minor, patch;
} module_t;

typedef struct {
	module_t **modules;
	char *err_str; // must be allocated on heap
	uint32_t modules_len, index, pass, err1, err2;
} batch_run_t;

void aca_batch_alloc(void ***data, uint32_t data_len);
void aca_batch_run(void **data, uint32_t *err1, uint32_t *err2, uint32_t *err_idx, char **err_str, uint32_t len, uint32_t passes);
void aca_batch_free(void **data);

#ifdef __cplusplus
}
#endif

#endif /* ACA_BATCH_H */
