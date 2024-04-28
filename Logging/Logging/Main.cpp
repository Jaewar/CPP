#include <iostream>

class Log {
public:
	enum Level {
		LevelError = 0,
		LevelWarning = 1,
		LevelInfo = 2
	};

private:
	// m_ means it is a class level member variable.
	Level m_LogLevel = LevelInfo;

public:
	void SetLevel(Level level) {
		m_LogLevel = level;
	}

	void Error(const char* message) {
		if (m_LogLevel >= LevelError)
			std::cout << "[ERROR]: " << message << std::endl;
	}

	void Warn(const char* message) {
		if (m_LogLevel >= LevelWarning)
			std::cout << "[WARNING]: " << message << std::endl;
	}

	void Info(const char* message) {
		if (m_LogLevel >= LevelInfo)
			std::cout << "[INFO]: " << message << std::endl;
	}
};

int main() {

	Log log;
	log.SetLevel(Log::LevelWarning);
	log.Error("Error");
	log.Warn("Warn");
	log.Info("Info");
	std::cin.get();
}