
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
#include <aca/batch.h>

#define TEST_RUN0_LENGTH 2
#define TEST_RUN0_PASSES 1

#define TEST_RUN1_LENGTH 3
#define TEST_RUN1_PASSES 2

#define ASSERT(a) if (!(a)) { *err_line = __LINE__; return; }

static aca_module_t test_run0_mod_a = {"ab", "cde", NULL, 1, 2, 3};
static aca_module_t test_run0_mod_b = {"fghi", "jklmn", NULL, 4, 5, 6};

static aca_module_t test_run1_mod_a = {"ab", "cde", NULL, 1, 2, 3};

static void test_run0_func_a(aca_batch_run_t *const batch_run) {
	batch_run->modules[batch_run->index] = &test_run0_mod_a;
}
static void test_run0_func_b(aca_batch_run_t *const batch_run) {
	batch_run->modules[batch_run->index] = &test_run0_mod_b;
}

static void test_run1_func_a(aca_batch_run_t *const batch_run) {
	if (batch_run->pass == 0) {
		batch_run->modules[batch_run->index] = &test_run1_mod_a;
	} else if (batch_run->pass == 1) {
		batch_run->err1 = 2; // test failed
		batch_run->err2 = 1;
	} else if (batch_run->pass != -1){
		batch_run->err1 = 2; // test failed
		batch_run->err2 = 2;
	}
}
static void test_run1_func_b(aca_batch_run_t *const batch_run) {
	if (batch_run->pass == 0) {
		batch_run->err1 = 1; // test ok; expected err
	} else if (batch_run->pass == 1) {
		batch_run->err1 = 2; // test failed
		batch_run->err2 = 3;
	} else if (batch_run->pass != -1){
		batch_run->err1 = 2; // test failed
		batch_run->err2 = 4;
	}
}
static void test_run1_func_c(aca_batch_run_t *const batch_run) {
	if (batch_run->pass >= 0) {
		batch_run->err1 = 2; // test failed
		batch_run->err2 = 5;
	} else if (batch_run->pass < 0){
		batch_run->err1 = 2; // test failed
		batch_run->err2 = 6;
	}
}

static void test_alloc(int *const err_line) {
	void **data = NULL;
	aca_batch_alloc(&data, 2);

	ASSERT(data)

	aca_batch_free(data);
}

static void test_run0(int *const err_line) {
	void **data = NULL;
	uint32_t err1 = 0, err2 = 0, err_idx = 0;
	char *str = NULL;

	aca_batch_alloc(&data, TEST_RUN0_LENGTH);
	ASSERT(data)

	data[0] = (void*)test_run0_func_a;
	data[1] = (void*)test_run0_func_b;
	aca_batch_run(data, TEST_RUN0_LENGTH, TEST_RUN0_PASSES, &err1, &err2, &err_idx, &str);
	ASSERT(!err1)
	ASSERT(data[TEST_RUN0_LENGTH+0] == (void*)&test_run0_mod_a)
	ASSERT(data[TEST_RUN0_LENGTH+1] == (void*)&test_run0_mod_b)

	aca_batch_free(data);
}

static void test_run1(int *const err_line) {
	void **data = NULL;
	uint32_t err1 = 0, err2 = 0, err_idx = 0;
	char *str = NULL;

	aca_batch_alloc(&data, TEST_RUN1_LENGTH);
	ASSERT(data)

	data[0] = (void*)test_run1_func_a;
	data[1] = (void*)test_run1_func_b;
	data[2] = (void*)test_run1_func_c;
	aca_batch_run(data, TEST_RUN1_LENGTH, TEST_RUN1_PASSES, &err1, &err2, &err_idx, &str);
	ASSERT(err1)
	ASSERT(!err2)
	ASSERT(data[TEST_RUN1_LENGTH+0] == (void*)&test_run1_mod_a)
	ASSERT(data[TEST_RUN1_LENGTH+1] == NULL)
	ASSERT(data[TEST_RUN1_LENGTH+2] == NULL)

	aca_batch_free(data);
}

void test_batch(int *const err_line) {
	*err_line = 0;
	test_alloc(err_line);
	test_run0(err_line);
	test_run1(err_line);
}
