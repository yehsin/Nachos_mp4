#include "syscall.h"
//typedef int OpenFileId;
int main(void)
{
	char test[] = "abcdefghijklmnopqrstuvwxyz";
	//printf('%s',test);
	int success= Create("file1.test");
	OpenFileId fid;
	int i;
	//MSG("Success on creating file1.test");
	if (success != 1) MSG("Failed on creating file");
	//MSG("Success on creating file0.test");
	fid = Open("file1.test");
	
	if (fid < 0) MSG("Failed on opening file");
	
	for (i = 0; i < 26; ++i) {
		int count = Write(test + i, 1, fid);
		if (count != 1) MSG("Failed on writing file");
	}
       
	success = Close(fid);
	if (success != 1) MSG("Failed on closing file");
	MSG("Success on creating file1.test");
	Halt();
}

