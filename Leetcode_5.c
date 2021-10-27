#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#define MAX_LEN 1001
/*
P{i��j}��ʾ�±�i��jΪ�����ַ�������P{i+1��j-1}��Ϊ�����ִ�
��ˣ�P{i,j}Ϊ�����ִ���������P{i+1,j-1}Ϊ���ģ�����P[i] == P[j]
��̬�滮�����ַ������ȴ���2ʱ
*/
int longestString(char *s, int left, int right)
{
	int tempLeft = left;
	int tempRight = right;
	while (tempLeft >= 0 && tempRight < strlen(s) && s[tempLeft] == s[tempRight]) {
		tempLeft--;
		tempRight++;
	}
	return tempRight - tempLeft - 1;
}

char * longestPalindrome(char * s)
{
	int sLen = strlen(s);
	if (s == NULL) {
		return NULL;
	}
	if (sLen == 1) {
		return s;
	}
		
	char *maxstr = (char *)malloc(sizeof(char)*sLen);
	memset(maxstr, '\0', sizeof(char)*sLen);
	if (sLen == 2) {
		if (s[0] == s[1]) {
			return s;
		} else {
			maxstr[0] = s[0];
			return maxstr;
		}
	}
	int len1 = 0;
	int len2 = 0;
	int maxLen = 0;
	int start = 0;
	int end = 0;
	for (int i = 0; i < sLen; i++) {
		len1 = longestString(s, i, i);
		len2 = longestString(s, i, i + 1);
		maxLen = len1 > len2 ? len1 : len2;
		if (maxLen > end - start) {
			start = i - (maxLen - 1) / 2;
			end = i + maxLen / 2;
		}

	}
	for (int i = 0; i < end; i++) {
		maxstr[i] = s[start + i];
	}
	return maxstr;
}
int main()
{
	char nums[] = "aab";
	char *result = (char *)malloc(sizeof(char)* MAX_LEN);
	memset(result, '\0', sizeof(char)* MAX_LEN);
	result = longestPalindrome(nums);
	printf("The result is :%s\n", result);
	system("pause");
	return 0;
}