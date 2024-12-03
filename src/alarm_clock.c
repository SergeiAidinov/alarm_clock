/*
 ============================================================================
 Name        : alarm_clock.c
 Author      : Sergei Aidinov
 Version     :
 Copyright   : WTFPL
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

int main(void) {
	initscr();
	curs_set(0);
	time_t init_time = time(NULL);
	sleep(3);
	do {
		time_t mytime = time(NULL);
		struct tm *now = localtime(&mytime);
		long tm_sec_diff = (mktime(&mytime) - mktime(&init_time));
		printf("%d ==> ", tm_sec_diff);
		printw("Date: %d.%d.%d\n", now->tm_mday, now->tm_mon + 1,
				now->tm_year + 1900);
		printw("Time: %d:%d:%d\n", now->tm_hour, now->tm_min, now->tm_sec);
		refresh();
		clear();
		sleep(1);
		system(
				"play -n synth \
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
	} while (1);

	return EXIT_SUCCESS;
}
