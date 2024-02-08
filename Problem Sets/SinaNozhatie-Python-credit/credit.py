# importing libraries

from cs50 import get_int
import re


def main():
    # infinite loop if user enter letter or negative int
    while True:
        cardnumber = get_int("card number:")
        if cardnumber > 0:
            break

    if validity(cardnumber) == True:
        choose_bank(cardnumber)

    else:
        print("INVALID")


def validity(cardnumber):
    # check the lenth of the cardnumber
    lenth = len(str(cardnumber))

    # if the checksum and lenth both = True then the function returns True
    if (lenth == 13 or lenth == 15 or lenth == 16) and (checksum(cardnumber) == True):
        return True

    else:
        return False


def checksum(cardnumber):
    sum1 = 0
    sum2 = 0
    i = 0

    while cardnumber != 0:
        if i % 2 == 0:  # if it's the last digit add it to sum2
            sum2 += cardnumber % 10

        else:
            n = 2 * (cardnumber % 10)  # multiply the second last digit by 2

            if n > 9:
                sum1 += (
                    n % 10 + n / 10
                )  # if the number was 12 do 1 + 2 then add to sum1

            else:
                sum1 += n
        # int(x) for removing the decimals
        sum1 = int(sum1)
        sum2 = int(sum2)
        cardnumber = cardnumber / 10  # remove the last Digit
        cardnumber = int(cardnumber)
        i += 1

    sum = sum1 + sum2

    # the last digit of sum must = 0

    if sum % 10 == 0:
        return True

    else:
        return False


def choose_bank(cardnumber):
    # sorting a list of RegEx
    pattern = ["^34", "^37", "^51", "^52", "^53", "^54", "^55", "^4"]
    for i in range(8):
        # check each RegEx in pattern with cardnumber
        result = re.match(pattern[i], str(cardnumber))
        if result:  # if they match the loop will stop
            break
        else:
            i += 1  # to print INVALID

    # i is the number of RegEx in list
    if i == 0 or i == 1:
        print("AMEX")

    elif i == 2 or i == 3 or i == 4 or i == 5 or i == 6:
        print("MASTERCARD")

    elif i == 7:
        print("VISA")

    else:
        print("INVALID")


main()
