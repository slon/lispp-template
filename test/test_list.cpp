#include "lisp_test.h"

TEST_F(LispTest, DISABLED_ListsAreNotSelfEvaliating) {
    ExpectRuntimeError("()");
    ExpectRuntimeError("(1)");
    ExpectRuntimeError("(1 2 3)");

    ExpectEq("'()", "()");
    ExpectEq("'(1)", "(1)");
    ExpectEq("'(1 2)", "(1 2)");
}

TEST_F(LispTest, DISABLED_ListSyntax) {
    ExpectEq("'(1 . 2)", "(1 . 2)");
    ExpectSyntaxError("(1 . 2 3)");

    ExpectEq("'(1 2 . 3)", "(1 2 . 3)");
    ExpectEq("'(1 2 . ())", "(1 2)");
    ExpectEq("'(1 . (2 . ()))", "(1 2)");
}

TEST_F(LispTest, DISABLED_ListInvalidSyntax) {
    ExpectSyntaxError("((1)");
    ExpectSyntaxError("(1))");
    ExpectSyntaxError(")(1)");

    ExpectSyntaxError("(.)");
    ExpectSyntaxError("(1 .)");
    ExpectSyntaxError("(. 2)");
}

TEST_F(LispTest, DISABLED_PairPredicate) {
    ExpectEq("(pair? '(1 . 2))", "#t");
    ExpectEq("(pair? '(1 2))", "#t");
    ExpectEq("(pair? '())", "#f");
}

TEST_F(LispTest, DISABLED_NullPredicate) {
    ExpectEq("(null? '())", "#t");
    ExpectEq("(null? '(1 2))", "#f");
    ExpectEq("(null? '(1 . 2))", "#f");
}

TEST_F(LispTest, DISABLED_ListPredicate) {
    ExpectEq("(list? '())", "#t");
    ExpectEq("(list? '(1 2))", "#t");
    ExpectEq("(list? '(1 . 2))", "#f");
    ExpectEq("(list? '(1 2 3 4 . 5))", "#f");
}

TEST_F(LispTest, DISABLED_PairOperations) {
    ExpectEq("(cons 1 2)", "(1 . 2)");
    ExpectEq("(car '(1 . 2))", "1");
    ExpectEq("(cdr '(1 . 2))", "2");
}

TEST_F(LispTest, DISABLED_PairMutations) {
    ExpectNoError("(define x '(1 . 2))");

    ExpectNoError("(set-car! x 5)");
    ExpectEq("(car x)", "5");

    ExpectNoError("(set-cdr! x 6)");
    ExpectEq("(cdr x)", "6");
}

TEST_F(LispTest, DISABLED_ListOperations) {
    ExpectEq("(list)", "()");
    ExpectEq("(list 1)", "(1)");
    ExpectEq("(list 1 2 3)", "(1 2 3)");

    ExpectEq("(list-ref '(1 2 3) 1)", "2");
    ExpectEq("(list-tail '(1 2 3) 1)", "(2 3)");
    ExpectEq("(list-tail '(1 2 3) 3)", "()");

    ExpectRuntimeError("(list-ref '(1 2 3) 3)");
    ExpectRuntimeError("(list-ref '(1 2 3) 10)");
    ExpectRuntimeError("(list-tail '(1 2 3) 10)");
}