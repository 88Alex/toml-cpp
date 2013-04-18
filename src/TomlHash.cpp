#include "TomlHash.h"
vector<TomlElement> TomlHash::getHashElements() { return elements; }
string TomlHash::getType() { return "HASH"; }
TomlHash::TomlHash(string name_, TomlElement parent_, vector<TomlElement> elements_)
{
    name = name_;
    parent = parent_;
    elements = elements_;
}
