Toml-C++
========

A simple C++ parser/module for TOML.

Toml-C++ is compliant with TOML v0.1.0.
Should the next version of TOML be released, Toml-C++ will be updated accordingly within 10 days.

Well, how does it work?
========

Simple. Here is a sample:

    #include "TomlParser.h"
    ...
    TomlParser.setFile("example.toml");
    TomlParser.load();
    TomlElement[] elements = TomlParser.getElements();
    for(int i=0; i<(sizeof elements); i++)
    {
        cout << elements[i].getName() << endl;
        if(elements[i].getType()=="ARRAY")
        {
            TomlArray array = dynamic_cast<TomlArray>(elements[i]);
            TomlElement[] arrayElements = array.getElements();
            //...
        }
        else if(elements[i].getType()=="HASH")
        {
            TomlHash hash = dynamic_cast<TomlHash>(elements[i]);
            TomlElement[]  hashElements = hash.getChildElements();
            //....
        }
    }

(Please forgive me for my sloppy indentation. The markdown format isn't really cooperative with this.)

Wow. Never thought it would be so simple.
========

Well, thanks.

Anyway, what are all the classes?
========

Part of what makes Toml-C++ so simple is that there are only 5 classes.

There is the TomlParser class, which has several static methods useful for you. You saw some of these in action.
There is the TomlElement class, an abstract class representing a TOML element.
There is the TomlKey class, which represents a TOML key.
There is the TomlArray class, which is self-explanatory.
And there is the TomlHash class, which is just as self-explanatory.

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

`setFile(string)`: sets the file to the file indicated in the string.
You don't even have to pass it a file object. Toml-C++ does that for you.

`load()`: now this is one fun method. It loads everything from the TOML file into the data structure.

`getElements()`: retrieves all the fundamental-level elements from the data structure.

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


TomlArray
---------

A class representing a TOML array.

Method summary:

`getElements()`: returns a vector containing all the elements of the array.

TomlHash
--------

A class representing a TOML hash.

Method summary:

`getHashElements()`: returns a vector containing all the elements inside the hash.

Note: Please remember that the TomlKey, TomlArray, and TomlHash classes are superclasses of the TomlElement class.

And that's it! Good luck with your programming!
