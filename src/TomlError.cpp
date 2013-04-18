#include "TomlError.h"
TomlError::TomlError(string message_, int lineNumber_)
{
    message = message_;
    lineNumber = lineNumber_;
}
TomlError::description()
{
    return "Error in line " + lineNumber + ": " + message + "\n";
}
