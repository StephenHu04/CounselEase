#include "Hasher.hpp"

#include <string>

using namespace std;

// Auxiliary methods for hashing strings
int base256conversion(const std::string &s);
int hashString(const std::string &s, int foldNum);

//Time complexity would be O(1) since it can be done in constant time
// Hashing a string uses a fold size of 2
int Hasher::hash(const int &s) {
	return hashString(to_string(s), 2);
}


//Time complexity would be O(n), n being the length of the fold
// Convert a string to its base-256 number
int base256conversion(const string &s) {
    int base = 1;
    int total = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        char c = s[i];
        total += (int)c * base;
        base *= 256;
    }
    return total;
}

//Time complexity would be O(n), n being the length of the string divided by the foldNum
//folds a string and returns a value
int hashString(const string &s, int foldNum) {
    int total = 0;
    for (unsigned i = 0; i < s.length(); i += foldNum) {
        // Look at foldNum-many characters at a time
        string temp = s.substr(i, foldNum);
        // Turn just that substring into a number and add it to our running total
        total += base256conversion(temp);
    }
    return total;
}
