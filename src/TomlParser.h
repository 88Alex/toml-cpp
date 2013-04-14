#ifndef TOMLPARSER
#define TOMLPARSER
#include <iostream>
#include <fstream>
#include <vector>

class TomlElement
{
    private:
        string name;
        TomlElement parent;//null if its parent is the root
    public:
        virtual TomlElement getParent();
        virtual string getName();
        virtual string getFullName();
        //constructor deliberately left out.
        friend class TomlParser;
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
        friend class TomlParser;
}

class TomlArray : TomlElement
{
    private:
        vector<TomlElement> elements;
    public:
        vector<TomlElement> getArrayElements();
        TomlArray(string name_, TomlElement parent_, vector<TomlElement> elements_);
        string getType();//always returns "ARRAY"
        friend class TomlParser;
}

class TomlHash : TomlElement
{
    private:
        vector<TomlElement> elements;
    public:
        vector<TomlElement> getHashElements();
        TomlHash(string name_, TomlElement parent_, vector<TomlElement> elements_);
        string getType();//always returns "HASH"
        friend class Tomlparser;
}

class TomlParser
{
    private:
        static fstream stream;
    public:
        static void setFile(string name);
        static void load();//this is where everything's done
}

#endif //TOMLPARSER
