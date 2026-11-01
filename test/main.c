/*
 *          Copyright 2026, Vitali Baumtrok.
 * Distributed under the Boost Software License, Version 1.0.
 *     (See accompanying file LICENSE or copy at
 *        http://www.boost.org/LICENSE_1_0.txt)
 */

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define UNUSED(a) (void)(a);

#define PRINT_RESULT_CLM_A(unt) if (!err_line) printf("%-8s %-21s", unt, "PASS"); else printf("%-6s FAIL line %-11d", unt, err_line);
#define PRINT_RESULT_CLM_B(unt) if (!err_line) printf("%-8s PASS\n", unt); else printf("%-6s FAIL line %d\n", unt, err_line);

void test_batch(int *err_line);

int main(int argc, char **argv) {
	UNUSED(argc)
	UNUSED(argv)
	int err_line;
	test_batch(&err_line); PRINT_RESULT_CLM_A("batch")
	printf("\n");

	return 0;
}
