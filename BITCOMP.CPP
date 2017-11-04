//This code is successfully compilable in C-Free 5.0 with mingw5 compiler
//which can compile it for 64 bit windows 7

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>

int main()
{
 FILE *fp1, *fp2, *fp3;
 unsigned long i,j,s;
 char *a,*b,*white,*red,*green,*blue;
 char a_b,b_b,c_b,white_b,black_b,green_b,red_b,blue_b,
      a_g,b_g,c_g,white_g,black_g,green_g,red_g,blue_g,
      a_r,b_r,c_r,white_r,black_r,green_r,red_r,blue_r,background;
 //clrscr();

 printf("BITCOMP                                                           by  Amit Bhola");
 printf("--------------------------------------------------------------------------------");
 printf("Compares two 24-bitmap files and saves the output in a third 24-bitmap file.\n");
 printf("A sacrosanct shade is declared in file 'white.bmp' .\n");
 printf("Comparison result is made pixel by pixel between File1 and File2 as below:-\n");
 printf("  - If both pixels match each other, then same original pixel is outputted\n");
 printf("  - If both pixels do not match each other,then pixels are compared with\n");
 printf("    sacrosanct shade.\n");
 printf("  - Then wrt sacrosanct shade,if File1 pixel is different but File2 pixel is not");
 printf("    then shade declared in file 'red.bmp' is outputted.\n");
 printf("  - If wrt sacrosanct shade,File1 pixel is same but File2 pixel is different\n");
 printf("    then shade declared in file 'blue.bmp' is outputted.\n");
 printf("  - If wrt sacrosanct shade,both File1 and File2 pixels are different\n");
 printf("    then shade declared in file 'green.bmp' is outputted.\n");
 printf("--------------------------------------------------------------------------------");
 printf("REQUISITES:\n\n");
 printf("Existance of files white.bmp, red.bmp, blue.bmp, and green.bmp\n");
 printf("Existance of files File1.bmp and File2.bmp of same pixel width*pixel height\n");
 printf("All files to be of 24-Bit bitmap format\n");
 printf("File1.bmp and File2.bmp to be of pixel width which is divisible by 4.\n");
 printf("Max size of any file : 4,294,967,295 bytes\n\n");
 printf("If above conditions are met, then press any key to run, else close this window.\n");
 getch();
 background='n';
 printf("\n\nDo you want that if pixels are same in File1 and File2, the output is not the\n");
 printf("original pixel but the sacrosanct shade?\nEnter y for yes, any other key for no : ");
 scanf("%c",&background);
 printf("\n\nBITCOMP is now comparing the files...\n");
 if (background=='y' || background=='Y')
  background='y';
 
//Reading of RGB of 'sacrosanct' shade------------------------------------------

 fp1=fopen("white.bmp","rb");
 if (fp1==NULL)
  { printf("\nFile white.bmp not found!"); getch(); exit(0); }
  fseek (fp1 , 0 , SEEK_END);
  s = ftell (fp1);
  fseek(fp1,0,SEEK_SET);
 white = (char*) malloc (sizeof(char)*s);
 fread(white,1,s,fp1);
 white_b  =*(white  +54);  white_g  =*(white  +55);  white_r  =*(white  +56);
 //printf("%c,%c,%c,",white_b,white_g,white_r);
 fclose(fp1);
 
 //Reading of RGB of 'File1 exclusive' shade------------------------------------
 
 fp1=fopen("red.bmp","rb");
 if (fp1==NULL)
  { printf("\nFile red.bmp not found!"); getch(); exit(0); }
  fseek (fp1 , 0 , SEEK_END);
  s = ftell (fp1);
  fseek(fp1,0,SEEK_SET);
 red = (char*) malloc (sizeof(char)*s);
 fread(red,1,s,fp1);
 red_b  =*(red  +54);  red_g  =*(red  +55);  red_r  =*(red  +56);
 //printf("%c,%c,%c,",red_b,red_g,red_r);
 fclose(fp1);
 
 //Reading of RGB of 'File2 exclusive' shade------------------------------------

 fp1=fopen("blue.bmp","rb");
 if (fp1==NULL)
  { printf("\nFile blue.bmp not found!"); getch(); exit(0); }
  fseek (fp1 , 0 , SEEK_END);
  s = ftell (fp1);
  fseek(fp1,0,SEEK_SET);
 blue = (char*) malloc (sizeof(char)*s);
 fread(blue,1,s,fp1);
 blue_b  =*(blue  +54);  blue_g  =*(blue  +55);  blue_r  =*(blue  +56);
 //printf("%c,%c,%c,",blue_b,blue_g,blue_r);
 fclose(fp1);
 
 //Reading of RGB of 'File1-File2 both not sacrosanct' shade-------------------
 
 fp1=fopen("green.bmp","rb");
 if (fp1==NULL)
  { printf("\nFile green.bmp not found!"); getch(); exit(0); }
  fseek (fp1 , 0 , SEEK_END);
  s = ftell (fp1);
  fseek(fp1,0,SEEK_SET);
 green = (char*) malloc (sizeof(char)*s);
 fread(green,1,s,fp1);
 green_b  =*(green  +54);  green_g  =*(green  +55);  green_r  =*(green  +56);
 //printf("%c,%c,%c,",green_b,green_g,green_r);
 fclose(fp1);
 
 //Reading the File1------------------------------------------------------------
 
 fp1=fopen("file1.bmp","rb");
 if (fp1==NULL)
  { printf("\nFile file1.bmp not found!"); getch(); exit(0); }
  fseek (fp1 , 0 , SEEK_END);
  s = ftell (fp1);
  fseek(fp1,0,SEEK_SET);
 a = (char*) malloc (sizeof(char)*s);
 fread(a,1,s,fp1);
 fclose(fp1);

//Reading the File2-------------------------------------------------------------

 fp1=fopen("file2.bmp","rb");
 if (fp1==NULL)
  { printf("\nFile file2.bmp not found!"); getch(); exit(0); }
  fseek (fp1 , 0 , SEEK_END);
  s = ftell (fp1);
  fseek(fp1,0,SEEK_SET);
 b = (char*) malloc (sizeof(char)*s);
 fread(b,1,s,fp1);
 fclose(fp1);

//Comparing File1 and File2 to write File3--------------------------------------

 fp3=fopen("file3.bmp","wb");
 for(i=0,j=0;i<s;i=i)
  {
   if(i<54)
    {
     fwrite((a+i),1,1,fp3);
     i+=1;
     j+=1;
    }
   else
    {
     a_b=*(a+j); a_g=*(a+j+1); a_r=*(a+j+2);
     b_b=*(b+j); b_g=*(b+j+1); b_r=*(b+j+2); j+=3;
	 
     if(a_b==b_b && a_g==b_g && a_r==b_r)
      {
       if(background=='y')
	   {
   	    fwrite(&white_b,1,1,fp3);
        fwrite(&white_g,1,1,fp3);
        fwrite(&white_r,1,1,fp3);
	   }
	   else
 	   {
   	    fwrite(&a_b,1,1,fp3);
        fwrite(&a_g,1,1,fp3);
        fwrite(&a_r,1,1,fp3);
	   }
      }
     else
      {
       if( !(a_b==white_b && a_g==white_g && a_r==white_r) &&
	        (b_b==white_b && b_g==white_g && b_r==white_r)   )
	     {
 	      fwrite(&red_b,1,1,fp3);
          fwrite(&red_g,1,1,fp3);
	      fwrite(&red_r,1,1,fp3);
	     }
       else if(  (a_b==white_b && a_g==white_g && a_r==white_r) &&
	          	!(b_b==white_b && b_g==white_g && b_r==white_r)   )
	     {
	      fwrite(&blue_b,1,1,fp3);
	      fwrite(&blue_g,1,1,fp3);
	      fwrite(&blue_r,1,1,fp3);
	     }
       else
	     {
	      fwrite(&green_b,1,1,fp3);
	      fwrite(&green_g,1,1,fp3);
	      fwrite(&green_r,1,1,fp3);
	     }
      }
    i+=3;
    }
  }

 fclose(fp3);

 printf("\nComparison Done and saved in File3.bmp. ");
 getch();
 return 0;
}
