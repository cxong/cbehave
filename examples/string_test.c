/*
 * string_test.c
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "cbehave.h"

FEATURE(strstr, "strstr")
    SCENARIO("The strstr finds the first occurrence of the substring in the source string")

        GIVEN("A source string: Lionel Messi is a great football player")
            char *str = "Lionel Messi is a great football player";

        WHEN("we use strstr to find the first occurrence of [football]")
            char *p = strstr(str, "football");

        THEN("We should get the string: [football player]")
            SHOULD_STR_EQUAL(p, "football player");

    SCENARIO_END

    SCENARIO("If strstr could not find the first occurrence of the substring, it will return NULL")

        GIVEN("A source string: FC Barcelona is a great football club.")
            char *str = "FC Barcelona is a great football club";

        WHEN("we use strstr to find the first occurrence of [AC Milan]")
            char *p = strstr(str, "AC Milan");

        THEN("We should get no string but a NULL")
            SHOULD_STR_EQUAL(p, NULL);
    SCENARIO_END

FEATURE_END

CBEHAVE_RUN("Strstr Features are as below:", TEST_FEATURE(strstr))
