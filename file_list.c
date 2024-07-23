#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1 , empty;
    while(argv[i] != NULL)
    {
	empty = isFileEmpty(argv[i]);
	if(empty == FILE_NOTAVAILABLE)
	{
	    printf("File : %s is not available\n" , argv[i]);
	    printf("Hence we are not adding that file into file linked list\n");
	    i++;
	    continue;
	}
	else if(empty == FILE_EMPTY)
	{
	    printf("File : %s is not having contents in it.\n" , argv[i]);
	    printf("Hence we are not adding that file into file linked list\n");
	    i++;
	    continue;
	}
	else
	{
	    int ret_val = to_create_list_of_files(f_head , argv[i]);

	    if(ret_val == SUCCESS)
	    {
		printf("Successfull : Inserting the file name %s into the file linked list\n" , argv[i]);
	    }
	    else if(ret_val == REPEATATION)
	    {
		printf("This file name : %s is repeated. Do not add the files more than once\n" , argv[i]);
	    }
	    else
	    {
		printf("Failure\n");
	    }
		i++;
	}
    }
}

// used to check for files availability and to check for file contents
int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename , "r");
    if(fptr == NULL)
    {
	if(errno == ENOENT)
	{
	    return FILE_NOTAVAILABLE;
	}
    }

    fseek(fptr , 0, SEEK_END);
    if(ftell(fptr)== 0)
    {
	return FILE_EMPTY;
    }
}

//to create list of files
int to_create_list_of_files(Flist **f_head, char *name)
{
   // ..........TODO............
    //Check for duplicate files
    //create a file linked list (insert_last)
	
	//traverse through  file nodes
	if(*f_head==NULL)
	{
		//if first filename just add the file
		Flist *new=malloc(sizeof(Flist));
		if(new == NULL)
		{
			return FAILURE;
		}
		//copy filename to new node and update link with NULL
		strcpy(new->file_name,name);
		new->link=NULL;
		*f_head=new;
		return SUCCESS;

	}
	//not a first file then traverse and check filename matches 
	Flist *temp=*f_head;
	Flist *prev=NULL;
	while(temp)
	{
		if((strcmp(name,temp->file_name))==0)
		{
			//file already present in file list
			return REPEATATION;
		}
		prev=temp;
		temp=temp->link;
	}
	//temp reaches null shows file name not repeated
	Flist *new=malloc(sizeof(Flist));
	if(new == NULL)
	{
		return FAILURE;
	}
	strcpy(new->file_name,name);
	new->link=NULL;
	prev->link=new;
	return SUCCESS;
}















