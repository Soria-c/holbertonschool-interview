#!/usr/bin/python3
"""Prime Game
Maria and Ben are playing a game. Given a set of consecutive integers starting
1 up to and including n, they take turns choosing a prime number the
set and removing that number and its multiples the set. The player that
cannot make a move loses the game.
"""


def print_numbers(numbers):
    """Prints the numbers in the list"""
    """print(" leaving", end=" ")"""
    flag = True
    for x in range(len(numbers)):
        if flag is False:
            """print(", ", end="")"""
        flag = False
        """print("{}".format(numbers[x]), end="")"""


def isWinner(x: int, nums: list):
    """Prime Game
    args:
        x: number of rounds
        nums: array of n
    returns:
        name of the player that won the most rounds
        or None in case of a tie
    """
    if not nums or x < 1 or min(nums) < 1 or len(nums) != x:
        return None

    ben = 0
    maria = 0
    for i in range(len(nums)):
        """print("Round {}: {}".format(i, nums[i]))"""
        if nums[i] == 1:
            """print("\t- Ben wins because there are no prime numbers "
                  "for Maria to choose")"""
            ben += 1
            continue
        numbers = [x for x in range(1, nums[i] + 1)]

        first = True
        while 1:
            if first is True:
                first = False
                newList = []
                flag = True
                """print("\t- Maria picks {} and removes ".
                      format(numbers[1]), end="")"""
                for i in range(len(numbers)):
                    if numbers[i] % 2 == 0 and numbers[i] != 1:
                        if flag is False:
                            """print(", ", end="")"""
                        flag = False
                        """print("{}".format(numbers[i]), end="")"""
                        numbers[i] = 0
                    else:
                        newList.append(numbers[i])
                numbers = newList
                """print_numbers(numbers)"""
            else:
                """print("\t- Maria picks {} and removes {}"
                      .format(numbers[1], numbers[1]), end="")"""
                numbers.remove(numbers[1])
                print_numbers(numbers)
            if len(numbers) == 1:
                """print("\t- Maria wins because there are no prime numbers "
                      "left for Ben to choose")"""
                maria += 1
                break
            # print(numbers)
            """print("\t- Ben picks {} and removes {}"
                  .format(numbers[1], numbers[1]), end="")"""
            numbers.remove(numbers[1])
            """print_numbers(numbers)"""
            if len(numbers) == 1:
                """print("\t- Ben wins because there are no prime numbers "
                      "left for Maria to choose")"""
                ben += 1
                break

    if ben == maria:
        return None
    elif ben > maria:
        return "Ben"
    return "Maria"


if __name__ == "__main__":
    isWinner(3, [4, 5, 1])
