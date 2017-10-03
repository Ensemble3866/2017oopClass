#ifndef UTTERM_H
#define UTTERM_H
#include <string>
#include "number.h"

//test Number.value()
TEST (Number,ctor) {
    Number _1("1");
    ASSERT_EQ("1", _1.value());
}
//test Number.symbol()
TEST (Number, symbol) {
    Number _2("2");
    ASSERT_EQ("_2", _2.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
    Number _25("25");
    ASSERT_TRUE(_25 = _25);
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
    Number _25("25");
    Number _0("0");
    ASSERT_FALSE(_25 = _0);
}

//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
    Number _25("25");
    Atom tom("tom");
    ASSERT_FALSE(_25 = tom);
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
    Number _25("25");
    Variable X("X");
    ASSERT_TRUE(_25 = X);
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
    Number _25("25");
    Atom tom("tom");
    ASSERT_FALSE(tom = _25);
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
    Atom tom("tom");
    Variable X("X");
    tom = X;
    ASSERT_EQ("tom", X.value());
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
    Atom tom("tom");
    Variable X("X");
    // X = tom;
    //tom = X;
    //ASSERT_EQ("tom", X.value());
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
    Atom tom("tom");
    Atom jerry("jerry");
    Variable X("X");
    //X = jerry;
    //ASSERT_FALSE(tom = X);
}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {
    Number _5("5");
    Variable X("X");
    //X = _5;
    //ASSERT_EQ("5", X.value());
}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers) {

}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber) {

}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {

}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){

}
#endif
