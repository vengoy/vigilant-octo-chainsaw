#include "tests_includes/s21_tests.h"

int main(void) {
    run_tests();
    return 0;
}

void run_testcase(Suite *testcase) {
    // TD
    setlocale(LC_ALL,"");
    //setlocale(LC_ALL, "C");
    static int counter_testcase = 1;

    if (counter_testcase > 1)
        putchar('\n');
    printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
    counter_testcase++;

    SRunner *sr = srunner_create(testcase);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    srunner_free(sr);
    sleep(1);
}

void run_tests(void) {
    Suite *list_cases[] = {suite_memchr(), suite_strerror(), suite_memcpy(),
                           suite_memcmp(), suite_memmove(), suite_memset(),
                           suite_strcat(), suite_strncat(), suite_strchr(),
                           suite_strlen(), suite_strcmp(), suite_strncmp(),
                           suite_strcpy(), suite_strncpy(), suite_strcspn(),
                           suite_strpbrk(), suite_strrchr(),
                           suite_strstr(), suite_strspn(), suite_strtok(),
                           suite_insert(), suite_atoi(), suite_sprintf(),
                           suite_trim(), suite_to_lower(), suite_strntollu(),
                           suite_strtold(), suite_sscanf(), suite_to_upper(),
                           NULL};

    for (Suite **current_testcase = list_cases; *current_testcase != NULL; current_testcase++) {
        run_testcase(*current_testcase);
    }
}
