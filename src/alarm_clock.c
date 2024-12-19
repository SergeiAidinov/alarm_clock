/*
 ============================================================================
 Name        : alarm_clock.c
 Author      : Sergei Aidinov
 Version     :
 Copyright   : WTFPL
 Description : Alarm clock in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

int alarm_hour = 0;
int alarm_minute = 0;
const int RING_MAX_QTY = 4;
const int RING_INTERVAL = 1;

void ringing() {
	static int ring_counter = 0;
	if (ring_counter == RING_MAX_QTY) exit(0);
	printf("Ringing... %d\n", ring_counter);
	system(
					"play -n -q synth \
					pl F4  pl A4  pl C5  pl F5  pl C4  pl G4  pl C5  pl E5  pl D4  pl F4  \
					pl A4  pl D5  pl A3  pl F4  pl A4  pl C5  pl F5  pl C4  pl G4  pl C5  \
					pl E5  pl D4  pl F4  pl A4  pl D5  pl A3  pl E4  pl A4  pl C5  pl Bb3 \
					pl D4  pl F4  pl Bb4 pl F3  pl C4  pl F4  pl A4  pl Bb3 pl D4  pl F4  \
					pl Bb4 pl C4  pl E4  pl G4  pl C5  pl F4  pl A4  pl C5  pl F5  pl C4  \
					pl G4  pl C5  pl E5  pl D4  pl F4  pl A4  pl D5  pl A3  pl E4  pl A4  \
					pl C5  pl Bb3 pl D4  pl F4  pl Bb4 pl F3  pl C4  pl F4  pl A4  pl Bb3 \
					pl D4  pl F4  pl Bb4 pl C4  pl E4  pl G4  pl C5 \
					pl A4  pl G4  pl F4  pl E4  pl D4  pl C4  pl D4  pl E4 \
					delay \
					0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 \
					+0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 \
					+0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 \
					+0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 \
					+0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 \
					+0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 \
					+0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 \
					+0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 \
					+0.700 +0.700 +0.700 +0.700 +0.700 +0.700 +0.700 +0.700 \
					\
					remix - fade 0 20 .1 norm -1");
	alarm_minute += RING_INTERVAL;
	ring_counter++;
}

void clock_work() {
	int hour, minute, second;
	do {
		time_t mytime = time(NULL);
		struct tm *now = localtime(&mytime);
		hour = now->tm_mday - 4;
		minute = now->tm_min;
		second = now->tm_sec;
		printw("Alarm clock is set for %d hour(s) %d minute(s)\n", alarm_hour, alarm_minute);
		printw("Date: %d.%d.%d\n", now->tm_mday, now->tm_mon + 1,
				now->tm_year + 1900);
		printw("Time: %d:%d:%d\n", hour, minute, second);
		refresh();
		clear();
		sleep(1);
		if (hour >= alarm_hour && minute >= alarm_minute) {
			ringing();
		}
	} while (1);
}

int main(int argc, char * argv[]) {
	initscr();
	curs_set(0);
	alarm_hour = atoi(argv[1]);
	alarm_minute = atoi(argv[2]);
	clock_work();
	return EXIT_SUCCESS;
}


	/*system(
					"play -n -q synth \
					pl F4  pl A4  pl C5  pl F5  pl C4  pl G4  pl C5  pl E5  pl D4  pl F4  \
					pl A4  pl D5  pl A3  pl F4  pl A4  pl C5  pl F5  pl C4  pl G4  pl C5  \
					pl E5  pl D4  pl F4  pl A4  pl D5  pl A3  pl E4  pl A4  pl C5  pl Bb3 \
					pl D4  pl F4  pl Bb4 pl F3  pl C4  pl F4  pl A4  pl Bb3 pl D4  pl F4  \
					pl Bb4 pl C4  pl E4  pl G4  pl C5  pl F4  pl A4  pl C5  pl F5  pl C4  \
					pl G4  pl C5  pl E5  pl D4  pl F4  pl A4  pl D5  pl A3  pl E4  pl A4  \
					pl C5  pl Bb3 pl D4  pl F4  pl Bb4 pl F3  pl C4  pl F4  pl A4  pl Bb3 \
					pl D4  pl F4  pl Bb4 pl C4  pl E4  pl G4  pl C5 \
					pl A4  pl G4  pl F4  pl E4  pl D4  pl C4  pl D4  pl E4 \
					delay \
					0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 \
					+0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 \
					+0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 \
					+0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 \
					+0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 \
					+0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 \
					+0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 \
					+0.175 +0.175 +0.175 +0.175 +0.175 +0.175 +0.175 \
					+0.700 +0.700 +0.700 +0.700 +0.700 +0.700 +0.700 +0.700 \
					\
					remix - fade 0 20 .1 norm -1");*/
	/*refresh();
	clear();*/








