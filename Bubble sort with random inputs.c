/*Okay, I don't want to get overworked so I'm going to 'only' do bubble sort. Nah, it's a big accomplishment, yep, no doubt.<delulu>*/
/*Edit, okayyy, I went a bit overboard :3 , but I like it and I'm proud iof it. I was excited and curious, and that is IT. */
/*NO WAAAY, HUGE FUCKING IMPROVEMENTS. me b4: pointer... what? me now: muhahahaha, I am master of it all. Like the comparison of my previous code and now is so fucking huge*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>//used to copy things byte by byte. for example memcpy(*to, *from, numBytes)      I used it in the array save copy thing

void check_i(int check, int n);  // declaration (promise) <-- ChatGPT ; this is just to tell the program that the function check_i exists, because array_init_manuals print_array was having some problems
void print_array(int array[], int n_1);

int n_1;//number of elements in array

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

int main()
{
    int choice_1,a,b,choice_2;

    srand(time(0));

    printf("Input the desired number of elements in 'array'\n");
    int check_1 = scanf("%d",&n_1);
    check_i(check_1, 1);
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
    
    printf("We are going to do the bubblesort now, type '1' for min2max sort or type '2' for max2min sort.\n");
    int check_4 = scanf("%d",&choice_2);
    check_i(check_4, 1);
    if (choice_2 != 1 && choice_2 != 2)
    {
        printf("ERROR: wrong input values (only '1' or '2' permitted)\n");
        exit(1);
    }
    //int array_sorted_min2max[] = array[]; //wrong way to copy an array
    int array_sorted_min2max[n_1];
    memcpy(array_sorted_min2max, array, sizeof(array));
    if (choice_2 == 1)
    {
        bubblesort_min2max(array_sorted_min2max,n_1);
        print_array(array,n_1);
        print_array(array_sorted_min2max,n_1);

    }
    else if (choice_2 == 2)
    {
    
    }
    /*Implement Bubble Sort yourself — you already have the array ready, it’s a natural next step.

    Add sorting order choice — ascending or descending.
    
    Add statistics — min, max, average of the array.*/

    

    return 0;
}