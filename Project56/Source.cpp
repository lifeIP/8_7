#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

void process(const char* file_in, const char* file_out);
void counter(const char* strin, char* strout);

int main()
{
	setlocale(LC_ALL, "RUS");
	process("file.txt", "result.txt");
}

void process(const char* file_in, const char* file_out)
{
	FILE* f = fopen(file_in, "rt");
	if (f == NULL)
	{
		cout << "Не удалось открыть файл " << file_in << endl;
		return;
	}
	ofstream fo;
	fo.open(file_out);
	if (!fo.is_open())
	{
		cout << "Не удалось открыть файл " << file_out << endl;
		fclose(f);
		return;
	}
	while (!feof(f))
	{
		char buff[250];
		buff[0] = 0;
		fgets(buff, 250, f);
		if (strlen(buff) > 0)
		{
			char buff2[250];
			counter(buff, buff2);
			cout << buff2;
			fo << buff2;
		}
	}
	fclose(f);
	fo.close();
}

void counter(const char* strin, char* strout) {
	memset(strout, 0, sizeof(char) * 250);
	for (int i = 0; i < strlen(strin); i++) {
		char val = strin[i];
		char res[10] = {};
		switch (val)
		{
		case 'A':
			strcpy(res, ".-");
			break;
		case 'B':
			strcpy(res, "-...");
			break;
		case 'C':
			strcpy(res, "-.-.");
			break;
		case 'D':
			strcpy(res, "-..");
			break;
		case 'E':
			strcpy(res, ".");
			break;
		case 'F':
			strcpy(res, "..-.");
			break;
		case 'G':
			strcpy(res, "--.");
			break;
		case 'H':
			strcpy(res, "....");
			break;
		case 'I':
			strcpy(res, "..");
			break;
		case 'J':
			strcpy(res, ".---");
			break;
		case 'K':
			strcpy(res, "-.-");
			break;
		case 'L':
			strcpy(res, ".-..");
			break;
		case 'M':
			strcpy(res, "--");
			break;
		case 'N':
			strcpy(res, "-.");
			break;
		case 'O':
			strcpy(res, "---");
			break;
		case 'P':
			strcpy(res, ".--.");
			break;
		case 'Q':
			strcpy(res, "--.-");
			break;
		case 'R':
			strcpy(res, ".-.");
			break;
		case 'S':
			strcpy(res, "...");
			break;
		case 'T':
			strcpy(res, "-");
			break;
		case 'U':
			strcpy(res, "..-");
			break;
		case 'V':
			strcpy(res, "...-");
			break;
		case 'W':
			strcpy(res, ".--");
			break;
		case 'X':
			strcpy(res, "-..-");
			break;
		case 'Y':
			strcpy(res, "-.--");
			break;
		case 'Z':
			strcpy(res, "--..");
			break;
		case '\n':
			res[strlen(res)] = '\n';
			break;
		default:
			res[strlen(res)] = '0';
			break;
		}
		strcat(strout, res);
	}
}