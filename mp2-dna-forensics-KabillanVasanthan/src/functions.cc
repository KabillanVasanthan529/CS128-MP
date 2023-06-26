#include "functions.hpp"
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "utilities.hpp"
#include <vector>

using namespace std;

int LongestConsSeq(std::string seq, const std::string& pattern) {
    if (seq.find(pattern) == string::npos) {
        return 0;
    }
    int count = 1;
    unsigned int pos = seq.find(pattern) + pattern.length();
    while(pos + pattern.length() <= seq.length() && seq.substr(pos, pattern.length()) == pattern) {
        pos += pattern.length();
        count++;
    }
    seq = seq.substr(pos, seq.length() - pos);
    if(LongestConsSeq(seq, pattern) > count) {
        return LongestConsSeq(seq, pattern);
    }

    return count;
}
std::string Match(const std::string& data, std::string dna) {
    std::string match;
    int i = 0;
    std::vector<std::string> first_line;
    
    std::ifstream ifs{data};
    int persons = 0;
    for(std::string line; std::getline(ifs, line); line = "") {
        if(i == 0) {
            first_line = utilities::GetSubstrs(line, ',');
            i++;
            continue;
        }
        std::vector<std::string> vec = utilities::GetSubstrs(line, ',');
        bool matched = true;
        for (unsigned int j = 1; j < vec.size(); j++) {
            if (std::stoi(vec.at(j)) != LongestConsSeq(dna, first_line.at(j))) {
                matched = false;
            } 
        }
        if (matched) {
            match = vec.at(0);
            persons++;
        }
        if (persons > 1) {
            return "No Match";
        }
    }
    if(match.length() == 0) {
        return "No Match";
    }
    return match;
}