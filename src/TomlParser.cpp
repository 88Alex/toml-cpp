#include "TomlParser.h"
#include <fstream>
static void TomlParser::setFile(string name)
{
    fstream newStream(name);
    stream = newStream;
}
static void TomlParser::load()
{
    bool formatStrMode = false, rawStrMode = false, escMode = false, endOfLine = false;
    string currLine = "";
    string currStr = "";
    TomlHash currHash = null;
    int lineNumber = 1;
    char currChar;
    for(; !stream.eof(); lineNumber++)//this is the line loop
    {
        lineloopstart:
        endOfLine = false;
        if(formatStrMode || rawStrMode)
        {
            throw new TomlError("Multiline strings not supported. If you insist, use \"\\n\" instead.", lineNumber);
        }
        rawStrMode = false;
        formatStrMode = false;;
        getline(stream, currLine);
        for(int i=1; i<currLine.length(); i++)//this goes over each individual character
        {
            currChar = currLine[i];
            if(endOfLine)
            {
                throw new TomlError("What are you trying to do with these random characters?",lineNumber);
            }
            else if(formatStrMode)
            {
                //parse string
            }
            else if(rawStrMode)
            {
                if(currChar=='\'')
                {
                    rawStrMode = false;
                }
                else
                {
                    currStr.append(1,currChar);
                }
            }
            else
            {
                switch(currChar)
                {
                    case '#':
                        goto lineloopstart;//I know right but it's a necessary evil
                    case '"':
                        formatStrMode = true;
                        break;
                    case '\'':
                        rawStrMode = true;
                        break;
                    case '[':
                        string hashName = "";
                        while(currChar != ']')
                        {
                            hashName.append(1,currChar);
                            i++;
                            currChar = currLine[i];
                        }
                        currHash = new TomlHash(hashName, currHash);
                        endOfLine = true;
                        break;
                    default:
                        //
                }
            }
        }
    }
}
