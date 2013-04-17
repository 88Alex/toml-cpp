class TomlError
{
    public:
        string message;
        int lineNumber;
        TomlError(string message_, int lineNumber_);
        string description();
}
