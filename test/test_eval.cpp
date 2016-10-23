#include <gtest/gtest.h>

#include "lisp_test.h"

TEST_F(LispTest, Quote) {
    ExpectEq("(quote (1 2))", "(1 2)");
}

TEST_F(LispTest, Lambda) {
    ExpectEq("((lambda (x) (+ 1 x)) 5)", "6");
}
