#pragma once

#include <string>

#include <gtest/gtest.h>

struct LispTest : public ::testing::Test {
    // initialize new interpreter here
    LispTest() {}

    // evaluate expression and compare result to expected
    void ExpectEq(std::string expression, std::string result) {
        FAIL() << "Not implemented" << std::endl << expression << std::endl << result << std::endl;
    }

    // evaluate expression and check that there is not errors
    void ExpectNoError(std::string expression) {
        FAIL() << "Not implemented" << std::endl << expression << std::endl;
    }

    // check that expression evaluation produces syntax error
    void ExpectSyntaxError(std::string expression) {
        FAIL() << "Not implemented" << std::endl << expression << std::endl;
    }

    // check that expression evaluation produces runtime error
    void ExpectRuntimeError(std::string expression) {
        FAIL() << "Not implemented" << std::endl << expression << std::endl;
    }

    // check that expression evaluation produces name error
    void ExpectUndefinedVariable(std::string expression) {
        FAIL() << "Not implemented" << std::endl << expression << std::endl;
    }
};