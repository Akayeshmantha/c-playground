#include <stdio.h>

void main(int argc, char **argv) {

    //declaration 
    char slot[50]; 

    printf("Enter slot no: ");

    // reading string 
    scanf("%s",slot); 
    
    // print string 
    printf("%s",slot); 
  
    FILE *pf;
    char command[20];
    char data[512];

     // Execute a process listing
    sprintf(command, "lspci -s %s",slot); 

    // Setup our pipe for reading and execute our command.
    pf = popen(command,"r"); 

    if(fgets(data,512,pf))
    printf("The device is %s \n",data);
    else
    printf("Error opening the file");

    // Error handling
    if (pclose(pf) != 0)
        fprintf(stderr," Error: Failed to close command stream \n");

}
