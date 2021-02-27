#include "monty_hall.h"

#include "random_gen.h"

double winning_probability(const unsigned long runs) {
    double wins = 0; //number of won cars

    for (unsigned long i = 0; i < runs; i++) {
        double randCar = get_random_number();
        int car = static_cast<int>(randCar * 3); //number of the door with the car
        double randChoose = get_random_number();
        int choose = static_cast<int>(randChoose * 3); //number of the door chosen by player
        if (car != choose){
            wins++;
            //Monty Hall opens the door with the goat
            //and the player's door is also with the goat,
            //so the player chooses the only door with the car
        }
        //if the player's door was with the car, doesn't matter, witch of two other doors
        //opens Monty Hall - the player will change his door and definitely get the goat
    }
    if (runs > 0) {
        wins /= runs;
        return wins;
    } else {
        return 0; //if there were no tries, there are no cars won
    }
}
