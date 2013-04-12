#ifndef TOMLPARSER
#define TOMLPARSER
#include <iostream>
#include <fstream>

class TomlElement
{
    private:
        string name;
        string type;
        TomlElement parent;
    public:
        TomlElement getParent();
        string getName();
        string getFullName();
        TomlElement(string name_, TomlElement parent_, string type);
}

class TomlArray : TomlElement
{
    public:
        TomlElement[] getArrayElements();
        TomlArray(string name_, TomlElement parent_)
}

class TomlHash : TomlElement
{
    public:
        TomlElement[] getHashElements();
        TomlHash getParentHash();
}

class TomlParser
{
    private:
        static fstream stream;
    public:
        static void setFile(string name);
        static TomlElement getRootElement();//from there, it's on
}

#endif //TOMLPARSER
