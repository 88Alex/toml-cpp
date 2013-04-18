#include "TomlArray.h"
vector<TomlElement> TomlArray::getElements() { return elements; }
string TomlArray::getType() { return "ARRAY"; }
TomlArray::TomlArray(string name_, TomlElement parent_, vector<TomlElement> elements_)
{
    name = name_;
    parent = parent_;
    elements = elements_;
}
