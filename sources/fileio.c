#include "fileio.h"

unsigned char readSingleByte (char* path, unsigned long location)
{
	FILE *fp = NULL;
	unsigned char ch[2];
	fp = fopen(path,"rb");
	
	/*如果无法读取*/ 
	if (fp==NULL)      
	{
	    printf("An IOException has occured when opening a file\n");
	    return 0;
	}
	
	fseek(fp, location, 0);  //找到文件中的目标位置 
	fread(ch, sizeof(ch), 1, fp); //读取一个字节
	
	fclose(fp);
	return ch[0];
}