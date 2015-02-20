#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std; 

std::vector<std::string>
parse_bash(const std::string& s, int& p) {
    std::vector<std::string> parsed;
    std::vector<std::string> res;
    res.push_back("");
    while (p < s.length()) {
        if (s[p] == '(') {
            p++;
            std::vector<std::string> substrings = parse_bash(s, p);
            std::vector<std::string> newres;
            for (std::string ss : substrings) {
                for (std::string r : res) {
                    newres.push_back(r + ss);
                }
            }
            res = newres;
        } else if (s[p] == ',') {
            parsed.insert(parsed.end(), res.begin(), res.end());
            res.clear();
            res.push_back("");
            p++;
        } else if (s[p] == ')') {
            p++;
            parsed.insert(parsed.end(), res.begin(), res.end());
            return parsed;
        } else {
            for (int i = 0; i < res.size(); ++i) {
                res[i] += s[p];
            }

            p++;
        }
    }
    parsed.insert(parsed.end(), res.begin(), res.end());
    return parsed;
}

int
main(int argc, char* argv[]) {
    if (argc > 1) {
        std::cout << argv[1] << std::endl;
        int p = 0;
        std::vector<std::string> res = parse_bash(argv[1], p);
        for (std::string s : res) {
            std::cout << s << std::endl;
        }
    }

    return 0;
}
