#include "fileio.h"

unsigned char readSingleByte (char* path, long int location)
{

	FILE *fp = NULL;
	unsigned char ch[1];
	fp = fopen(path,"rb");
	
	/*如果无法读取*/ 
	if (fp==NULL)      
	{
	    printf("File open error!\n");
	    exit(1);
	}
	
	/*如果输入的位置（long int）第一个字符为字母或汉字则返回位置0的1字节*/ 
	
	fseek(fp, location, 0);  //找到文件中的目标位置 
	fread(ch, sizeof(ch), 1, fp); //读取一个字节
	
	fclose(fp);
	return ch[0];
}