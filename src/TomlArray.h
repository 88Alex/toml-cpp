#ifndef TOML_ARRAY
#define TOML_ARRAY

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

#endif //TOML_ARRAY
