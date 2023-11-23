#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9 // Max number of candidates

typedef struct // Candidates have name and vote count
{
    string name;
    int votes;
} candidate;

candidate candidates[MAX]; // Array of candidates

int candidate_count; // Number of candidates
string jame;

bool vote(string name); // Function prototypes
void print_winner(void);

int main(int argc, string argv[])
{

    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // voters for candidates
    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int x = 0; x < voter_count; x++)
    {
        jame = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(jame))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{

    for (int u = 0; u < candidate_count; u++)
    {

        if (strcmp(candidates[u].name, name) == 0)
        {
            candidates[u].votes += 1;
            return true;
            return 0;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{

    int s = 0;
    int g = 0;
    int u = 0;

    for (int p = 0; p < candidate_count; p++)
    {

        if (g < candidates[p].votes)
        {
            g = candidates[p].votes;
            s = p;
        }
    }

    if (g == 0)
    {

        for (int y = 0; y < candidate_count; y++)
        {
            printf("%s\n", candidates[y].name);
        }
    }
    else
    {

        printf("%s\n", candidates[s].name);

        for (int x = 0; x < candidate_count; x++)
        {

            if (candidates[s].votes == candidates[x].votes && s != x)
            {
                printf("%s\n", candidates[x].name);
                u += 1;
            }
        }
    }
}
