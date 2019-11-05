#include "EngineException.h"
#include <sstream>

EngineException::EngineException(int line, const char * file, const char* desc) noexcept
	:
	line(line),
	file(file),
	desc(desc)
{
	MessageBox(NULL, what(), GetType(), MB_OK | MB_ICONEXCLAMATION);
}

/*
	Get what the exception was.
*/
const char* EngineException::what() const noexcept
{
	std::ostringstream oss;
	oss << desc << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

/*
	Get the type of exception.
*/
const char* EngineException::GetType() const noexcept
{
	return "Engine Exception";
}

/*
	Get the line that the exception occured on.
*/
int EngineException::GetLine() const noexcept
{
	return line;
}

/*
	Get the file that the exception occured in.
*/
const std::string& EngineException::GetFile() const noexcept
{
	return file;
}

std::string EngineException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}