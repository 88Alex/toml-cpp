#ifndef TOML_ARRAY
#define TOML_ARRAY
#include <string>
#include <vector>

using namespace std;

class TomlArray : TomlElement
{
    private:
        vector<TomlElement> elements;
    public:
        vector<TomlElement> getElements();
        TomlArray(string name_, TomlElement parent_, vector<TomlElement> elements_);
        string getType();//always returns "ARRAY"
        friend class TomlParser;
};

#endif //TOML_ARRAY
