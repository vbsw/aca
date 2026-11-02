/*
 *          Copyright 2026, Vitali Baumtrok.
 * Distributed under the Boost Software License, Version 1.0.
 *     (See accompanying file LICENSE or copy at
 *        http://www.boost.org/LICENSE_1_0.txt)
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <aca/allocator.h>

// private

static void module_task(aca_batch_run_t *const batch_run) {
	// TODO
}

// public

void *aca_allocator_task = module_task;
