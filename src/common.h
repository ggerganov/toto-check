/*! \file common.h
 *  \brief Enter description here.
 */

#pragma once

#include <algorithm>
#include <array>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

#define PATH_ARCHIVE_6_49 "../data/6-49/archive-all.txt"

namespace Data649 {

struct Draw {
    int id = -1;
    std::array<int, 6> nums;
};

struct Issue {
    int id = -1;
    int idYear = -1;
    int year = -1;

    std::vector<Draw> draws;
};

struct Result {
    int idIssue = -1;
    int idDraw = -1;
};

struct Results {
    std::array<std::vector<Result>, 7> kOutOf6;
};

using Issues = std::vector<Issue>;

bool loadArchive(const char * fname, Issues & issues) {
    issues.clear();

    std::ifstream fin(fname);
    if (!fin.good()) return false;

    int curIssueId = 0;

    while (true) {
        std::string line;
        std::getline(fin, line);
        if (fin.eof()) break;

        std::vector<int> arr;
        std::istringstream iss(line);
        while (true) {
            int a;
            if (iss.eof()) break;
            iss >> a;
            arr.push_back(a);
        }

        int n = arr.size();
        if (n != 8 && n != 14 && n != 20 && n != 26) {
            fprintf(stderr, "Unexpected number of integers in archive line: %d\n", n);
            return false;
        }

        Issue issue;
        issue.id = curIssueId;
        issue.year = arr[0];
        issue.idYear = arr[1];

        int ndraws = (n - 2)/6;
        for (int i = 0; i < ndraws; ++i) {
            Draw draw;
            draw.id = i;
            draw.nums[0] = arr[2 + i*6 + 0];
            draw.nums[1] = arr[2 + i*6 + 1];
            draw.nums[2] = arr[2 + i*6 + 2];
            draw.nums[3] = arr[2 + i*6 + 3];
            draw.nums[4] = arr[2 + i*6 + 4];
            draw.nums[5] = arr[2 + i*6 + 5];

            issue.draws.emplace_back(std::move(draw));
        }

        issues.emplace_back(std::move(issue));

        ++curIssueId;
    }

    fin.close();

    return true;
}

bool saveArchive(const char * fname, const Issues & issues) {
    std::ofstream fout(fname);

    for (auto & issue : issues) {
        fout << std::setw(6) << issue.year << std::setw(4) << issue.idYear;
        for (auto & draw : issue.draws) {
            fout << " ";
            for (auto num : draw.nums) {
                fout << std::setw(3) << num;
            }
        }
        fout << std::endl;
    }

    fout.close();

    return true;
}

bool isValid(Draw draw) {
    std::sort(draw.nums.begin(), draw.nums.end());
    if (
            draw.nums[0] < 1 || draw.nums[5] > 49 ||
            draw.nums[0] == draw.nums[1] ||
            draw.nums[1] == draw.nums[2] ||
            draw.nums[2] == draw.nums[3] ||
            draw.nums[3] == draw.nums[4] ||
            draw.nums[4] == draw.nums[5]) {
        return false;
    }

    return true;
}

Results check(const Draw & drawToCheck, const Issues & issues) {
    Results results;

    for (auto & issue : issues) {
        for (auto & draw : issue.draws) {
            int k = 0;
            for (auto n0 : drawToCheck.nums) {
                for (auto n1 : draw.nums) {
                    if (n0 == n1) {
                        ++k;
                        break;
                    }
                }
            }
            Result result;
            result.idIssue = issue.id;
            result.idDraw = draw.id;
            results.kOutOf6[k].emplace_back(std::move(result));
        }
    }

    return results;
}

std::string toJson(const Issues & issues) {
    std::string result;

    result += '{';
    result += "\"issues\": [";
    for (int i = 0; i < (int) issues.size(); ++i) {
        auto & issue = issues[i];
        result += '{';
        result += "\"id\": " + std::to_string(issue.id) + ",";
        result += "\"idYear\": " + std::to_string(issue.idYear) + ",";
        result += "\"year\": " + std::to_string(issue.year) + ",";
        result += "\"draws\": [";
        for (int j = 0; j < (int) issue.draws.size(); ++j) {
            auto & draw = issue.draws[j];
            result += '[';
            result += std::to_string(draw.nums[0]) + ',';
            result += std::to_string(draw.nums[1]) + ',';
            result += std::to_string(draw.nums[2]) + ',';
            result += std::to_string(draw.nums[3]) + ',';
            result += std::to_string(draw.nums[4]) + ',';
            result += std::to_string(draw.nums[5]);
            result += ']';
            if (j == (int) issue.draws.size() - 1) break;
            result += ',';
        }
        result += ']';
        result += '}';
        if (i == (int) issues.size() - 1) break;
        result += ',';
    }
    result += ']';
    result += '}';

    return result;
}

}
