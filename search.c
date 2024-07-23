#include "inverted_search.h"

int search( Wlist *head, char *word)
{
    //check empty / not
    if(head == NULL)
    {
	printf("Search is not possible , list is empty\n");
	return 1;
    }

    //traverse the list 
    while(head)
    {
	//compare the search word with the available words
	if(!(strcmp(head->word , word)))
	{
	    printf("Word %s is present in %d file/s \n" , word , head->file_count);
	    Ltable *Thead = head->Tlink;
	    while(Thead)
	    {
		printf("In file : %s   %d time/s \n" , Thead->file_name , Thead->word_count);
		Thead = Thead->table_link;
	    }
	    printf("\n");
	    return SUCCESS;
	}
	head = head->link;
    }
    printf("Search word is not present in the list\n");
}






