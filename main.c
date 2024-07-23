#include "inverted_search.h"

int main(int argc, char *argv[])
{
    system("clear");

    Wlist *head[27] = {NULL};

    // validate CLA
    if (argc <= 1)
    {
        printf("Enter valid no of arg\n");
        printf("./.Slist.exe f1.txt f2.txt.....\n");
        return 0;
    }
    // create file linked list
    // declare head pointer

    Flist *f_head = NULL;

    // validate the files
    file_validation_n_file_list(&f_head, argv);

    if (f_head == NULL)
    {
        printf("No files are available in the file linked list\n");
        printf("Hence the process terminated\n");
        return 1;
    }

    /*............TODO................
       prompt the user for choice
    Select your choice among following options:
        1. Create DATABASE
        2. Display Database
        3. Update DATABASE
        4. Search
        5. Save Database
    Enter your choice
    */
    int choice;
    char exit='y';
    printf("Enter Your choice\n");
    printf("1. Create DATABASE\n2. Display Database\n3. Update DATABASE\n4. Search\n5. Save Database\n");
    do
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // create database
            create_database(f_head , head);
            break;

        case 2:
            // display database
            display_database(head);
            break;

        case 3:
            // update_database
            update_database(head , &f_head);
            break;

        case 4:
            // search
            char word[WORD_SIZE];
            printf("Enter the word\n");
            scanf("%s",word);
            search(head[tolower(word[0]) % 97] , word);
            break;

        case 5:
            // save database
            save_database(head);
            break;

        default:
            printf("Enter valid option\n");
            break;
        }

        printf("Enter Y/y to repeat or N/n to exit\n");
        scanf(" %c", &exit);

    } while (exit == 'Y' || exit == 'y');
}
