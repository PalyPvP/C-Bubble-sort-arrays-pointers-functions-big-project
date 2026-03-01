/*Okay, I don't want to get overworked so I'm going to 'only' do bubble sort. Nah, it's a big accomplishment, yep, no doubt.<delulu>*/
/*Edit, okayyy, I went a bit overboard :3 , but I like it and I'm proud iof it. I was excited and curious, and that is IT. */
/*NO WAAAY, HUGE FUCKING IMPROVEMENTS. me b4: pointer... what? me now: muhahahaha, I am master of it all. Like the comparison of my previous code and now is so fucking huge*/
/*Pushed onto github, hell yeah!*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>//used to copy things byte by byte. for example memcpy(*to, *from, numBytes)      I used it in the array save copy thing
#include <limits.h>//used for INT_MIN and INT_MAX for my calc_arraymin/max functions, I need the lowest possible values an int can have in there for the logic

void check_i(int check, int n);  // declaration (promise) <-- ChatGPT ; this is just to tell the program that the function check_i exists, because array_init_manuals print_array was having some problems
void print_array(int array[], int n_1);

//int n_1;//number of elements in array //unnecessary global variable, I'm already always passing it to functions, replaced with local variable in main

void array_init_gen(int array[], int a, int b, int n_1)
{
    for (int i=0; i<n_1;i++)
    {
        array[i] = rand() % (b - a + 1) + a;
    }
    print_array(array,n_1);
}

void array_init_manual(int array[], int n_1)
{
    printf("Now you are going to input values for the array in the elements 0 through %d\n",n_1);
    for(int i = 0; i<n_1;i++)
    {
        printf("Input the value for %d. place\n",i);
        int check_1 = scanf("%d",&array[i]);
        check_i(check_1,1);
        printf("The value %d was assigned correctly\n",array[i]);
    }
    print_array(array,n_1);
}

void print_array (int array[], int n_1)
{
    //int n = sizeof(array)/sizeof(array[0]);  //doesnt work, I passed just a pointer and I cant get reliable value from a pointer, do it in main or just get normally by n_1 value
    for (int i = 0; i<n_1; i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
}

void bubblesort_min2max(int array_bs[], int n_1)
{
    for (int i = 0; i<n_1-1;i++)
    {
        for (int j = 0; j<n_1-i-1;j++)
        {
            if (array_bs[j]>array_bs[j+1])
            {
                int temp = array_bs[j+1];
                array_bs[j+1] = array_bs[j];
                array_bs[j] = temp;
            }
        }
    }
}

void bubblesort_max2min(int array[], int n_1)//I got the conclusion that the for loops should just stay the same and we will add one variable that changes over loops
{//here I dont need to write the pointer thingy manually because C converts arrays to pointers automatically , so it updates the original value (it works with it too)
    for (int i=0;i<n_1-1;i++ )//quick recap: if i is smaller than n_1-1 then go
    {/*
        printf("%d. pass O.F\t\t",i); //troubleshooting 1
        print_array(array,n_1);
        */
        int k =n_1-1;//so for 5 element array the value is 4 (last elements line value)
        for (int j=0;j<n_1-1-i;j++)
        {/*
            printf("\t%d. pass I.F.\t",j); //troubleshooting 1
            print_array(array,n_1);
            printf("\n");
            */

            //k = k-1; //we decrease it every pass instead of increasing like with j in min2max function ; I accidentally put it before executing part so it didnt sort the most-right variable
            if (array[k]>array[k-1])
            {
                int temp = array[k-1];
                array[k-1] = array[k];
                array[k] = temp;
            }
            k = k-1;
        }
        //printf("\n"); //troubleshooting 1
    }
}


void check_i (int check, int n)//n is just the number of things that you are scanning for
{
    if (check!=n)
    {
        printf("ERROR: Bad input (only positive integer values allowed)\n");
        exit(1);
    }
}

void i_generation_range (int *a, int *b)//no wayy, I actually learned adresses and pointers here. HELL YEAH! thats my vibe
{
    //int a,b;
    printf("Input the generation range <a;b>\n");
    int check = scanf("%d%d",a,b);
    check_i(check,2);
    /*
    printf("\n%p\n",a); //just checking the behaviour of printing pointers while explainthing this to myself to understand it more
    printf("%d\n",*a);
    */
}

void calc_array_min (int array[], int n_1, int *array_min)
{
    for (int i = 0; i<n_1 ; i++)
    {
        if (array[i] < array[i+1])
        {

        }
    }
}

