
// Byron Burdette
// COP2535.0M1



/*********************************************************************************************************************************************************
**********************************************************************************************************************************************************
                                 MEMBER FUNCTION DEFINITIONS FOR THE CLASS "CafeteriaSurvey"
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************/





#include "CafeteriaSurvey.h"                                                         //   include class specification file for class "CafeteriaSurvey"




/*********************************************************************************************************************************************************
                                       THIS MARKS THE BEGINNING OF THE CONSTRUCTOR

the purpose of this function is to open the input file, dynamically allocate all the memory we need and set the names of the individual menu items
**********************************************************************************************************************************************************/
CafeteriaSurvey::CafeteriaSurvey()                                                               //   begin function definition
{
   inFile = new ifstream;                                                                       //   allocate memory for an ifstream object and store it's address in "inFile"
   inFile->open("cafeteria.txt");                                                               //   open the input file

   size = new int{ 4 };                                                                         //   allocate memory for an int and store it's address in "size". This represents the number of individual menu items in teh survey

   index = new int;                                                                             //   allocate memory for an int and store it's address in "index". We'll use this to iterate through out "for" loops 

   nextLine = new string;                                                                       //   allocate memory for a string and store it's address in "nextLine". We'll use this string to temporarily store a line read from the input file using getline()

   grub = new string;                                                                           //   allocate memory for a string and store it's address in "grub". We'll use this to help keep track of which food we're tallying results for later on

/*   allocate memory for a string[] with the number of elements being equal to the integer stored in the memory location stored in pointer "size" and store it's address in "food".
   We'll use this array to store the names of the individual menu items in the survey   */
   food = new string[*size]{ "Cheese Pizza", "Hamburger", "Fish Sticks", "Mystery Meat" };

/*   allocate memory for an array of int* with the number of elements being equal to the integer stored in the memory location stored in the pointer "size".   Here, we're setting
   up the first dimension (the rows) in our 2d array which is going to hold the tallied results of the survey. There will be one row per menu item and two columns per row, 1 column 
   for "Likes" and one for "Dislikes"   */
   survey = new int*[*size];

/*   Here, we've already set up the first dimension of our 2d array (the rows). Now it's time to set up the second dimension (the columns). For this, I think we need to use a loop.
   We're doing EVERYTHING with pointers, so we'll use dereferences to our pointers "index" and "size" for the condition and index for the loop. */
   for (*index = 0; *index < *size; (*index)++)                                                 //   for each menu item in the survey...
      *(survey + *index) = new int[2]{ 0 };                                                     //   create a new int[] with two elements, both initialized to 0, and store it's address in the pointer representing the current row in "survey"
}                                                                                               //   end function definition
/*********************************************************************************************************************************************************
                                             THIS MARKS THE END OF THE CONSTRUCTOR
**********************************************************************************************************************************************************/




/*********************************************************************************************************************************************************
                                    THIS MARKS THE BEGINNING OF THE "description" FUNCTION

                           the purpose of this function is to display the purpose of the program for the user
**********************************************************************************************************************************************************/
void CafeteriaSurvey::description()                                                                  //   begin function definition
{
   cout << "A group of students were asked to complete a survey in order to help improve" << endl    //   output a string literal describing the program to the user
      << "their school's cafeteria lunches. The survey lists differernt menu items and" << endl      //   more description...
      << "asks whether the student liked or disliked that item. Below is a table with the" << endl   //   even more description...
      << "results of the survey." << endl << endl << endl;                                           //   last bit of the description followed by some newline spacing
}                                                                                                    //   end of the function definition
/*********************************************************************************************************************************************************
                                       THIS MARKS THE END OF THE "description" FUNCTION
**********************************************************************************************************************************************************/




