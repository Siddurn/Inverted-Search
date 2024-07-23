#include "inverted_search.h"

void update_database(Wlist *head[], Flist **f_head)
{
    char file_name[FNAME_SIZE];
    Flist *prev = NULL;
    // prompt the user
    printf("Enter the new file name for updating the database\n");
    scanf("%s", file_name);

    // validate the file name
    //........TODO......
    
    int  suffix=strlen((*f_head)->file_name)-4;
    if (strcmp((*f_head)->file_name+suffix, ".txt") == 0) // validating filename is .txt
    {
        while (*f_head)
        {
            if (!(strcmp((*f_head)->file_name, file_name)))
            {
                printf("File name is already exist\n");
                return;
            }
            prev = *f_head;
            *f_head = ((*f_head)->link);
        }
        Flist *new_fnode = malloc(sizeof(Flist));
        if (new_fnode == NULL)
        {
            return;
        }
        strcpy(new_fnode->file_name, file_name);
        new_fnode->link=NULL;
        prev->link=new_fnode;
        create_database(new_fnode,head);
        printf("Update file successfully\n");
    }
    else
    {
        printf("Please enter .txt file\n");
    }
}
