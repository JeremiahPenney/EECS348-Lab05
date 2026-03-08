#include <stdio.h>

#define SIZE 12

// this will just print the regular month sales report and it willl go therough al 12 months and show the name / sales amount

void mReport(char *month[], double sale[])
{
    int i;
    printf("Monthly Sales Report for 2024\n");
    printf("%-10s %-10s\n", "Month", "Sales");

    for (i = 0; i < SIZE; i++)
    {
        printf("%-10s %.2f\n", month[i], sale[i]);
    }

    printf("\n");
}

// this will just fins the lowest sale highest sale and avg sale then loop through all the sales vals but will keep track of min max and t sum

void s_Report(char *month[], double sale[])
{
    int i;
    int min = 0;
    int max = 0;
    double sum = 0;
    double avg;
    for (i = 0; i < SIZE; i++)
    {
        if (sale[i] < sale[min])
        {
            min = i;
        }
        if (sale[i] > sale[max])
        {
            max = i;
        }
        sum = sum + sale[i];
    }
    avg = sum / SIZE;
    printf("Sales Summary Report:\n");
    printf("Minimum sales: %.2f (%s)\n", sale[min], month[min]);
    printf("Maximum sales: %.2f (%s)\n", sale[max], month[max]);
    printf("Average sales: %.2f\n", avg);
    printf("\n");
}

// its in the name look at the code and pick up from where you didnt finish its not hard lock in
// adds by 6 @ a time but divide by that to get the avg
void movingAverage(char *month[], double sale[])
{
    int i, j;
    double sum;
    printf("Six-Month Moving Average Report:\n");
    for (i = 0; i <= SIZE - 6; i++)
    {
        sum = 0;

        for (j = i; j < i + 6; j++)
        {
            sum += sale[j];
        }

        printf("%s-%s %.2f\n", month[i], month[i + 5], sum / 6);
    }
    printf("\n");
}

// this func justs puts the sales form high-> low
// it will copy the org array so the real sales O dosent get messed up or miss arranged
// then will use the buble sort to just put the big first and well the lowest last hince the name H->L

void highestToLowest(char *month[], double sale[])
{
    int i, j;

    double arr[SIZE];
    char *arrMonth[SIZE];

    double temp;
    char *tempMonth;

    // just copies the  original data into  a anew arrays
    for (i = 0; i < SIZE; i++)
    {
        arr[i] = sale[i];
        arrMonth[i] = month[i];
    }

    // bs(bubble short from ->(highest to lowest) )
    for (i = 0; i < SIZE - 1; i++)
    {

        for (j = 0; j < SIZE - 1 - i; j++)
        {

            if (arr[j] < arr[j + 1])
            {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                tempMonth = arrMonth[j];
                arrMonth[j] = arrMonth[j + 1];
                arrMonth[j + 1] = tempMonth;
            }
        }
    }

    printf("Sales Report (Highest to Lowest):\n");
    printf("%-10s %-10s\n", "Month", "Sales");

    for (i = 0; i < SIZE; i++)
    {
        printf("%-10s $%.2f\n", arrMonth[i], arr[i]);
    }

    printf("\n");
}

// longest part of my code because its like the flow or control center of da code
// it opens the file / reads in all 12 sales values and will closes the file
// it will then call each funu to print the reports (all the things Ive been talking about above )

int main()
{

    FILE *file;

    double sale[SIZE];

    char *month[SIZE] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"};

    int i;

    file = fopen("sales.txt", "r");

    if (file == NULL)
    {
        printf("File could not open\n");
        return 1;
    }

    for (i = 0; i < SIZE; i++)
    {
        fscanf(file, "%lf", &sale[i]);
    }

    fclose(file);

    mReport(month, sale);
    s_Report(month, sale);
    movingAverage(month, sale);
    highestToLowest(month, sale);

    return 0;
}
