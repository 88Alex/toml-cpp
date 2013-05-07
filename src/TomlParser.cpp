#include "TomlParser.h"
static long TomlParser::parseInteger(string text)
{
    int index = 0;
    char currChar = text.at(index);
    bool isNegative = false;
    int currNumber;
    if(currChar == '+')
    {
        index++;
        currChar = text.at(index);
    }
    else if(currChar == '-')
    {
        isNegative = true;
        index++;
        currChar = text.at(index);
    }
    for(; index < text.length(); index++, currChar = text.at(index))
    {
        if(48 <= currChar && currChar <= 57)
        {
            currNumber *= 10;
            currNumber += (currChar - 48);
        }
        else
        {
            throw 1; // 1 = Error parsing integer
        }
    }
}
static bool TomlParser::parseBoolean(string text)
{
    if(text == "true") return true;
    else if(text == "false") return false;
    else throw 2; // 2 = error parsing boolean
}
static double TomlParser::parseDouble(string text)
{
    //
}
static void TomlParser::clipSpaces(string& text)
{
    bool isStrMode = true;//We don't want to clip spaces inside strings
    int index = 0;
    char currChar = text.at(index);
    for(; index < text.length(); index++, currChar = text.at(index))
    {
        if(isStrMode) break;
        else if(currChar = '\'' || currChar = '"') isStrMode = true;
        else if(currChar = ' ' || currChar = '\t')
        {
            front = text.substr(0, index);
            back = text.substr(index + 1);
            front.append(back);
            text = front;
        }
    }
}
static void TomlParser::setFile(string name)
{
    fstream newStream(name);
    stream = newStream;
}
static void TomlParser::load()
{
    bool formatStrMode = false, rawStrMode = false, escMode = false, endOfStrMode = false; endOfLine = false;
    string currLine = "";
    string currStr = "";
    TomlHash currHash = null;
    TomlElement currElement = null;
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
        formatStrMode = false;
        getline(stream, currLine);
        clipSpaces(currLine);
        for(int i=1; i<currLine.length(); i++)//this goes over each individual character
        {
            currChar = currLine[i];
            if(endOfLine)
            {
                throw new TomlError("What are you trying to do with these random characters?", lineNumber);
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
                    endOfLine = true;
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
                    default://it's a key
                        if(endOfStrMode)
                        {
                            currElement.type = "STRING";
                            currElement.value = currStr;
                            break;
                        }
                        string name = "";
                        while(currChar != '=')
                        {
                            name.append(currChar);
                            i++;
                            currChar = currLine.at(i);
                        }
                        i++;//we go past the =
                        currChar = currLine.at(i);
                        valueStr = line.substr(i + 1);
                        currElement = new TomlElement(name, "");
                        try
                        {
                            long value = parseInteger(valueStr);
                            currElement.value = valueStr;
                            currElement.type = "INTEGER";
                        }
                        catch(int i)
                        {
                            try//This is the only way
                            {
                                bool value = parseBoolean(valueStr);
                                currElement.value = valueStr;
                                currElement.type = "BOOL";
                                catch(int i)
                                {
                                    try
                                    {
                                        double value = parseDouble(line.substr(valueStr));
                                        currElement.value = valueStr;
                                        currElement.type = "DOUBLE";
                                        catch(int i)
                                        {
                                            //now it's not a built-in type
                                        }
                                    }
                                }
                            }
                        }//end try-catch
                }//end switch
            }//end else
        }//end inner for
    }//end outer for
}
