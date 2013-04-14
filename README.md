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

I've seen other implementations of TOML with, like, 20 classes, and they confuse me severely.
Toml-C++ was designed to provide a simple interface but with extensive functionality,
and part of this was making less classes.
