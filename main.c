
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka.h"
#include <string.h>
#include "ratp.h"
#include "age.h"

/* A test case that does nothing and succeeds. */

void recupAge(int* limit) {
    function_called();
    *limit = (int) mock(); 
}

static int setup(void **state) {
    (void) state;
    printf("setUp");
 return 0;
}

static int teardown(void **state) {
    (void) state;
    printf("tearDown");
     return 0;
}

static void null_test_success(void **state) {
    (void) state;
}

static void test_inf_12(void **state) {
    (void) state;

    will_return(recupAge, 12);
    float prix;
    expect_function_calls(recupAge, 1);
    prix = computePrice(6);
    assert_float_equal(0.75, prix, 0.0001);
}

static void test_inf_12True(void **state) {
    (void) state;

    will_return(recupAge, 11);
    float prix;
    expect_function_calls(recupAge, 1);
    prix = computePrice(6);
    assert_true(0.75 == prix);
}

static void test_sup_12(void **state) {
    (void) state;

    will_return(recupAge, 12);
    float prix;
    expect_function_calls(recupAge, 1);
    prix = computePrice(16);
    assert_float_equal(1.5, prix, 0.0001);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test_setup(test_inf_12, setup),
        cmocka_unit_test(test_inf_12True),
        cmocka_unit_test(test_sup_12),
    };
 //   cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests_name("toto",tests, setup, teardown);
}
