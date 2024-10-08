#include <stdio.h>
#include <string.h>

char countries[10][20];
int medals[10][3];

void assign_medals(int i, int medal)
{

	if (medal == 0)  // checks for gold
	{
		medals[i][0]++;   // assigns gold
	}

	else if (medal == 1)// checks for silver
	{
		medals[i][1]++;   // assigns silver
	}

	else if (medal == 2) // checks for bronze
	{
		medals[i][2]++;   // assigns bronze
	}

	else
	{
		printf("No such medal exists"); // if value is not 0,1,or 2
	}

}

void sort_medals()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = i+1; j < 10; j++)
        {
            if ((medals[i][0] < medals[j][0]) ||  // check for more golds
                (medals[i][0] == medals[j][0] && medals[i][1] < medals[j][1]) ||  // check for silvers is gold are equal
                (medals[i][0] == medals[j][0] && medals[i][1] == medals[j][1] && medals[i][2] < medals[j][2])) // check for bronze if golds and silver are equal
               
                {
                    int temp_medals[3];
                    memcpy(temp_medals,medals[i],sizeof(temp_medals));
                    memcpy(medals[i], medals[j],sizeof(temp_medals));
                    memcpy(medals[j], temp_medals,sizeof(temp_medals));
                    
                    char temp_country[20];
                    strcpy(temp_country, countries[i]);
                    strcpy(countries[i], countries[j]);
                    strcpy(countries[j], temp_country);
                }
        }
    }
}







void insert(char country[], int medal)
{
	int found = 0;
	
	for (int i = 0; i < 10; i++)
	{
	    if(strcmp(countries[i],country) == 0)
	    {
	        assign_medals(i, medal);
	        found = 1;
	        break;
	    }
	}
	
	if (!found)
	{

		for (int i = 0; i < 10; i++) // loop through all spots in country array
		{
			if (countries[i][0] == '\0') // check if row is empty
			{
				strcpy(countries[i],country); // insert country into array
				assign_medals(i,medal);
				found = 1;
				break;
			}

		}
		
	}

	if (!found)
	{
		printf("\nToo many countries");
	}
	
	sort_medals();

}


void show_all()
{
    printf("\nCountry\t\tGold\t\tSilver\t\tBronze\n");
    for (int i = 0; i < 10; i++)
    {
        if (countries[i][0]!='\0')
        {
            printf("\n%s\t\t%d\t\t%d\t\t%d\n",countries[i],medals[i][0],medals[i][1],medals[i][2]);
        }
    }
}

int main()
{
    int option;
    char country[20];
    int medal;
    
    printf("Type 1 to enter a country and its medals\n");
    printf("Type 2 to show all countries and their medals\n");
    printf("Type 0 to exit program\n");
	
    while (1)
    {
        printf ("Enter option: ");
        if (scanf ("%d", &option) != 1)
        {
            printf ("Exiting\n");
            return 0;
        }
        switch (option)
        {
        case 1:
            printf ("Enter the country name:\n");
            scanf("%s",country);
            
            
            printf("Enter medal type, 0 for Gold, 1 for Silver, 2 for Bronze\n");
            
            if (scanf("%d",&medal) != 1 || medal < 0 || medal > 2)
            {
                printf("No such medal exists. Enter either 0, 1, or 2");
                break;
            }
            
            insert(country, medal);
            continue;
            
        case 2:
            show_all();
            continue;
            
        case 0:
            printf ("Exiting");
            return 0;
            
        default:
            printf ("Wrong option, enter either 0, 1, 2\n");
        }
    }
    return 0;
}
