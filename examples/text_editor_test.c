/*
 * text_editor_test.c
 *
 * The test aims to show the usage of ASSERT
 */

#include <stdio.h>
#include <errno.h>
#include "cbehave.h"

FEATURE(1, "Text Editor - Open Exsited File")
    SCENARIO("Open an Exsited File and write something to it")
    {
        FILE *fp = NULL;
        char *buf = "Hello Cbehave!";
        GIVEN("A file named foo.txt")
        GIVEN_END

        WHEN("we open the file and write something to it")
            fp = fopen("foo.txt", "r+");
            ASSERT(fp, errno);
        WHEN_END

        THEN("We should see [Hello Cbehave] has been written into foo.txt")
            if (fp)
                fclose(fp);
        THEN_END
    }
    SCENARIO_END
FEATURE_END

int main() {
    cbehave_feature editor_features[] = {
        {feature_idx(1)},
    };

    return cbehave_runner("Text Editor Features are as belows:", editor_features);
}
