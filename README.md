Toml-C++
========

A simple C++ parser/module for Toml.

Well, how does it work?
========

Simple. Here is a sample:

<code>#include "TomlParser.h"

...

TomlParser.setFile("example.toml");


TomlParser.load();

TomlElement[] elements = TomlParser.getElements();

for(int i=0; i<(sizeof elements); i++)

{

  cout << elements[i].getName();

  if(elements[i].getType()=="ARRAY")

  {

    TomlArray array = dynamic_cast<TomlArray>(elements[i]);

    TomlKey[] arrayElements = array.getElements();
    
    //...
    
  }
  
  else if(elements[i].getType()=="HASH")
  
  {
    
    TomlHash hash = dynamic_cast<TomlHash>(elements[i]);
    
    TomlElement[]  hashElements = hash.getChildElements();
  
  }

}
</code>

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

Also, please note that array.getElements() returns an array of TomlKeys,
but hash.getChildElements returns an array of TomlElements.
