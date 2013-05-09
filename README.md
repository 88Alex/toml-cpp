Toml-C++
========

A simple C++ parser/module for TOML.

For more information on TOML, see http://www.github.com/mojombo/toml.

Toml-C++ is compliant with TOML v0.1.0.
Should the next version of TOML be released, Toml-C++ will be updated accordingly within 10 days.

Well, how does it work?
========

Simple. Here is a sample:

```cpp
#include "TomlParser.h"
...
TomlParser.setFile("example.toml");
TomlParser.load();
vector<TomlElement> elements = TomlParser.getElements();
for(int i=0; i<elements.size(); i++)
{
    cout << elements[i].getName() << endl;
    if(elements[i].getType()=="ARRAY")
    {
        TomlArray array = dynamic_cast<TomlArray>(elements[i]);
        vector<TomlElement> arrayElements = array.getElements();
        //...
    }
    else if(elements[i].getType()=="HASH")
    {
        TomlHash hash = dynamic_cast<TomlHash>(elements[i]);
        vector<TomlElement>  hashElements = hash.getHashElements();
        //....
    }
}
```

Wow. Never thought it would be so simple.
========

Well, thanks.

Anyway, what are all the classes?
========

Part of what makes Toml-C++ so simple is that there are only 6 classes.

There is the TomlParser class, which has several static methods useful for you. You saw some of these in action.
There is the TomlElement class, an abstract class representing a TOML element.
There is the TomlKey class, which represents a TOML key.
There is the TomlArray class, which represents a TOML array.
There is the TomlHash class, which represents a TOML hash.
And there is the TomlError class, which represents a TOML error.

By the way, the TomlKey, TomlArray, and TomlHash classes are super-classes of the TomlElement class.

Also, some of these classes have constructors, but don't bother with them. Toml-C++ manages that for you.

I've seen other implementations of TOML with, like, 20 classes, and they confuse me severely.
Toml-C++ was designed to provide a simple interface but with extensive functionality,
and part of this was making less classes.

Now for some formal documentation:

TomlParser
----------

A class with some static methods for TOML file parsing

Method summary:

`parseInteger(string)`: parses an integer.
Returns a long (64-bit) integer.

`parseBoolean(string)`: parses a boolean.
Returns a bool value.

`parseDouble(string)`: parses a double.
Returns a double (64-bit floating-point).

`clipSpaces(string&)`: clips all the spaces from a string.
No return value.
NOTE: This method is public, but only used internally.

`setFile(string)`: sets the file to the file indicated in the string.
You don't even have to pass it a file object. Toml-C++ does that for you.
No return value.

`load()`: now this is one fun method. It loads everything from the TOML file into the data structure.
No return value.
Throws: TomlError.

`getElements()`: retrieves all the fundamental-level elements from the data structure.
Returns an object of type `vector<TomlElement>`.

TomlElement
-----------

An abstract class (please don't try to instantiate it, lest the universe explode) representing a TOML element.

Method summary:

`getName()`: returns the name of the element.

`getFullName()`: returns the full name.

`getParent()`: returns the element's parent element, null if its parent is the root.

`getType()`: returns the element type.
Possible types are: STRING, INT, FLOAT, BOOL, DATETIME, ARRAY, HASH.

TomlKey
-------

A class representing a TOML key/value pair.

Method summary:

`getValue()`: returns the value.

(Note: extends TomlElement)

TomlArray
---------

A class representing a TOML array.

Method summary:

`getElements()`: returns a vector containing all the elements of the array.

(Note: extends TomlElement)

TomlHash
--------

A class representing a TOML hash.

Method summary:

`getHashElements()`: returns a vector containing all the elements inside the hash.

(Note: extends TomlElement)

And that's it! Good luck with your programming!

Known Flaws
========

[ ] Cannot parse arrays- YET! This will be fixed soon.
