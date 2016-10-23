#include <gtest/gtest.h>

#include "lisp_test.h"

TEST_F(LispTest, DISABLED_Quote) {
    ExpectEq("(quote (1 2))", "(1 2)");
}
