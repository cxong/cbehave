/*
 * text_editor_test.c
 *
 * The test aims to show the usage of ASSERT
 */

#include <stdio.h>
#include <errno.h>
#include "cbehave.h"

FEATURE(open_existing, "Text Editor - Open Existing File")
    SCENARIO("Open an existing file and write something to it")
        FILE *fp = NULL;
        char *buf = "Hello Cbehave!";
        GIVEN("A file")
			fp = tmpfile();

        WHEN("we open the file and write something to it")
            ASSERT(fp, errno);
            fputs(buf, fp);

        THEN("We should see [Hello Cbehave] has been written into it")
            if (fp)
                fclose(fp);
    SCENARIO_END
FEATURE_END

CBEHAVE_RUN("Text Editor Features are as below:", TEST_FEATURE(open_existing))
