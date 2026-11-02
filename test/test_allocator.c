
/*
 *          Copyright 2026, Vitali Baumtrok.
 * Distributed under the Boost Software License, Version 1.0.
 *     (See accompanying file LICENSE or copy at
 *        http://www.boost.org/LICENSE_1_0.txt)
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdalign.h>
#include <string.h>
#include <aca/allocator.h>

#define ASSERT(a) if (!(a)) { *err_line = __LINE__; return; }

typedef void (*batch_task_func_t)(aca_batch_run_t *batch_run);

static void test_TODO(int *const err_line) {
	// TODO
}

void test_allocator(int *const err_line) {
	*err_line = 0;
	test_TODO(err_line);
}
