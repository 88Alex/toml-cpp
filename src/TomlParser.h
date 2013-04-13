#ifndef TOMLPARSER
#define TOMLPARSER
#include <iostream>
#include <fstream>

class TomlElement
{
    private:
        string name;
        TomlElement parent;//null if its parent is the root
    public:
        virtual TomlElement getParent() = 0;//pure virtual function!
        virtual string getName();
        virtual string getFullName();
}

class TomlKey : TomlElement
{
    private:
        string type;//All caps, short form i.e. STRING, NUMBER, BOOL, DATE.
        string value;
    public:
        string getType();
        string getValue();//You can parse it afterwards.
        TomlKey(string name_, string type_, string value_);
}

class TomlArray : TomlElement
{
    public:
        TomlElement[] getArrayElements();
        TomlArray(string name_, TomlElement parent_);
        string getType();//always returns "ARRAY"
        TomlKey[] getElements();
}

class TomlHash : TomlElement
{
    public:
        TomlElement[] getHashElements();
        TomlHash(string name_, TomlElement parent_);
        string getType();//always returns "HASH"
        TomlElement[] getChildElements();
}

class TomlParser
{
    private:
        static fstream stream;
    public:
        static void setFile(string name);
        static void load();
}

#endif //TOMLPARSER
