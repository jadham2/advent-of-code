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
                std::string unit = m["hgt"].substr(m["hgt"].length() - 2); 
                int height = std::stoi(m["hgt"]);
                std::string hcl = m["hcl"];
                bool validHair = true;
                for(int i = 1; hcl[i] != '\0'; i++) {
                    if(hcl[i] < '0' || hcl[i] > '9') {
                        if(hcl[i] < 'a' || hcl[i] > 'f') {
                            validHair = false;
                        }
                    }
                }
                std::string ecl = m["ecl"];
                std::string pid = m["pid"];
                bool validPid = true;
                for(int i = 0; pid[i] != '\0'; i++) {
                    if(pid[i] < '0' || pid[i] > '9') {
                        validPid = false;
                    }
                }
                if(m["byr"].length() != 4 || std::stoi(m["byr"]) < 1920 || std::stoi(m["byr"]) > 2002) {
                    m.clear();
                }
                else if(m["iyr"].length() != 4 || std::stoi(m["iyr"]) < 2010 || std::stoi(m["iyr"]) > 2020) {
                    m.clear();
                }
                else if(m["eyr"].length() != 4 || std::stoi(m["eyr"]) < 2020 || std::stoi(m["eyr"]) > 2030) {
                    m.clear(); 
                }
                else if(unit != "cm" && unit != "in") {
                    m.clear();
                }
                else if((unit == "cm" && (height < 150 || height > 193)) || (unit == "in" && (height < 59 || height > 76))) {
                    m.clear();
                }
                else if(hcl[0] != '#') {
                    m.clear();
                }
                else if(!validHair || m["hcl"].length() != 7) {
                    m.clear();
                }
                // if ecl doesn't equal any of the values.
                else if(ecl != "amb" && ecl != "blu" && ecl != "brn" && ecl != "gry" && ecl != "grn" && ecl != "hzl" && ecl != "oth") {
                    m.clear();
                }
                else if(!validPid || m["pid"].length() != 9) {
                    m.clear();
                }
                else {
                    m.clear();
                    numValid++;
                }
             }
        }
        // otherwise read in data.
        else {
            // if readType is false, then you are reading in a key.
            // if it is true, you are reading in a value.
            bool readType = false;
            for(int i = 0; str[i] != '\0'; i++) {
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
