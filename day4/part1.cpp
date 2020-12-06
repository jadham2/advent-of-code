#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

// NOTE: This project would probably be easier with regex. But, I don't know how to use regex! Woo!
int main() {

    // create an unordered map of strings, this will hold our keys.
    std::unordered_map<std::string, std::string> m;

    // variable for the number of valid passports.
    int numValid = 0;
    
    // open the passports file, starting to get used to C++ file handling.
    std::ifstream passports;
    passports.open("input.txt");

    // str stores the current passports line.
    std::string str;
    // key and value, classic hashmap.
    std::string key;
    std::string value;

    // read each line of the passports file.
    while(getline(passports, str)) {
        // if you reach an empty, new line; then the passport is finished reading. 
        if(str == "") {
            // if all the values required are present, increase numValid.
            if(m.find("byr") != m.end() && m.find("iyr") != m.end() && m.find("eyr") != m.end() && m.find("hgt") != m.end() && m.find("hcl") != m.end() && m.find("ecl") != m.end() && m.find("pid") != m.end()) {
                numValid++;
             }
            m.clear();
        }
        // otherwise read in data.
        else {
            // if readType is false, then you are reading in a key.
            // if it is true, you are reading in a value.
            bool readType = false;
            // parse the passport string until it reaches the delimeter.
            for(int i = 0; str[i] != '\0'; i++) {
                // if the string reaches a colon, then we are finished reading the key and must read the value.
                if(str[i] == ':') {
                    readType = true;
                    continue;
                }
                // otherwise if we hit a whitespace character, we are finished reading in a pair and must add the pair to the hashmap
                // and reset the variables for the next pair in the passport.
                else if(str[i] == ' ') {
                    m[key] = value;
                    readType = false;
                    key.clear();
                    value.clear();
                }
                // otherwise, we are reading in either a key or a value.
                else {
                    // if readType is true, you are reading in a value.
                    if(readType) {
                        value += str[i];
                    }
                    // otherwise if readType is false, you are reading in a key.
                    else {
                        key += str[i];
                    }
                }
            }
            // must flush the last pair since it never reaches it with the delimeter.
            m[key] = value;
            key.clear();
            value.clear();
        }
    }
	
    std::cout << numValid << "\n";
    // close your file!
    passports.close();

    return 0;
}
