#ifndef TOMLPARSER
#define TOMLPARSER

#include <iostream>
#include <fstream>
#include <vector>
#include "TomlElement.h"
#include "TomlKey.h"
#include "TomlArray.h"
#include "TomlHash.h"

class TomlParser
{
    private:
        static fstream stream;
        static vector<TomlElement> elements;
    public:
        static void setFile(string name);
        static void load();//this is where everything's done
        static vector<TomlElement> getElements();
}

#endif //TOMLPARSER
