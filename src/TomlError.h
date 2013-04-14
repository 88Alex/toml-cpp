class TomlError
{
    public:
        string message;
        int lineNumber;
        TomlError(string message, int lineNumber_);
}
