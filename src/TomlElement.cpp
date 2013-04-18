#include "TomlElement.h"
TomlElement TomlElement::getParent() { return parent; }
string TomlElement::getName() { return name; }
string TomlElement::getFullName() { return parent.getName() + "." + name; }
string TomlElement::getType() { return "ELEMENT"; }
