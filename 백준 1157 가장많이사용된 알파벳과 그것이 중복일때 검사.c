#include <stdio.h>
#include <string.h>

int main() {
	int count = 0, max = 0;
	char str[1000000], max_alpa;
	scanf("%s",str);
	for (int i = 'a'; i <= 'z'; i++) {
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] == i || str[j] == i - 32)
				count++;
		}

		if (max < count) {
			max = count;
			max_alpa = i;
			if (max_alpa >= 97)
				max_alpa -= 32;
		}
		else if (max == count)
			max_alpa = '?';

		count = 0;
	}
	printf("%c", max_alpa);
}