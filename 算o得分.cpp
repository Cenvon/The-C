void main() {
	char s[]="oxoxoxooxoxooo";
	/*scanf("%s", s);*/
	int score = 0;
	int o_counter = 0;
	//printf("%d", sizeof(s));�����ֵ��12������������������ \0
	//printf("%d", strlen(s));//����ֻ���ַ����� �ַ��ĸ��� 
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