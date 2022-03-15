/**********************************************************************************
 Author:         Joel Sadanand Samson
 G_NUM:          01352483
 Date:           Feb 11, 2022
 Last Updated:   Feb 11, 2022
 Purpose:        This program is written for HW 1 problem 
                 Takes input of strings and sort in Ascending or Descending order
 Program:        contstants.c
 
**********************************************************************************/

#include <stdio.h>    //Standard Input/Output Library
#include <stdlib.h>   //Standard Library Functions
#include <string.h>   //Library with String fucntions
/****************************************************************
									  
  Function   : Display
  Description: This function is used to print the Array of Strings

****************************************************************/
void
display (char array[10][100])
{
  printf ("The sorted array is \n");
  for (int i = 0; i < 10; i++)
    {
      printf ("%s", array[i]);
      printf ("\n");
    }
}
/*******************************************************************************
									  
  Function   : Condtions
  Description: This function is used to check some condtions on the input string
               returns a fla value used for comparision later

*******************************************************************************/
int
condtions (char str[100], int count)
{
  int flag = 0;
  // If condtion to check if string inputed has length of no more than 25
  if (!((strlen (str) >= 1 && (strlen (str)) < 26))) 
    {
      printf ("Error: String entered has lenght more than 25 – please re-enter\n");
      printf("Enter string %d: \n", count);
      flag++;
    }
  // If condtion to check if string contains ( in it
    if(strstr(str,"("))
    {
        printf ("Error: ( is an illegal character – please re-enter\n");
      printf ("Enter string %d: \n", count);
      flag++;
    }
  // If condtion to check if string contains ) in it
    if(strstr(str,")"))
    {
        printf ("Error: ) is an illegal character – please re-enter\n");
      printf ("Enter string %d: \n", count);
      flag++;
    }
  // If condtion to check if string contains $ in it
    if(strstr(str,"$"))
    {
        printf ("Error: $ is an illegal character – please re-enter\n");
      printf ("Enter string %d: \n", count);
      flag++;
    }
  // If condtion to check if string contains ! in it
    if(strstr(str,"!"))
    {
        printf ("Error: ! is an illegal character – please re-enter\n");
      printf ("Enter string %d: \n", count);
      flag++;
    }
  // If condtion to check if string contains @ in it
    if(strstr(str,"@"))
    {
        printf ("Error: @ is an illegal character – please re-enter\n");
      printf ("Enter string %d: \n", count);
      flag++;
    }
  // If condtion to check if string contains # in it
    if(strstr(str,"#"))
    {
        printf ("Error: # is an illegal character – please re-enter\n");
      printf ("Enter string %d: \n", count);
      flag++;
    }
  // If condtion to check if string contains ^ in it
    if(strstr(str,"^"))
    {
        printf ("Error: ^ is an illegal character – please re-enter\n");
      printf ("Enter string %d: \n", count);
      flag++;
    }
    // If condtion to check if string contains % in it
    if(strstr(str,"%"))
    {
        printf ("Error: %% is an illegal character – please re-enter\n");
      printf ("Enter string %d: \n", count);
      flag++;
    }
  // If condtion to check if string is a empty string
  if (strcmp (str, "\n") == 0)
    {
      printf ("Error: Empty String inputed – please re-enter\n");
      printf ("Enter string %d: \n", count);
      flag++;
    }
  return flag;
}
/*******************************************************************************
									  
  Function   : Assceding
  Description: This function is used to sort the array in asscending order
               Uses Bubble sort technique

*******************************************************************************/
void
asscending (char str[10][100], char temp[100], int SIZE)
{
  for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE - 1 - i; j++)
	{
	  if (strcmp (str[j], str[j + 1]) > 0)
	    {
	      //swap array[j] and array[j+1]
	      strcpy (temp, str[j]);          //temp is a temporary array
	      strcpy (str[j], str[j + 1]);
	      strcpy (str[j + 1], temp);

	    }
	}
    }
  printf ("Ascending order:\n");
  display (str);                //calls function display to display the string
  printf ("String with Lowest ASCII value: %s\n", str[0]);    
  printf ("String with Highest ASCII value: %s\n", str[9]);
}
/*******************************************************************************
									  
  Function   : Descending
  Description: This function is used to sort the array in descending order
               Uses Bubble sort technique

*******************************************************************************/
void
descending (char str[10][100], char temp[100], int SIZE)
{
  for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE - 1 - i; j++)
	{
	  if (strcmp (str[j], str[j + 1]) < 0)
	    {
	      //swap array[j] and array[j+1]
	      strcpy (temp, str[j]);         //temp is a temporary array
	      strcpy (str[j], str[j + 1]);
	      strcpy (str[j + 1], temp);

	    }
	}
    }
  printf ("Descending Order:\n");
  display (str);                //calls function display to display the string
  printf ("String with Lowest ASCII value: %s\n", str[9]);
  printf ("String with Hoghest ASCII value: %s\n", str[0]);
}

/*********************************************************************
    Main Function  
 
*********************************************************************/
int
main ()
{
  char str[10][100];  // Declaring a Array of Strings
  int SIZE = 10;      // Used to signify No of strings in array
  char temp[100];     // Temporary Variable
  int count = 0;      // Counter to keep track of which string
  
  
  printf ("Enter 10 character strings:\n");

  for (int i = 0; i < 10; i++)
    {
      count++;

      printf ("Enter string %d: \n", count);
    c:
      fgets (str[i], 100, stdin);  // Users input using fgets

      int flag = condtions (str[i], count);   // flag used for condition checking
      if (flag != 0)
	{
	  goto c;
	}
 //This part checks if the string has a duplicate value in the array
      for (int j = 0; j < i; j++)
	{
	  if (strcmp (str[i], str[j]) == 0)
	    {
	      printf ("Error: duplicate string – please re-enter\n");
	      printf ("Enter string %d: \n", count);
	      goto c;
	    }
	}
    }
    
  char c;

  printf ("Print character strings in Ascending or Descending order : ");
d:
  scanf (" %c", &c);  // User input for which way to sort

// Switch case to perform various instructions if matched

  switch (c)
    {
    case 'A':
    // if A for Asscending
      asscending (str, temp, SIZE);
      break;
    case 'D':
    // if B for Asscending
      descending (str, temp, SIZE);
      break;
    default:
    // if the character inputed is not A or D
      printf ("Invalid\n");
      printf ("Enter the way to sort again\n");
      goto d;
      break;

    }
    return 0;
}
/*************************************************************
    Main Function ends here
*************************************************************/
  
  
