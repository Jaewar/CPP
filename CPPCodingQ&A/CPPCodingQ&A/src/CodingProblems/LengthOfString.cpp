#include "LengthOfString.h"

void LengthOfString::PrintStringLength(std::string message, bool ignoreSpace)
{
	int m_Length = 0;

	for (int i = 0; i < message[i] != '\0'; i++)
	{
		if (ignoreSpace && isspace(message[i])) continue;
		m_Length++;
	}

	std::cout << message << " is " << m_Length << " characters long." << std::endl;
}
