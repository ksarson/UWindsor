#
# Iterated Prisoners Dilemma
# Simulation for GA and Hill Climber
# 60-371 Final Project
#
# Joel Rorseth 104407927
#

#import axelrod as axl
import sys
import random


# MARK: Prisoner scoring logic
# Score player's moves against opponent
def player_score(player_moves, opp_moves):
    player_score = 0

    for i in range(len(player_moves)):

        # Adopt this common scoring metric for IPD
        if (player_moves[i] == 'C' and opp_moves[i] == 'C'):
            player_score += 3

        if (player_moves[i] == 'C' and opp_moves[i] == 'D'):
            player_score += 0

        if (player_moves[i] == 'D' and opp_moves[i] == 'C'):
            player_score += 5

        if (player_moves[i] == 'D' and opp_moves[i] == 'D'):
            player_score += 1

    return player_score


# Return score for ym moves against TFT
def my_score_against_tft(player_moves):

    # Define TFT sequence in relation to my moves
    tft_moves = player_moves
    tft_moves.pop()
    tft_moves.insert(0, 'C')

    return player_score(player_moves, tft_moves)


# Return score for ym moves against STFT
def my_score_against_stft(player_moves):

    # Define STFT sequence in relation to my moves
    stft_moves = player_moves
    stft_moves.pop()
    stft_moves.insert(0, 'D')

    return player_score(player_moves, stft_moves)


# Return score for ym moves against TF2T
def my_score_against_tf2t(player_moves):

    # Define TFT sequence in reltion to my moves
    tf2t_moves = ['C', 'C']

    for i in range(len(player_moves)-2):
        idx = i+2

        if (player_moves[i] == 'D' and player_moves[i+1] == 'D'):
            tf2t_moves.append('D')
        else:
            tf2t_moves.append('C')

    return player_score(player_moves, tf2t_moves)




#MARK: Genetic Algorithm
# Fitness of a sequence
def seq_fitness(sequence, fit_fn):

    # How does this sequence fair against TFT
    my_score = fit_fn(sequence)
    return my_score


# Select a single parent, with more fit parents being more likely
def selection(pop, pop_scores, pop_fitness):

    rand_fitness = random.uniform(0, 1)
    current_fitness = 0.0
    result = []

    for i in range(len(pop)):

        if current_fitness <= rand_fitness:

            current_fitness += (pop_scores[i] / pop_fitness)
            result = pop[i]

    return result


# Produce a child sequence by crossing two parent sequences
def crossover(p1, p2):

    pos = int(random.random()*len(p1))
    return p1[:pos] + p2[pos:]

    #return (dna1[:pos]+dna2[pos:], dna2[:pos]+dna1[pos:])


# Consider randomly flipping the value at every and any index in sequence
def mutate(child, mut_prob):

    for i in range(len(child)):

        rand_prob = random.uniform(0, 1)

        # If random prob is not larger than small mutation prob, mutate
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


# Return random seq (C's and D's) of length n
def random_seq_of_length(n):

    seq = []
    for _ in range(n):
        seq.append(random.choice(['C','D']))
    return seq


# Generate all successors of a node (mutations in one spot)
def generate_all_successors(node):

    successors = []

    for i in range(len(node)):
        new_node = node

        # Replace current index with flipped bit, now a neighbor
        new_node[i] = 'D' if (new_node[i] == 'C') else 'C'
        successors.append(new_node)

    return successors


# HILL CLIMBING search
def hill_climbing(num_turns, fit_fn):

    # Generate random start node
    current_node = random_seq_of_length(num_turns)
    current_node_fitness = -1
    next_node = []
    next_node_fitness = -1

    while (True):

        # Generate successor to current (all one-off variants)
        successors = generate_all_successors(current_node)

        for neighbor in successors:

            neighbor_fitness = fit_fn(neighbor)

            # If this neighbor beats current, move to it
            if (neighbor_fitness > next_node_fitness):
                next_node_fitness = neighbor_fitness
                next_node = neighbor

        #print("Next", next_node_fitness, ">? Current", fit_fn(current_node))

        # If none of the neighbors improved current, terminate
        if (next_node_fitness <= current_node_fitness):
            return current_node_fitness
            #return (current_node, current_node_fitness)

        #print("Current is now seq with fitness", fit_fn(next_node))
        current_node = next_node
        current_node_fitness = next_node_fitness

    return current_node_fitness
    #return (current_node, current_node_fitness)



# GENETIC ALGORITHM search
def ga(num_gen, pop_size, num_turns, survival_count, mut_prob, fit_fn):


    # Randomly init population
    current_population = [['Z' for x in range(num_turns)] for y in range(pop_size)]
    for p in range(pop_size):
        current_population[p] = random_seq_of_length(num_turns)
        #current_population[p][t] = random.choice(['C','D'])


    print("> INITIAL POP")
    for s in current_population:
        print(s)
    print("\n\n")

    # Score each seq in population
    current_pop_scores = []
    for member in current_population:
        current_pop_scores.append( fit_fn(member) )

    total_pop_fitness = sum(current_pop_scores)

    best_seq = []
    best_score = -1

    # For each generation
    for gen in range(num_gen):

        # Init with top 'survival_count' sequences
        next_gen = top_n_in_population(current_population, survival_count, fit_fn)
        
        print("> NEW GEN, STARTING WITH TOP FEW")
        for n in next_gen:
            print(n)
        print()

        # Create new population, 'pop_size' new children
        for i in range(pop_size - survival_count):

            # Select two parents, likely to be more fit parents
            parent1 = selection(current_population, current_pop_scores, total_pop_fitness)
            parent2 = selection(current_population, current_pop_scores, total_pop_fitness)

            # Produce child
            new_child = crossover(parent1, parent2)

            # Randomly mutate the child
            child = mutate(new_child, mut_prob)

            # Add to next generation
            next_gen.append(child)


        # Establish next generation, determine best sequence and its score
        current_population = next_gen
        best_seq, best_score = score_my_population(current_population, fit_fn)

        print("> FINISHING GEN, POP HAS EVOLVED TO:")
        for s in current_population:
            print(s)
        print("\n\n")
        #print("Generation", str(gen), ": Best score =", str(best_score))

    return best_score
    #return (best_seq, best_score)


def main():

    if (len(sys.argv) != 6):
        print("Usage: python3", sys.argv[0],
            "<num_gen> <pop_size> <num_turns> <mut_prob> <fit_fn>")
        sys.exit()


    num_gen = int(sys.argv[1])
    pop_size = int(sys.argv[2])
    num_turns = int(sys.argv[3])
    mut_prob = float(sys.argv[4])

    fit_fn = my_score_against_tft

    if (sys.argv[5] == "tf2t"):
        fit_fn = my_score_against_tf2t
    if (sys.argv[5] == "stft"):
        fit_fn = my_score_against_stft

    survival_count = int(pop_size / 2)

    # TODO: Make a range of game lengths to stack up GA vs Hill, graph it?
    # The GA should use TFT? use the best mutation rate and other params


    # TODO: Compare different mutation rates and graph score for GA only...
    # Vary mut_prob from 0 to 0.3 (aka 0 to 30% ish maybe)

    # TODO: Compare different population sizes... vary pop_size


    # Get scores from respective search algo
    best_score_hill = hill_climbing(num_turns, fit_fn)
    print("Hill Climbing final score:", best_score_hill)

    best_score_ga = ga(num_gen, pop_size, num_turns, survival_count, mut_prob, fit_fn)
    print("Gen Algorithm final score:", best_score_ga)


main()
