#pragma once
#include <sstream>
#include <vector>
#include <algorithm>

struct Version {

    enum Result {
          LESS
        , GRETTER
        , EQUAL
    };

    explicit Version(const std::string& version, char delimiter = '.') {
        for (const auto& el : split(version, delimiter)) {
            _version.emplace_back(std::stoi(el));
        }
    }
    bool operator<(const Version& other) const {
        return LESS == compare(other);
    }

    bool operator>(const Version& other) const {
        return !operator<(other);
    }

    bool operator==(const Version& other) const {
        return EQUAL == compare(other);
    }

    bool operator!=(const Version& other) const {
        return !operator==(other);
    }

    bool operator>=(const Version& other) const  {
        return !operator<(other);
    }

    bool operator<=(const Version& other) const {
        return !operator>(other);
    }

private:

    std::vector<std::string> split(const std::string& str, char delimiter) const {
       std::vector<std::string> tokens;
       std::string token;
       std::istringstream tokenStream(str);
       while (std::getline(tokenStream, token, delimiter)) {
          tokens.emplace_back(token);
       }
       return tokens;
    }

    Result compare(const Version& other) const {
        const auto thisSize  = _version.size();
        const auto otherSize = other._version.size();
        const auto maxSize   = std::max(thisSize, otherSize);

        const auto completeByZeros = [](std::vector<int> vec, std::size_t newSize) {
            vec.resize(newSize);
            return vec;
        };

        const auto& thisVersion  =  thisSize == maxSize ? this->_version : completeByZeros(this->_version, maxSize);
        const auto& otherVersion = otherSize == maxSize ? other._version : completeByZeros(other._version, maxSize);

        for (std::size_t i = 0; i < maxSize; ++i) {
            if (thisVersion[i] > otherVersion[i]) {
                return GRETTER;
            }
            if (thisVersion[i] < otherVersion[i]) {
                return LESS;
            }
        }

        return EQUAL;
    }

private:

    std::vector<int> _version;

};
