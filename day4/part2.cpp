#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

// function to check if a passport is valid.
bool isValid(std::unordered_map<std::string, std::string> m) {
    // first, check if all the necessary keys exist in the passport map.
    if(m.find("byr") != m.end() && m.find("iyr") != m.end() && m.find("eyr") != m.end() && m.find("hgt") != m.end() && m.find("hcl") != m.end() && m.find("ecl") != m.end() && m.find("pid") != m.end()) {
        
        // get whether the height is in cm or in by taking a substring of the last 2 characters.
        std::string unit = m["hgt"].substr(m["hgt"].size() - 2); 
        // get the height using the stoi function
        int height = std::stoi(m["hgt"]);
        // get the haircolor using the stoi function.
        std::string hcl = m["hcl"];
        // check if the haircolor is within the a-f and 0-9 range.
        // if it isn't, then return false since it's invalid.
        for(size_t i = 1; i < hcl.size(); i++) {
            if(!((hcl[i] >= 48 && hcl[i] <= 57) || (hcl[i] >= 97 && hcl[i] <= 102))) {
                return false;
            }
        }
        // get the eyecolor as a string.
        std::string ecl = m["ecl"];
        // get the personal ID as a string.
        std::string pid = m["pid"];
        // check if each character in the pid is in the 0-9 range, if it isn't then return false.
        for(size_t i = 0; i < pid.size(); i++) {
            if((pid[i] < '0') || (pid[i] > '9')) {
                return false;
            }
        }
        // if birth year isn't in the 1920-2002 range, return false. (must also be 4 digits)
        if(m["byr"].length() != 4 || std::stoi(m["byr"]) < 1920 || std::stoi(m["byr"]) > 2002) {
            return false;
        }
        // if birth year isn't in the 2010-2020 range, return false. (must also be 4 digits)
        else if(m["iyr"].length() != 4 || std::stoi(m["iyr"]) < 2010 || std::stoi(m["iyr"]) > 2020) {
            return false;
        }
        // if expiration year isn't in the 2020-2030 range, return false. (must also be 4 digits)
        else if(m["eyr"].length() != 4 || std::stoi(m["eyr"]) < 2020 || std::stoi(m["eyr"]) > 2030) {
            return false;
        }
        // make sure the units are valid!
        else if(unit != "cm" && unit != "in") {
            return false;
        }
        // if the unit is in cm, check it's height and make sure it's in the 150-193 range.
        else if((unit == "cm" && (height < 150 || height > 193))) {
            return false;
        }
        // if the unit is in in, check it's height and make sure it's in the 59-76 range.
        else if(unit == "in" && (height < 59 || height > 76)) {
            return false;
        }
        // make sure the first character of the hair color is the # character.
        else if(hcl[0] != '#') {
            return false;
        }
        // make sure the haircolor has 7 characters (# + the 6 chars)
        else if(m["hcl"].length() != 7) {
            return false;
        }
        // if ecl doesn't equal any of the values, return false.
        else if(ecl != "amb" && ecl != "blu" && ecl != "brn" && ecl != "gry" && ecl != "grn" && ecl != "hzl" && ecl != "oth") {
            return false;
        }
        // make sure the pid is 9 digits long.
        else if(pid.size() != 9) {
            return false;
        }
        // if everything is fine, return true. Valid passport! Woo!
        else {
            return true;
        }
    }
    // if any of the required keys dont exist, return false.
    else {
        return false;
    }
}

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

    // readh each line of the passports file.
    while(getline(passports, str)) {
        // if you reach an empty, new line; then the passport is finished reading. Start the verification process
        if(str == "") {
            // call the isValid function on the current passport to make sure it's valid.
            // if it is valid, increase the numValid variable to track it's number of valid passports.
            if(isValid(m)) {
                numValid++;
             }
             
             // clear the hashmap after verification so that we can use it for the next passport!
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
