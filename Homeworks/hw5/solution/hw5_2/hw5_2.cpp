#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>

std::string strip(const std::string &str);
std::string join(const std::string &sep, const std::vector<std::string> &strings);
std::vector<std::string> split(const std::string &str, const std::string &sep);
std::string swapcase(std::string str);

std::string strip(const std::string &str) {
    if (str.empty()) {
        return str;
    }
    std::size_t size = str.size();
    std::size_t left = 0, right = size - 1;
    while (left < size && std::isspace(str[left])) {
        left++;
    }
    while (right >= left && std::isspace(str[right])) {
        right--;
    }
    std::string ans = "";
    for (std::size_t i = left; i <= right; i++) {
        ans += str[i];
    }
    return ans;
}


std::string join(const std::string &sep, const std::vector<std::string> &strings) {
    std::string ans = "";
    if (strings.empty()) {
        return ans; 
    }
    std::size_t maxindex = strings.size() - 1;
    for (std::size_t i = 0; i < maxindex; i++) {
        ans += strings[i];
        ans += sep;
    }
    ans += strings[maxindex];
    return ans;
}


std::vector<std::string> split(const std::string &str, const std::string &sep) {
    std::vector<std::string> ans = {};
    std::size_t start = 0;
    if (sep.empty() || str.empty()) {
        ans.push_back(str);
        return ans;
    }
    while (true) {
        std::size_t end = str.find(sep, start);
        if (end == std::string::npos) {
            ans.push_back(str.substr(start));
            break;
        } else {
            ans.push_back(str.substr(start, end - start));
            start = end + sep.size();
        }
    }
    return ans;
}


std::string swapcase(std::string str) {
    std::string ans = "";
    for (std::size_t i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            ans += str[i] + 'A' - 'a';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            ans += str[i] + 'a' - 'A';
        } else {
            ans += str[i];
        }
    }
    return ans;
}