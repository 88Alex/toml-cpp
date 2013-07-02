#ifndef TOML_KEY
#define TOML_KEY

using namespace std;

class TomlKey : TomlElement
{
    private:
        string type;//All caps, short form i.e. STRING, NUMBER, BOOL, DATE.
        string value;
    public:
        string getType();
        string getValue();//You can parse it afterwards.
        TomlKey(string name_, string type_, string value_, TomlElement parent_);
        friend class TomlParser;
};

#endif //TOML_KEY