/*********************************************************************************************************************************************************
                                 THIS MARKS THE BEGINNING OF THE "tallySurvey" FUNCTION

      the purpose of this function is to read the input file containing the survey results and to tally up the results for each menu item
**********************************************************************************************************************************************************/
void CafeteriaSurvey::tallySurvey()                                              //   begin function definition
{
   while (getline(*inFile, *nextLine, '\t'))                                     //   read the next line in the file, stopping when it finds a tab or newline. Store the string in the address pointed to by "nextLine". Do this until the EOF is reached
   {
      *grub = *nextLine;                                                         //   the first thing we read will be a menu item, so store it in the location stored in "grub"

      getline(*inFile, *nextLine);                                               //   get the next line and store it in the address stored in "nextLine". This will be the survey result (a 'Y' or 'N') corresponding to the menu item read in the previous statement "grub"

      for (*index = 0; *index < *size; (*index)++)                               //   for every menu item...
         if (*grub == *(food + *index))                                          //   if the value stored in the location stored in "grub" is equal to the value stored in the array "food" at the current index..
         {
            if (nextLine->find("Y") != string::npos)                             //   check if the last thing we read from the file was a "Y"
               *(*(survey + *index)) += 1;                                       //   if it was, tally the "Y" column for this menu item
            else                                                                 //   otherwise it must have been an 'N'
               *(*(survey + *index) + 1) += 1;                                   //   tally the 'N' column for this menu item

            break;                                                               //   we've added this survey result to the tally, so we can stop checking now. Save some time by going ahead and breaking this loop to continue reading the file
         }                                                                       //   end of the "for" loop
   }                                                                             //   end of the "while" loop
}                                                                                //   end of the function definition
/*********************************************************************************************************************************************************
                                             THIS MARKS THE END OF THE "tallySurvey" FUNCTION
**********************************************************************************************************************************************************/




/*********************************************************************************************************************************************************
                                            THIS MARKS THE BEGINNING OF THE "output" FUNCTION

                                 the purpose of this function is to display the tallied results in a table
**********************************************************************************************************************************************************/
void CafeteriaSurvey::output()                                                                          //   begin function definition
{
   cout << setw(9) << setfill(' ') << "Food";                                                           //   display column header
   cout << setw(11) << setfill(' ') << "Like";                                                          //   display column header
   cout << setw(9) << setfill(' ') << "Dislike" << endl << endl;                                        //   display column header followed by newline spacing

   for (*index = 0; *index < *size; (*index)++)                                                         //   for each menu item...
   {
      cout << setw(12) << setfill(' ') << *(food + *index);                                             //   display the name of the menue item
      cout << setw(7) << setfill(' ') << *(*(survey + *index));                                         //   display the number of likes
      cout << setw(7) << setfill(' ') << *(*(survey + *index) + 1) << endl;                             //   display the number of dislikes
   }                                                                                                    //   end of the "for" loop

   cout << endl << endl << endl;                                                                        //   newline formatting
}                                                                                                       //   end of the function definition
/*********************************************************************************************************************************************************
                                                     THIS MARKS THE END OF THE "output" FUNCTION
**********************************************************************************************************************************************************/




/*********************************************************************************************************************************************************
                                                THIS MARKS THE BEGINNING OF THE DESTRUCTOR

the purpose of this function is to close the input file, free up all the memory that was allocated in the constructor and set all the pointers to NULL to
prevent the program from using them later (I don't really think I needed to do that last part since we're already in the destructor and nothing else
happens beyond this point, but I'm not sure so I did it anyway)
**********************************************************************************************************************************************************/
CafeteriaSurvey::~CafeteriaSurvey()                                                                     //   begin function definition
{
   inFile->close();                                                                                     //   close the input file
   delete inFile;                                                                                       //   free up the memory stored at the address stored in "inFile"
   inFile = 0;                                                                                          //   set the pointer "inFile" to NULL

   for (*index = 0; *index < *size; (*index)++)                                                         //   for each menu item
   {
      delete[] * (survey + *index);                                                                     //   free up the memory stored at the address for the current menu item
      *(survey + *index) = 0;                                                                           //   set the pointer for the current menu item to NULL
   }                                                                                                    //   end of the "for" loop

   delete[] survey;                                                                                     //   free up the memory stored at the address stored in "survey"
   survey = 0;                                                                                          //   set the pointer "survey" to NULL

   delete size;                                                                                         //   free up the memory store at the address stored in "size"
   size = 0;                                                                                            //   set the pointer "size" to NULL

   delete index;                                                                                        //   free up the memory stored at the address stored in "index"
   index = 0;                                                                                           //   set the pointer "index" to NULL

   delete[] food;                                                                                       //   free up the memory store at the address stored in "food"
   food = 0;                                                                                            //   set the pointer "food" to NULL

   delete nextLine;                                                                                     //   free up the memory store at the address stored in "nextLine"
   nextLine = 0;                                                                                        //   set the pointer "nextLine" to NULL

   delete grub;                                                                                         //   free up the memory store at the address stored in "grub"
   grub = 0;                                                                                            //   set the pointer "grub" to NULL
}                                                                                                       //   end of the function definition
/*********************************************************************************************************************************************************
                                                             THIS MARKS THE END OF THE DESTRUCTOR
**********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************
**********************************************************************************************************************************************************
                                                  THIS MARKS THE END OF THE MEMBER FUNCTION DEFINITIONS
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************/