#include "lisp_test.h"

TEST_F(LispTest, DISABLED_SymbolsAreNotSelfEvaluating) {
    ExpectUndefinedVariable("x");

    ExpectEq("'x", "x");
    ExpectEq("(quote x)", "x");
}

TEST_F(LispTest, DISABLED_SymbolPredicate) {
    ExpectEq("(symbol? 'x)", "#t");
    ExpectEq("(symbol? 1)", "#f");
}

TEST_F(LispTest, DISABLED_SymbolsAreUsedAsVariableNames) {
    ExpectNoError("(define x (+ 1 2))");
    ExpectEq("x", "3");

    ExpectNoError("(define x (+ 2 2))");
    ExpectEq("x", "4");
}

TEST_F(LispTest, DISABLED_DefineInvalidSyntax) {
    ExpectSyntaxError("(define)");
    ExpectSyntaxError("(define 1)");
    ExpectSyntaxError("(define x 1 2)");
}

TEST_F(LispTest, DISABLED_SetOverrideVariables) {
    ExpectUndefinedVariable("(set! x 2)");
    ExpectUndefinedVariable("x");

    ExpectNoError("(define x 1)");
    ExpectEq("x", "1");

    ExpectNoError("(set! x (+ 2 4))");
    ExpectEq("x", "6");
}

TEST_F(LispTest, DISABLED_SetInvalidSyntax) {
    ExpectSyntaxError("(set!)");
    ExpectSyntaxError("(set! 1)");
    ExpectSyntaxError("(set! x 1 2)");
}
