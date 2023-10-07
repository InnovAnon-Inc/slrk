//#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <check.h>

START_TEST(test_syslog) {
	//err_t e = syslog();
	//ck_assert_int_ne(e, EOF);
}
END_TEST

Suite *syslog_suite(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("Syslog");

	/* Core test case */
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_syslog);
	suite_add_tcase(s, tc_core);

	return s;
}

int main(void) {
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = syslog_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0)
	? EXIT_SUCCESS : EXIT_FAILURE;
}
