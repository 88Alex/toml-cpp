#ifndef TOMLPARSER
#define TOMLPARSER

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "TomlElement.h"
#include "TomlKey.h"
#include "TomlArray.h"
#include "TomlHash.h"

using namespace std;

class TomlParser
{
    private:
        fstream stream;
        vector<TomlElement> elements;
    public:
        long parseInteger(string text);
        bool parseBoolean(string text);
        double parseDouble(string text);
        void clipSpaces(string& text);
        // [Date] parseDate(string text);
        void setFile(string name);
        void load();//this is where everything's done
        vector<TomlElement> getElements();
};

#endif //TOMLPARSER
