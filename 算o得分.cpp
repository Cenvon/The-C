void main() {
	char s[]="oxoxoxooxoxooo";
	/*scanf("%s", s);*/
	int score = 0;
	int o_counter = 0;
	//printf("%d", sizeof(s));输出的值是12，其结果包含串结束符 \0
	//printf("%d", strlen(s));//其结果只有字符串中 字符的个数 
	for(int a = 0;a<strlen(s);a++)
	{
		if (s[a] == 'x') 
			o_counter = 0;
		else {
			o_counter++;
			score += o_counter;
		}
	}
	printf("%d", score);
}