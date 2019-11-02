/*! \file check-cli-6-49.cpp
 *  \brief Enter description here.
 */

#include "common.h"

int main(int argc, char ** argv) {
    if (argc < 7) {
        printf("Usage: %s n0 n1 n2 n3 n4 n5\n", argv[0]);
        return -1;
    }
    Data649::Issues issues;

    if (loadArchive(PATH_ARCHIVE_6_49, issues) == false) {
        fprintf(stderr, "Failed to read archive data\n");
        return -1;
    }

    Data649::Draw draw;
    draw.nums[0] = atoi(argv[1]);
    draw.nums[1] = atoi(argv[2]);
    draw.nums[2] = atoi(argv[3]);
    draw.nums[3] = atoi(argv[4]);
    draw.nums[4] = atoi(argv[5]);
    draw.nums[5] = atoi(argv[6]);

    Data649::Results results;
    if (Data649::isValid(draw)) {
        results = Data649::check(draw, issues);
    } else {
        fprintf(stderr, "Invalid 6/49 draw\n");
    }

    for (int k = 0; k < 7; ++k) {
        printf("%d - %d\n", k, (int) results.kOutOf6[k].size());
    }

    return 0;
}
