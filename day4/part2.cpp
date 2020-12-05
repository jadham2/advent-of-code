#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

bool isValid(std::unordered_map<std::string, std::string> m) {
    if(m.find("byr") != m.end() && m.find("iyr") != m.end() && m.find("eyr") != m.end() && m.find("hgt") != m.end() && m.find("hcl") != m.end() && m.find("ecl") != m.end() && m.find("pid") != m.end()) {
        std::string unit = m["hgt"].substr(m["hgt"].size() - 2); 
        int height = std::stoi(m["hgt"]);
        std::string hcl = m["hcl"];
        for(size_t i = 1; i < hcl.size(); i++) {
            if(!((hcl[i] >= 48 && hcl[i] <= 57) || (hcl[i] >= 97 && hcl[i] <= 102))) {
                return false;
            }
        }
        std::string ecl = m["ecl"];
        std::string pid = m["pid"];
        for(size_t i = 0; i < pid.size(); i++) {
            if((pid[i] < '0') || (pid[i] > '9')) {
                return false;
            }
        }
        if(m["byr"].length() != 4 || std::stoi(m["byr"]) < 1920 || std::stoi(m["byr"]) > 2002) {
            return false;
        }
        else if(m["iyr"].length() != 4 || std::stoi(m["iyr"]) < 2010 || std::stoi(m["iyr"]) > 2020) {
            return false;
        }
        else if(m["eyr"].length() != 4 || std::stoi(m["eyr"]) < 2020 || std::stoi(m["eyr"]) > 2030) {
            return false;
        }
        else if(unit != "cm" && unit != "in") {
            return false;
        }
        else if((unit == "cm" && (height < 150 || height > 193))) {
            return false;
        }
        else if(unit == "in" && (height < 59 || height > 76)) {
            return false;
        }
        else if(hcl[0] != '#') {
            return false;
        }
        else if(m["hcl"].length() != 7) {
            return false;
        }
        // if ecl doesn't equal any of the values.
        else if(ecl != "amb" && ecl != "blu" && ecl != "brn" && ecl != "gry" && ecl != "grn" && ecl != "hzl" && ecl != "oth") {
            return false;
        }
        else if(pid.size() != 9) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

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
        if(str == "") {
            // if all the values required are present, increase numValid.
            if(isValid(m)) {
                numValid++;
             }
             
             m.clear();
        }
        // otherwise read in data.
        
        else {
            // if readType is false, then you are reading in a key.
            // if it is true, you are reading in a value.
            bool readType = false;
            for(size_t i = 0; i < str.size(); i++) {
                if(str[i] == ':') {
                    readType = true;
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
