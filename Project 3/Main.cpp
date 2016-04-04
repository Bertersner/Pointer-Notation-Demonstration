
// Byron Burdette
// COP2535.0M1



/*********************************************************************************************************************************************************
**********************************************************************************************************************************************************
A group of students were asked to complete a survey in order to help improve their school's cafeteria lunches. The survey lists differernt menu items and
asks whether the student liked or disliked that item. The purpose of this program is to tally up the results of that survey and display the results in
a table.
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************/



#include "CafeteriaSurvey.h"                                    //   include the class specification file for the class "CafeteriaSurvey"




/**********************************************************************************************************************************************************
***********************************************************************************************************************************************************
                                    THIS MARKS THE BEGINNING OF THE MAIN FUNCTION
***********************************************************************************************************************************************************
***********************************************************************************************************************************************************/
int main()                                                                  //   begin function defintion
{
   CafeteriaSurvey* survey = new CafeteriaSurvey;                           //   declares a pointer "survey" to a CafeteriaSurve, allocated memory for an object of type CafeteriaSurvey and stores it's location in "survey"

   survey->description();                                                   //   displays the description of the program for the user

   survey->tallySurvey();                                                   //   tallys up the results of the survey

   survey->output();                                                        //   outputs the tallied results of the survey

   delete survey;                                                           //   free up the memory stored at the address stored in "survey"
   survey = 0;                                                              //   set the pointer "survey" to NULL


   system("pause");                                                         //   pause the program before terminating so the user can see the results of the survey
   return 0;                                                                //   terminate the program without errors
}                                                                           //   end of the function definition
/**********************************************************************************************************************************************************
***********************************************************************************************************************************************************
                                       THIS MARKS THE END OF THE MAIN FUNCTION
***********************************************************************************************************************************************************
***********************************************************************************************************************************************************/