//file operationsAssignment 10: Implement command line argument programs for following file operations. i. Copy ii. Type iii. Rename iv. Merge
#include <stdio.h>
#include<string.h>
void copier(char *oldFile, char *openType, char *newFile) {
    FILE *f1, *f2;
    f1 = fopen(oldFile, "r+");
    f2 = fopen(newFile, openType);
    char c = fgetc(f1);
    while (c != EOF) {
        fputc(c, f2);
        c = fgetc(f1);
    }
    
    fclose(f1);
    fclose(f2);
}

void fileOpener(char *fileName, char *fileData) {
    FILE *f = fopen(fileName, "w");
    fputs(fileData, f);
    
    fclose(f);
}

void fileFusion(char *oldFile, char *newFile) {
	printf("The data of second file is now merged with first file \n");
    printf("The contents of the new file is : ");
    copier(newFile, "a", oldFile);
    print(oldFile);
    
    }
    void print(char filename)
    {
    FILE *fp=fopen(filename,"r");
    char read[100];
    fgets(read,100,f2);
    printf("%s",read);
    fclose(fp);
	}
    

main(int argc, char const *argv[]) 
{

    int ch,i=0,check=0;
    char file1[20], file2[20];
    char file[5][20],fd[50];
    bool quit= false;
    printf("Enter name of file: ");
    scanf("%s", file1);
    strcpy(file[0],file1);
    while(!quit)
    {
    	printf("\nFile operations.Enter\n1.Writing file\n2.Copying file\n3.Merge files\n4.Rename file\n5.Quit \nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
        int c;
        char type,fileData[100];
        printf("Enter info:\n"); 
        fgetc(stdin);
		fgets(fileData, sizeof(fileData), stdin);
        fileOpener(file1, fileData);
        printf("The data is now written into the file. \n");
        break;
    case 2:
        printf("Enter the name of 2nd file: ");
        scanf("%s", file2);        
        copier(file1, "w", file2);
		printf("The data is now copied into the second file \n");      
        break;
    case 3:
        printf("Name of 2nd file: ");
        scanf("%s", file2);
        for(int j=0;j<=i;j++)
        {
        	if(strcmp(file2,file[j])==0)
        	{
        		check=1;
        		break;
			}
		}
		if(check==1)
        fileFusion(file1, file2);
        else
        {
        	int t;
        	printf("The file does not have any content. Do you want to write info into the second file? IF yes, Enter 1, else enter 0. ");
        	scanf("%d",&t);
        	if(t==1)
        	{
        		printf("Enter info:\n");
        		fgetc(stdin);
                fgets(fd,sizeof(fd),stdin);
                fileOpener(file2, fd);
			}
			
			fileFusion(file1, file2);
		}		
        break;
    case 4:
        printf("New file name: ");
        scanf("%s", file2);
        rename(file1, file2);
        printf("The file is renamed \n");
        break;
    case 5:
        quit=true;
		break;	
    default:
    	printf("Wrong choice ");
    	
	}
}
}
    
       
