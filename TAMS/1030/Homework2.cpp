/*David Zhao
CSCE 1030
9-26-17
Program that models a disease outbreak
*/
#include <stdio.h>
using namespace std;

int main()
{
	printf("Computer Science and Engineering\n");
	printf("CSCE 1030 - Computer Science I\n");
	printf("David Zhao     dz0086    davidzhao@my.unt.edu\n");
	//variables
	int total = 0;
	int suscep, infec;
	int recov = 0;
	double contRate, recRate;
	int suscepOld, infecOld, recovOld, days;
	//prompting for total
	while (total < 1)
	{
		printf("Please enter the total number of people: ");
		scanf("%d", &total);
		if (total < 1)
		{
			printf("Please enter a valid number of people.\n");
		}
	}
	//prompting for infected
	printf("Please enter the initial number of infected: ");
	scanf("%d", &infec);
	while (total < infec)
	{
		printf("Please enter a valid number: ");
		scanf("%d", &infec);
	}
	//prompting for contact rate
	printf("Please enter the contact rate: ");
	scanf("%lf", &contRate);
	while ((contRate < 0) || (contRate > 1))
	{
		printf("Please enter a valid number: ");
		scanf("%lf", &contRate);
	}
	//prompting for recovery rate
	printf("Please enter the recovery rate: ");
	scanf("%lf", &recRate);
	while ((recRate < 0) || (recRate > 1))
	{
		printf("Please enter a valid number: ");
		scanf("%lf", &recRate);
	}

	//setting variables to initial positions
	suscep = total - infec;
	suscepOld = suscep;
	infecOld = infec;
	recovOld = recov;
	days = 0;
	//actual loop of infection
	while (infec > 0)
	{
		
		suscep = suscepOld - ((contRate * infecOld * suscepOld));
		infec = infecOld + (contRate * infecOld * suscepOld) - (recRate * infecOld);
		recov = recovOld + (recRate * infecOld);
		printf("Day:%d	S: %d	I: %d	R: %d \n", days, suscep, infec, recov);
		suscepOld = suscep;
		infecOld = infec;
		recovOld = recov;
		days++;
	}
	//final printf
	printf("The outbreak took %d days to end.\n", days);
}
