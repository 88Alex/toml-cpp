#ifndef TOML_HASH
#define TOML_HASH
#include <string>

using namespace std;

class TomlHash : TomlElement
{
    private:
        vector<TomlElement> elements;
    public:
        vector<TomlElement> getHashElements();
        TomlHash(string name_, TomlElement parent_, vector<TomlElement> elements_);
        string getType();//always returns "HASH"
        friend class Tomlparser;
};

#endif //TOML_HASH
