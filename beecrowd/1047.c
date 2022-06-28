#include <stdio.h>
#include <stdlib.h>

int getHour()
{
	int hour = 0;
	scanf("%d",&hour);

	return hour;

}

int getMinute()
{
	int minute = 0;
	scanf("%d",&minute);

	return minute;

}

void printDuration(int initialHour, int initialMinute, int finalHour, int finalMinute)
{
	initialHour*=60;
	finalHour*=60;

	int initialTimeInMinutes = initialHour+initialMinute;
	int finalTimeInMinutes = finalHour + finalMinute;

	if(finalTimeInMinutes < initialTimeInMinutes)
		finalTimeInMinutes += 1440;

	int	durationInMinutes = finalTimeInMinutes - initialTimeInMinutes;

	if(durationInMinutes == 0)
	{
		printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
		return;
	}

	printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",durationInMinutes/60,durationInMinutes%60);

}

typedef struct time {
	int hour;
	int minute;

}time;

int main()
{
	time *startTime = malloc(sizeof(time));
	time *endTime = malloc(sizeof(time));

	startTime->hour = getHour();
	startTime->minute = getMinute();

	endTime->hour = getHour();
	endTime->minute = getMinute();

	printDuration(startTime->hour, startTime->minute, endTime->hour, endTime->minute);

	free(startTime);
	free(endTime);

	return 0;
}
