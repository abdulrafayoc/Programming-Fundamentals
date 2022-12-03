#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream SubhanAllah;
	SubhanAllah.open("SubhanAllah.txt",ios::out);

	SubhanAllah << "Abdullah ibn Mas'ud reported: The Messenger of Allah, peace and blessings be upon him, said, \" Most of the sins of the children of Adam are on their tongues.\"\n";

	SubhanAllah << "Ibn Mas'ud said, \"O tongue! Speak goodness and be rewarded, or remain silent and be safe, lest you become regretful.\" \nSource: al-Mu'jam al-Kabir 10300;";

	SubhanAllah.close();
	
	return 0;
}
