/*! \file check-cli-6-49.cpp
 *  \brief Enter description here.
 */

#include "common.h"

#include "incppect/incppect.h"

#include <mutex>

int main(int argc, char ** argv) {
    printf("Usage: %s [port] [http-root]\n", argv[0]);

    int port = 3000;
    std::string httpRoot = "../static/";

    if (argc > 1) port = atoi(argv[1]);
    if (argc > 2) httpRoot = argv[2];

    Incppect::Parameters parameters;
    parameters.portListen = port;
    parameters.maxPayloadLength_bytes = 4*1024*1024;
    parameters.httpRoot = httpRoot;
    Incppect::getInstance().runAsync(parameters).detach();

    std::mutex mutex;
    std::string jsonIssues = "{}";
    Incppect::getInstance().var("jsonIssues", [&](auto) {
        std::lock_guard lock(mutex);
        return Incppect::view(jsonIssues);
    });

    Data649::Issues issues;

    while (true) {
        printf("Reloading archive data\n");

        if (loadArchive(PATH_ARCHIVE_6_49, issues) == false) {
            fprintf(stderr, "Failed to read archive data\n");
            return -1;
        }

        {
            std::lock_guard lock(mutex);
            jsonIssues = Data649::toJson(issues);
        }

        std::this_thread::sleep_for(std::chrono::seconds(24*3600));
    }

    return 0;
}
