#
# Genetic Algorithm for Iterated Prisoners Dilemma
#

#import axelrod as axl
import random


# Return score for ym moves against TFT
def my_score_against_tft(my_moves):

    my_score = 0

    # Define TFT sequence in reltion to my moves
    tft_moves = my_moves
    tft_moves.pop()
    tft_moves.insert(0, 'C')

    for i in range(len(my_moves)):

        if (my_moves[i] == 'C' and tft_moves[i] == 'C'):
            my_score += 3

        if (my_moves[i] == 'C' and tft_moves[i] == 'D'):
            my_score += 0

        if (my_moves[i] == 'D' and tft_moves[i] == 'C'):
            my_score += 5

        if (my_moves[i] == 'D' and tft_moves[i] == 'D'):
            my_score += 1

    return my_score


# Return score for ym moves against STFT
def my_score_against_stft(my_moves):

    my_score = 0

    # Define TFT sequence in reltion to my moves
    stft_moves = my_moves
    stft_moves.pop()
    stft_moves.insert(0, 'D')

    for i in range(len(my_moves)):

        if (my_moves[i] == 'C' and stft_moves[i] == 'C'):
            my_score += 3

        if (my_moves[i] == 'C' and stft_moves[i] == 'D'):
            my_score += 0

        if (my_moves[i] == 'D' and stft_moves[i] == 'C'):
            my_score += 5

        if (my_moves[i] == 'D' and stft_moves[i] == 'D'):
            my_score += 1

    return my_score


# Return score for ym moves against TF2T


def my_score_against_tf2t(my_moves):

    my_score = 0

    # Define TFT sequence in reltion to my moves
    tf2t_moves = ['C', 'C']

    for i in range(len(my_moves)-2):
        idx = i+2

        if (my_moves[i] == 'D' and my_moves[i+1] == 'D'):
            tf2t_moves.append('D')
        else:
            tf2t_moves.append('C')


    for i in range(len(my_moves)):

        if (my_moves[i] == 'C' and tf2t_moves[i] == 'C'):
            my_score += 3

        if (my_moves[i] == 'C' and tf2t_moves[i] == 'D'):
            my_score += 0

        if (my_moves[i] == 'D' and tf2t_moves[i] == 'C'):
            my_score += 5

        if (my_moves[i] == 'D' and tf2t_moves[i] == 'D'):
            my_score += 1

    return my_score




def seq_fitness(sequence, fit_fn):

    # How does this sequence fair against TFT
    my_score = fit_fn(sequence)
    return my_score



def selection(pop, pop_scores, pop_fitness):

    rand_fitness = random.uniform(0, 1)
    current_fitness = 0.0
    result = []

    for i in range(len(pop)):

        if current_fitness <= rand_fitness:

            current_fitness += (pop_scores[i] / pop_fitness)
            result = pop[i]

    return result


def crossover(p1, p2):

    # p1 is [array] of length 10, a sequence

    pos = int(random.random()*len(p1))

    #print("===")
    #print(p1)
    #print(p2)
    #print(p1[:pos] + p2[pos:])
    #print("===")
    return p1[:pos] + p2[pos:]

    #return (dna1[:pos]+dna2[pos:], dna2[:pos]+dna1[pos:])


def mutate(child, mut_prob):

    for i in range(len(child)):

        rand_prob = random.uniform(0, 1)

        if (rand_prob <= mut_prob):

            if (child[i] == 'C'):
                child[i] = 'D'
            else:
                child[i] = 'C'

    return child


# Score of population is score of the best sequence contained within
def score_my_population(pop, fit_fn):

    max_score = -1
    max_seq = []

    for i in range(len(pop)):
        cur_score = fit_fn(pop[i])

        # Update if best seen yet
        if (cur_score > max_score):
            max_score = cur_score
            max_seq = pop[i]

    # Return only score of best seq
    return (max_seq, max_score)


def top_n_in_population(pop, survival_count, fit_fn):

    pop.sort(key=lambda x: seq_fitness(x, fit_fn), reverse=True)
    return pop[:survival_count]



def ga(num_gen, pop_size, num_turns, survival_count, mut_prob, fit_fn):


    # Randomly init population
    current_population = [['Z' for x in range(num_turns)] for y in range(pop_size)]
    for p in range(pop_size):
        for t in range(num_turns):
            current_population[p][t] = random.choice(['C','D'])

    # print(current_population)

    for p in range(pop_size):
        print(current_population[p])
    print()

    # Score each seq in population
    current_pop_scores = []
    #for member in current_population:
    #    current_pop_scores.append( fit_fn(member) )

    #total_pop_fitness = sum(current_pop_scores)


    # For each generation
    for gen in range(num_gen):

        # Init with top 'survival_count' sequences
        next_gen = current_population[:survival_count]#top_n_in_population(current_population, survival_count, fit_fn)
        print (next_gen)

        current_pop_scores = []
        for member in next_gen:
            current_pop_scores.append( fit_fn(member) )
        total_pop_fitness = sum(current_pop_scores)


        # Create new population, 'pop_size' new children
        for i in range(pop_size - survival_count):

            # Select two parents, likely to be more fit parents
            parent1 = selection(next_gen, current_pop_scores, total_pop_fitness)
            parent2 = selection(next_gen, current_pop_scores, total_pop_fitness)

            # Produce child
            new_child = crossover(parent1, parent2)

            # Randomly mutate the child
            child = mutate(new_child, mut_prob)

            # Add to next generation
            next_gen.append(child)


        # Establish next generation, determine best sequence and its score
        current_population = next_gen
        best_seq, best_score = score_my_population(current_population, fit_fn)

        print(best_score)


def main():

    mut_prob = 0.015

    fit_fn = my_score_against_stft

    seq_size = 10
    survival_count = 5
    num_gen = 10
    pop_size = 10


    ga(num_gen, pop_size, seq_size, survival_count, mut_prob, fit_fn)
    #choices = ['D', 'C', 'D']


main()
