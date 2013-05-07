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
        static fstream stream;
        static vector<TomlElement> elements;
    public:
        static long parseInteger(string text);
        static bool parseBoolean(string text);
        static double parseDouble(string text);
        static void clipSpaces(string& text);
        //static [Date] parseDate(string text);
        static void setFile(string name);
        static void load();//this is where everything's done
        static vector<TomlElement> getElements();
};

#endif //TOMLPARSER
