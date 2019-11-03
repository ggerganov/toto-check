/*! \file reload-archive-6-49.cpp
 *  \brief Enter description here.
 */

#include "common.h"

int main() {
    Data649::Issues issues;

    if (loadArchive(PATH_ARCHIVE_6_49, issues) == false) {
        fprintf(stderr, "Failed to read archive data\n");
        return -1;
    }

    if (saveArchive(PATH_ARCHIVE_6_49, issues) == false) {
        fprintf(stderr, "Failed to save archive data\n");
        return -2;
    }

    return 0;
}
