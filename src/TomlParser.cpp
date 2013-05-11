#include "TomlParser.h"
long TomlParser::parseInteger(string text)
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
    return isNegative ? -currNumber : currNumber;
}
bool TomlParser::parseBoolean(string text)
{
    if(text == "true") return true;
    else if(text == "false") return false;
    else throw 2; // 2 = error parsing boolean
}
double TomlParser::parseDouble(string text)
{
    bool isDecimal = false, isNegative = false;
    int index = 0, level = 1, currNumber = 0;
    char currChar = text.at(index);
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
            if(!isDecimal)
            {
                currNumber *= 10;
                currNumber += (currChar - 48);
            }
            else
            {
                double factor = 1;
                for(int i = 1; i <= level; i++, factor /= 10) ;
                currNumber += factor * (currChar - 48);
            }
        }
        else if(currChar == '.')
        {
            isDecimal = true;
        }
        else
        {
            throw 3; // 3 = Error parsing double
        }
    }
}
void TomlParser::clipSpaces(string& text)
{
    bool isStrMode = false;//We don't want to clip spaces inside strings
    int index = 0;
    char currChar = text.at(index);
    for(; index < text.length(); index++, currChar = text.at(index))
    {
        if(isStrMode)
        {
            if(currChar == '\\') index++;
            else if(currChar == '"') isStrMode = false;
        }
        else if(currChar == '\'' || currChar == '"') isStrMode = true;
        else if(currChar == ' ' || currChar == '\t')
        {
            string front = text.substr(0, index);
            string back = text.substr(index + 1);
            front.append(back);
            text = front;
        }
    }
}
void TomlParser::setFile(string name)
{
    fstream newStream(name);
    stream = newStream;
}
void TomlParser::load()
{
    bool formatStrMode = false, rawStrMode = false, escMode = false
    bool endOfStrMode = false, endOfLine = false;
    string currLine = "";
    string currStr = "";
    TomlHash currHash = null;
    TomlKey currKey = null;
    int lineNumber = 1;
    char currChar;
    for(; !stream.eof(); lineNumber++)//this is the line loop
    {
        lineloopstart:
        endOfLine = false;
        if(formatStrMode || rawStrMode)
        {
            throw new TomlError(
                "Multiline strings not supported. Use \"\\n\" instead.",
                lineNumber);
        }
        rawStrMode = false;
        formatStrMode = false;
        getline(stream, currLine);
        clipSpaces(currLine);
        for(int i=1; i<currLine.length(); i++)//this goes over each character
        {
            currChar = currLine[i];
            if(endOfLine)
            {
                throw new TomlError(
                    "What are you trying to do with these random characters?",
                    lineNumber);
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
            else if(endOfStrMode)
            {
                goto eos;
            }
            else
            {
                switch(currChar)
                {
                    case '#':
                        goto lineloopstart;
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
                    eos:
                        if(endOfStrMode)
                        {
                            currKey.type = "STRING";
                            currKey.value = currStr;
                            break;
                        }
                        string name = "";
                        while(currChar != '=')
                        {
                            name.append(&currChar);
                            i++;
                            currChar = currLine.at(i);
                        }
                        i++;//we go past the =
                        currChar = currLine.at(i);
                        string valueStr = currLine.substr(i + 1);
                        try
                        {
                            long value = parseInteger(valueStr);
                            currKey = new TomlKey(name, valueStr, "INTEGER",
                                currHash);
                        }
                        catch(int i)
                        {
                            try//This is the only way
                            {
                                bool value = parseBoolean(valueStr);
                                currKey = new TomlKey(name, valueStr, "BOOL",
                                    currHash);
                                catch(int i)
                                {
                                    try
                                    {
                                        double value = parseDouble(
                                            line.substr(valueStr));
                                        currKey.value = valueStr;
                                        currKey = new TomlKey(name, valueStr,
                                            "FLOAT", currHash);
                                        catch(int i)
                                        {
                                            //ignore it
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
vector<TomlElement> TomlParser::getElements()
{
    return elements;
}
