#pragma once
#include <exception>
#include <string>
#include <Windows.h>

class EngineException : public std::exception
{
public:
	EngineException(int line, const char* file, const char* desc = "No additional info provided.") noexcept;
	const char* what() const noexcept override;
	virtual const char* GetType() const noexcept;
	int GetLine() const noexcept;
	const std::string& GetFile() const noexcept;
	std::string GetOriginString() const noexcept;
	bool IsFatal();
private:
	int line;
	std::string file;
	const char* desc;
	bool fatal;
protected:
	mutable std::string whatBuffer;
};

#define EN_EXCEPTION(desc) EngineException( __LINE__, __FILE__, desc )