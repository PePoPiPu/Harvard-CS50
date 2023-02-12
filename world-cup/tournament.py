# Simulate a sports tournament

import csv
import sys
import random

# Number of simulations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            # Convert team's rating to int
            rating = int(row.get("rating"))
            team = {row.get("team"), rating}
            # Append into list
            teams.append(team)
    print(f"{teams}")
    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts

    winner = simulate_tournament(teams)

    print(f"{teams}")
    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["ratings"]
    rating2 = team2["ratings"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])
    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    round1 = simulate_round(teams)
    round2 = simulate_round(round1)
    round3 = simulate_round(round2)
    round4 = simulate_round(round3)
    return round4
if __name__ == "__main__":
    main()
