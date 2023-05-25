#include<cstdio>
int main() {
	int i = 0, r = 0;
	char s[1000010] = { NULL, };
	scanf("%[^\n]", s);
	
	while (s[i] != '\0') {
		if (s[i] != ' ' && s[i + 1] == ' ' || s[i + 1] == '\0')r++;
		if (s[i + 1] == '\0' && s[i] == ' ')r--;
		i++;
	}

	printf("%d", r);
}