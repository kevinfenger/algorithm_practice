#include <stdlib.h> 
#include <stdio.h> 
#include <iostream>
#include <map> 
#include <sstream> 

using namespace std; 

string
processXml(string xml) {
    map<string,int> tags; 
    tags["family"] = 1;  
    tags["person"] = 2; 
    tags["firstName"] = 3; 
    tags["lastName"] = 4;
    tags["state"] = 5; 

    if (xml.empty()) return ""; 
    string::iterator reader;
    bool foundStartTag = false, foundEndTag = false, valueHunting = false;  
    stringstream output;
    stringstream currentTag;
    stringstream value; 
    
    for (reader = xml.begin(); reader != xml.end() ; reader++) { 
        if (*reader == '<') {
            foundStartTag = true;  
            if (valueHunting && !value.str().empty()) { 
                output << value.str() << " "; 
                value.str(string()); 
                valueHunting = false;  
            }
            foundEndTag = false;
        }
        else if (*reader == '>') { 
            foundStartTag = false; 
            foundEndTag = true; 
            valueHunting = true;  
            output << 0 << " "; 
        }  
        else if (foundStartTag) { 
            if (*reader == '/') { 
                foundStartTag = false; 
            }
            else if (*reader == '"') { 
                valueHunting = true;
                foundStartTag = false; 
            }
            else if (isspace(*reader) || *reader == '=') {
                auto it = tags.find(currentTag.str());  
                if (it != tags.end()) { 
                    output << it->second << " "; 
                }
                currentTag.str(string()); 
            } 
            else { 
                currentTag << *reader; 
            }
        }
        else if (valueHunting) {  
            if (*reader == '"') { 
                valueHunting = false;
                foundStartTag = true; 
                output << value.str() << " "; 
                value.str(string()); 
            }
            else { 
                value << *reader; 
            }
        } 
    }
    return output.str();  
}

int main() { 
    stringstream xml; 
    xml << "<family lastName=\"McDowell\" state=\"CA\"><person firstName=\"Gayle\">Some Message</person></family>"; 
    cout << processXml(xml.str()) << endl; 
}
