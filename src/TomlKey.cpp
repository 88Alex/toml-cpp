#include "TomlKey.h"
string TomlKey::getType() { return type; }
string TomlKey::getValue() { return value; }
TomlKey::TomlKey(string name_, string type_, string value_, TomlElement parent_)
{
    name = name_; type = type_; value = value_; parent = parent_;
}
