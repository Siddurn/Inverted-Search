#include "inverted_search.h"

char *fname;
void create_database(Flist *f_head, Wlist *head[])
{
    //traverse through the file list

    while(f_head)
    {
	read_datafile(f_head , head , f_head->file_name);
	f_head = f_head->link;
    }
	printf("Create database compleated\n");
}
//read contents of file 
Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{

    int flag = 1;
    fname = filename;
    //open file in read mode
    FILE *fptr = fopen(filename ,"r");
    
    //declare an array to store words
    char word[WORD_SIZE];

    while(fscanf(fptr , "%s" , word) != EOF)
    {
	//index

	int index = tolower(word[0]) % 97;

	//other than alphabets 
	if(!(index >= 0 && index <= 25))
	{
	    index = 26;
	}
	//check whether words are repeated or not
	if(head != NULL)
	{
	    Wlist *temp = head[index];

	   //compare the words at each node with new word
	    while(temp)
	    {
		if(!strcmp(temp->word , word))
		{
		    if(update_word_count(&temp , filename)== FAILURE)
			{
				printf("Failed to create link node or update word count\n");
			}

		    flag = 0;
		    break;
		}
		temp = temp->link;
	    }

	    if(flag == 1)
	    {
		//fun called only when words are not repeated 
		insert_at_last(&head[index] , word,filename);
	    }
	}
    }
}

int update_word_count(Wlist ** head, char * file_name)
{
    //...............TODO..............
    //check whether words are repeated in same file or not
    //if same file --> increment word_count
   //if different files -----> increment file_count , create new Ltable 
   Ltable *ST=(*head)->Tlink;
   Ltable *prev=NULL;
   
   while(ST)
   {
	if(!strcmp(ST->file_name,file_name))
	{
		//increament the word count
		ST->word_count+=1;
		return SUCCESS;
	}
	prev=ST;
	ST=ST->table_link;
   }
   //its different file
   // increament the file count
   (*head)->file_count+=1;
   Ltable *L_node=malloc(sizeof(Ltable));
   if(L_node == NULL)
   {
	return FAILURE;
   }
   //copy file name to new link node and update link
   strcpy(L_node->file_name,file_name);
   L_node->table_link=NULL;
   L_node->word_count=1;
   //update the prev link node to new link node
   prev->table_link=L_node;
   return SUCCESS;
} 











