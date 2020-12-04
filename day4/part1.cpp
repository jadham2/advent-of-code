#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

int main() {

    std::unordered_map<std::string, std::string> m;
    int numValid = 0;
    std::ifstream passports;
    passports.open("input.txt");
    std::string str;
    std::string key;
    std::string value;
    while(getline(passports, str)) {
        // if you reach an empty, new line; then the passport is finished reading. 
        if(!str.compare("")) {
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
            for(int i = 0; str[i] != '\0'; i++) {
                if(str[i] == ':') {
                    readType = true;
                    continue;
                }
                else if(str[i] == ' ') {
                    m[key] = value;
                    readType = false;
                    key.clear();
                    value.clear();
                }
                else {
                    // if you are reading in a value.
                    if(readType) {
                        value += str[i];
                    }
                    else {
                        key += str[i];
                    }
                }
            }
            m[key] = value;
            key.clear();
            value.clear();
        }
    }
	
    std::cout << numValid << "\n";
    passports.close();
	return 0;
}
