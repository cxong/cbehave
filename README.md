cbehave - A Behavior Driven Development Framework for C
=======

A demonstration using real C code:

    #include "cbehave.h"

    // Step 1: define your functions
    int add(int a, int b);

    // Step 2: describe behaviour and the function calls
    FEATURE(1, "Addition")
        SCENARIO("Add two numbers")
            GIVEN("we have two numbers 50 and 70")
                int a = 50;
                int b = 70;
            GIVEN_END
            WHEN("we add them together")
                int r = add(a, b);
            WHEN_END
            THEN("the result should be 120")
                SHOULD_INT_EQUAL(r, 120);
            THEN_END
        SCENARIO_END
    FEATURE_END

    // Step 3: write empty implementations of functions
    int add(int a, int b)
    {
        // Step 5: write code to make the behaviour pass
        return a + b;
    }

    // Step 4: run tests and watch them fail (and succeed later)
    int main()
    {
        cbehave_feature calculator_features[] = {
            {feature_idx(1)}
        };

        return cbehave_runner(
            "Calculator Features are as belows:",
            calculator_features);
    }

Recent News
-----------
 - 2013-04-02 fork a copy to https://github.com/bigwhite/cbehave.git.
 - 2012-04-16 cbehave 0.2.0 released.
 - 2011-08-14 cbehave 0.1.0 version released.

Introduction
-------------
CBehave - A Behavior Driven Development Framework for C.

Main Features
-------------

 - use the "feature + scenario" structure (inspired by Cucumber)
 - use classical "given-when-then" template to describe behavior scenarios
 - support mock

User Guide
-------------
For more information, please open and read the project wiki. cbehave user guide is ready for you.

