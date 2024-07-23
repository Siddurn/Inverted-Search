#include "inverted_search.h"

void save_database( Wlist *head[])
{
    //prompt the user for file name

    char file_name[FNAME_SIZE];
    printf("Enter the file name\n");
    scanf("%s" , file_name);

    //open file
    FILE *fptr = fopen(file_name , "w");
    char *string="#[index]  :  [word]   :  [file_count]  :  [file_name]    :   [word_count]\n";
    fwrite(string,sizeof(char),strlen(string),fptr);
    int i;
    for(i=0; i<27 ; i++)
    {
	if(head[i] != NULL)
	{
	    write_databasefile(head[i] , fptr,i);
	}
    }
    printf("Database saved\n");
}

void write_databasefile(Wlist *head, FILE* databasefile,int index)
{
    //........TODO........
    // #[index]  :  [word]  :  [file_count]  :  [file_name]    :   [word_count]
   char string[50];   //string char variable with maximum enough to use in sprintf
   //traverse through main nodes
   while(head)
   {
    //write the index,word and file count into given file
    sprintf(string,"#[%-5d]  :[ %-10s]: [%-6d]     ",index,head->word,head->file_count);
    fwrite(string,sizeof(char),strlen(string),databasefile);
    //create a link table tep pointer
    Ltable *LT_temp=head->Tlink;
    //traverse through Link table
    while(LT_temp)
    {
        //add filenames and word count in perticular file
        sprintf(string,":[ %-15s]:   [%-2d] : ",LT_temp->file_name,LT_temp->word_count);
        fwrite(string,sizeof(char),strlen(string),databasefile);
        LT_temp=LT_temp->table_link;
    }
    fwrite("\n",sizeof(char),1,databasefile);

    head=head->link;
   }
    
}