void calc_array_max (int array[], int n_1, int *array_max)//array_max should first be declared as the lowest possible INT value (using the library limits.h it's "INT_MIN")
{
    for (int i = 0; i<n_1; i++)
    {
        if (array[i]>*array_max)//same thing as below
        {
            *array_max = array[i]; //as said below the * dereferences array_max from the memory adress and allows correct int to int comparison, not int to memory value
        }

        /* storing this away to learn from history, this logical flaw is horrendous, but hey, I found it and fixed it without AI stepping in and without seeing the fault on runtime
        if (array[i]>array[i+1])
        {
            *array_max = array[i] ;//I had int b4 array_max but that is forbidden bacause its already defined and it points to mains variable       PLUS      I need to put * before an variable that is like array_max
        }//PLUS I need to put * before an variable that is like array_max.    array_max = array[i] is "Put this value int into var. array_max", but *array_max = array[i] means "Put int value into an memory data type variable (impossible - will output error invalid data type conversion int ->*int) "\
        */
    }
    printf("The maximum value of the array is %d\n",*array_max);
}

int main()
{
    int choice_1,a,b,choice_2;
    int n_1;

    srand(time(0));

    printf("Input the desired number of elements in 'array'\n");
    int check_1 = scanf("%d",&n_1);
    check_i(check_1, 1);
    if (n_1 <= 0)
    {
        printf("ERROR: negative and 0 values are not allowed\n");
        return 1;
    }
    int array[n_1];
    printf("An array consisting of %d elements was created sucessfully\n",n_1);
    printf("Do you wish to input the values into the array manually (type '1') or do you want to generate them (type '2')?\n");
    int check_2 = scanf("%d",&choice_1);
    check_i(check_2, 1);
    if (choice_1 != 1 && choice_1 != 2)
    {
        printf("ERROR: wrong input values (only '1' or '2' permitted)\n");
        exit(1);
    }
    if (choice_1 == 1)
    array_init_manual(array,n_1);
    else if (choice_1 == 2)
    {/*
        printf("Input the generation range <a;b>\n");
        int check_3 = scanf("%d%d",&a,&b);
        check_i(check_3,2);*/
        i_generation_range(&a, &b);
        array_init_gen(array,a,b,n_1);
    }
    
    printf("\nWe are going to do the bubblesort now, type '1' for min2max sort or type '2' for max2min sort.\n");
    int check_4 = scanf("%d",&choice_2);
    check_i(check_4, 1);
    if (choice_2 != 1 && choice_2 != 2)
    {
        printf("ERROR: wrong input values (only '1' or '2' permitted)\n");
        exit(1);
    }
    if (choice_2 == 1)
    {
        //int array_sorted_min2max[] = array[]; //wrong way to copy an array
        int array_sorted_min2max[n_1];
        memcpy(array_sorted_min2max, array, sizeof(array));//copies memory from one place to another e.g; (<destination>,<source>,<size of the load>)

        bubblesort_min2max(array_sorted_min2max,n_1);
        printf("The original array:\t");
        print_array(array,n_1);
        printf("The sorted array:\t");
        print_array(array_sorted_min2max,n_1);

    }
    else if (choice_2 == 2)
    {
        int array_sorted_max2min[n_1];
        memcpy(array_sorted_max2min, array, sizeof(array));//copies memory from one place to another e.g; (<destination>,<source>,<size of the load>)
        bubblesort_max2min(array_sorted_max2min, n_1);
        printf("The original array:\t");
        print_array(array,n_1);
        printf("The sorted array:\t");
        print_array(array_sorted_max2min,n_1);
    }


    char choice_3 [4];//4 because three characters AND /0
    printf("\nNow we are going to calculate the max, min and the average of the array\n");
    printf("1st place: min, 2nd place:max, 3rd place:avg.\n"
           "1 = ON, 0 = OFF.  (type a code like e.g. '010' for only max value)\n");
    int check_5 = scanf("%s",choice_3);
    check_i(check_5, 1);
    //printf("%d",choice_3[0]); // this helped me diagnose why the comparison didnt work. if I printed the whole string then I would get the classical (101) result but print only one and it returns the ASCII value
    if ((choice_3[0] != '1' && choice_3[0] != '0') || (choice_3[1] != '1' && choice_3[1] != '0') || (choice_3[2] != '1' && choice_3[2] != '0')) // if I do '1' then it behaves like an char and has the value of 49 so
    {// the comparison will be is 49 != 49?      but if I had without '' then it would be is 49 != 1 
        printf("ERROR: wrong input values (2nd)\n");
        return 1;
    }
    if (choice_3[0] == '1')
    {
        int array_min;
        //calc_array_min
    }
    if (choice_3[1] == '1')
    {
        int array_max = INT_MIN;
        calc_array_max(array, n_1, &array_max);
    }
    if (choice_3[2] == '1')
    {
        int array_avg;
        //calc_array_avg
    }



           
           
           /*
    int check_5 = scanf("%s",choice_3);//data type s ; I don't need to add & to choice_3 bcs its an array and it automatically decays into a pointer of a memory adress so I dont have to do it myself
    check_i(check_5,1);
    printf("%s\n",choice_3);//the data type choice is "s"
    */
    

    /*Implement Bubble Sort yourself — you already have the array ready, it’s a natural next step.

    Add sorting order choice — ascending or descending.
    
    Add statistics — min, max, average of the array.*/

    

    return 0;
}