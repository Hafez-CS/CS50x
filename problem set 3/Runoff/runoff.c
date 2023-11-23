#include <cs50.h>
#include <ctype.h>
#include <math.h>
// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{

    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{

    for (int u = 0; u < candidate_count; u++)
    {
        if (strcmp(candidates[u].name, name) == 0)
        {

            preferences[voter][rank] = u;
            return true;
            return 0;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{

    int y = 0;
    int b = 0;

    for (int i = 0; i < voter_count; i++)
    {

        y = preferences[i][0];

        if (candidates[y].eliminated == false)
        {
            candidates[y].votes += 1;
        }
        else
        {

            do
            {
                b += 1;
                y = preferences[i][b];
            }
            while (candidates[y].eliminated == true);

            if (candidates[y].eliminated == false)
            {
                candidates[y].votes += 1;
            }
        }
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{

    for (int i = 0; i < candidate_count; i++) // loop thru candidates
    {

        int a = (candidates[i].votes * 100) / voter_count;

        if (a > 50) // more than 50 %
        {
            printf("winner %s\n", candidates[i].name);
            return true;
        }
    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{

    int s = 0;
    int g = 0;
    int h = -1;

    for (int p = 0; p < candidate_count; p++)
    {

        if (g < candidates[p].votes)
        {
            g = candidates[p].votes;
            s = p;
        }
    }

    for (int m = 0; m < candidate_count; m++)
    {

        if (candidates[s].votes >= candidates[m].votes && s != m && candidates[m].eliminated == false)
        {
            h = m;
        }
    }

    return candidates[h].votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{

    int s = 0;
    int g = 0;
    int h = -1;

    for (int p = 0; p < candidate_count; p++)
    {

        if (g < candidates[p].votes)
        {
            g = candidates[p].votes;
            s = p;
        }
    }

    if (min == g)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void eliminate(int min)
{

    for (int k = 0; k < candidate_count; k++) // loop thru candidates
    {
        if (candidates[k].votes == min && candidates[k].eliminated == false)
        {
            candidates[k].eliminated = true;
        }
    }

    return;
}







