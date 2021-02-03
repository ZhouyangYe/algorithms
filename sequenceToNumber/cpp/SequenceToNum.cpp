#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int getCharNum(char ch) {
	return int(ch) - 96;
}

int getDelta(int size, char first) {
	if (size == 1) {
		return 1;
	}

	int second = int(first) + 1;
	int length = int('z') - second - (size - 2);

	int delta = 0;
	for (int i = 0; i < length; i++) {
		delta += getDelta(size - 1, char(second + i));
	}
	return delta + 1;
}

int getMaxForSize(int size) {
	if (size == 1) {
		return getCharNum('z');
	}

	int length = 26 - size;
	int delta = 0;
	for (int i = 0; i < length; i++) {
		delta += getDelta(size, char(int('a') + i));
	}

	return getMaxForSize(size - 1) + 1 + delta;
}

int getNum(const char* str) {
	int size = strlen(str);

	if (size == 1) {
		return getCharNum(str[0]);
	}

	int baseNum = getMaxForSize(size - 1) + 1;

	int delta = 0;
	for (int i = 0; i < size; i++) {
		if (size > 1 && i > 0 && int(str[i]) < int(str[i - 1])) {
			return 0;
		}

		int startingChar = i == 0 ? int('a') : str[i - 1] + 1;
		int length = int(str[i]) - startingChar;
		for (int j = 0; j < length; j++) {
			delta += getDelta(size - i, char(startingChar + j));
		}
	}
	return baseNum + delta;
}

int main(void) {
	int num = getNum("aez");

	cout << num << endl;
}
