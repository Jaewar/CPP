#include "VowelOrConsonant.h"

char vowels[10] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

void VowelOrConsonant::vowelOrConsonant(char c)
{
	bool m_isVowel = false;

	if (isalpha(c))
	{
		for (int i = 0; i < sizeof(vowels); i++)
		{
			if (vowels[i] == c)
			{
				std::cout << c << " is a vowel." << std::endl;
				m_isVowel = true;
				return;
			}
		}
		if (m_isVowel == false)
		{
			std::cout << c << " is a consonant." << std::endl;
		}
	}
	else
	{
		std::cout << c << " is an invalid letter." << std::endl;
	}
}
