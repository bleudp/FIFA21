/*

FIFA 2021 - Created by @m3t4f0r4 and @blueudp // @bleudp

Shout out to @0xmrivas for the awesome help

:)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SZ 50
#define MAX_PLAYERS 4
#define MAX_PERCENTAGE 100
#define MIN_PERCENTAGE 1

int s_seed = 0;

int last = 0;

char *futbolistas[MAX_PLAYERS];

int scores[] = {100, 30, 60, 1, 100};

void append_nil(void) {
	futbolistas[last] = 0x0;
	return;
}

void append_player(char *name) {
	futbolistas[last] = name;
	last++;
	return;
}

void append_players(void) {
	append_player("Cristiano Ronaldo");
	append_player("Lionel Messi");
	append_player("Sergio Reguilon");
	append_player("Diego Maradona");
	append_player("Gonzalo Cruceira");
	append_nil();
	return;
}

int gen_rnd(int min, int max) {
	int rnd = 0;
	if(!s_seed) {
		srand((unsigned)rand());
		s_seed = 1;
	}
	rnd = (rand() + min) % max;
	return rnd;
}

int get_player_score(char *buf) {
	int prob = 0;
	int coincides = 0;
	for(int i = 0 ; i < 4 ; i++) {
		if(strcmp(buf, futbolistas[i]) == 0) {
			prob = scores[i];
			coincides = 1;
		}
	}
	if(!coincides) {
		printf("ERROR! Jugador no existe bro\n");
		return -1;
	}
	return prob;
}


int main(int argc, char *argv[]) {
	
	int prob = 0;
	int range = 0;
	int gen = 0;
	int n_penaltis = 10;
	int x = 0;
	char buf[MAX_NAME_SZ];
	
	memset(buf, '\0', sizeof(buf));
	
	append_players();
	
puts("                                                     Gonzalo	 ");
puts("                                                    Cruceira	 ");
puts("	Cristiano							 ");
puts("        Ronaldo     Lionel     Sergio     Diego       ,/)       ");
puts("                    Messi     Reguilon    Maradona    |_|       ");
puts("           _         _          _          _         ].[       ");
puts("          |.|	   |.|        |.|        |.|      /~`-'~\\    ");	
puts("          ]^[	   ]^[        ]^[        ]^[     (<|%  |>)	 ");
puts("        /~`-'~\	 /~`-'~\    /~`-'~\    /~`-'~\       \|___|/	 ");
puts("       {<|%  |>}	{<|%  |>}  {<|%  |>}  {<|%  |>}      {/   \}	 ");
puts("        \|___|/	 \|___|/    \|___|/    \|___|/        /__|__\	 ");
puts("       /\    \	  /   \      /   \      /   \     | / \ |	 ");
puts("       |/>/|__\	 /__|__\    /__|__\    /__|__\    |/   \|	 ");
puts("      _|)   \ |	 | / \ |    | / \ |    | / \ |    {}   {}	 ");
puts("     (_,|    \)	 (/   \)    (/   \)    (/   \)    |)   (|	 ");
puts("     / \     (|	 |)   (|_  _|)   (|_  _|)   (|_  _||   ||_	 ");
puts("  .,.\_/,...,|,_)(_,|,.,|,_)(_,|,.,|,_)(_,|,.,|,_)(_,|.,.|,_).,.\n\n");

	
	while(x < n_penaltis) {
		
		printf("humilde y amable caballero, seria usted tan amable de proporcionarme su nombre: ");
		
		fgets(buf, sizeof(buf), stdin);
		
		buf[strlen(buf)-1] = 0x0;
		
		prob = get_player_score(buf);
		
		if(prob == -1)
			continue;
		
		range = MAX_PERCENTAGE - prob;
		
		gen = gen_rnd(MIN_PERCENTAGE, MAX_PERCENTAGE);
		
		puts("tiramos penalti!!!!");
		
		puts("    -   \O                                     ,  .-.___	");
		puts("  -     /\                                   O/  /xx\XXX\	");
		puts(" -   __/\ `                                  /\  |xx|XXX|	");
		puts("    `    \, ()                              ` << |xx|XXX|	");
		puts("^^^^^^^^^^^`^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
		
		if(gen > range) {
			printf("peaso penarti ompare!!!!!!!!!!!!!!!!!!!!\n");
		} else {
			printf("tiene la punteria en er culo bro\n");
		}
		
		x++;
	}

}
