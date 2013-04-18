#ifndef TOML_ELEMENT
#define TOML_ELEMENT
#include <string>
using namespace std;

class TomlElement
{
    private:
        string name;
        TomlElement* parent;//null if its parent is the root
    public:
        virtual TomlElement getParent();
        virtual string getName();
        virtual string getFullName();
        virtual string getType();
        //constructor deliberately left out.
        friend class TomlParser;
};

#endif
