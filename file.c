#include <stdio.h>
int main()
{
    int t=0;
    while(t==0)
    {
        FILE * fp;
        int i,ct,j,a;
        printf("\n\n\n\t\t\t\t\t\tPHONEBOOK ENTRY SYSTEM\n");
        printf("\t\t\t\t\t\t\tSelect :\n\t\t\t\t\t1.Enter data\n\t\t\t\t\t2.Search contact\n\t\t\t\t\t3.display all\n\t\t\t\t\t4.cancel\n");
        scanf("%d",&a);                                 //taking input for choice

        char n[50],dt[50];
        if(a==1)
        {
            fp=fopen("phonebook.txt","a");              //opening file in append mode to insert a contact
            printf("Enter name: ");
            getchar();
            gets(n);                                    //input name
            printf("Enter mobile: ");
            gets(dt);                                   //input number
            fprintf(fp,"%s\t%s\n",n,dt);                // inputing variable n and d in file
            fclose(fp);                                 //closing file
            fp=fopen("phonebook.txt","r");              //reopening the file in read mode to take input from the file and sort them
            char c;
            ct=0;                                       //count variable for number of lines in the file
            for(c=fgetc(fp); c!=EOF; c=fgetc(fp))       //for loop to count new line in order to find out number of lines
            {
                if(c=='\n')
                    ct++;

            }
            fclose(fp);                                 //closing file
            //printf("%d\n",ct);
            char s[ct][50];                           //this array is for taking input each line in file as a single string input
            char temp[50];

            fp=fopen("phonebook.txt","r");              //reopening file in read mode to sort the lines of file
            i=0;
            while(!feof(fp))                            //to copy all the lines from file to array s
            {
                fgets(s[i],50,fp);
                i++;

            }



            for(i=0; i<ct; ++i)                         // sorting strings
            {
                for(j=i; j<ct; ++j)
                {

                    if(strcmp(s[i],s[j])>0)
                    {
                        strcpy(temp,s[i]);
                        strcpy(s[i],s[j]);
                        strcpy(s[j],temp);
                    }

                }
            }

            fclose(fp);                                 //closing the file
            fp=fopen("phonebook.txt","w");              //opening the file in write mode to insert the sorted array s
            char new[50];                               //for copying the each index of array s and then insert in file
            i=0;
            while(i!=ct)                              //loop runs for the number of lines in file
            {

                strcpy(new,s[i]);                       //copying element of s to new

                fprintf(fp,"%s",new);                   //inserting new to file
                ++i;

            }
            fclose(fp);                                 //file close
        }

        else if(a==2)                                   //to search a contact
        {
            char t[50];                                 //to take input name
            printf("Enter name: ");
            scanf("%s",t);
            fp=fopen("phonebook.txt","r");             //opening file in read mode to search a contact
            i=0;
            while(!feof(fp))
            {

                fscanf(fp, "%s\t%s", n,dt);             //copying name input to n and number input to dt from file
                if (strcmp(n, t) == 0 )                 //comparing n and t , if output is 0 then they matched
                {
                    printf("Record found : %s %s\n",  n, dt);//printing the name and number
                    i++;
                    break;                                   //breaking the loop

                }

            }

            if(i==0)
            {
                printf("Record not found\n");

            }


            fclose(fp);                                 //closing file
        }
        else if(a==3)
        {
            fp=fopen("phonebook.txt","r");              //opening file in read mode to display all the contacts
            char p[50],c;                                 //to copy each line from the file
            c = fgetc(fp);
            while (c != EOF)
            {
                printf ("%c", c);
                c = fgetc(fp);
            }
            fclose(fp);                                 //closing the file
        }
        else
        {
            t=1;

        }

    }


}
