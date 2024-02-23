import random
import time


# definicja globalna turn by używać jej to decydowania czy wstawić O czy X i kto wygrał
global turn
turn = 1

 
# definicja funkcji create() tworzącej globalną listę 2d o wymiarach 3x3
def create():

    global table
    table = [[" "," "," "],[" "," "," "],[" "," "," "]]


# definicja funkcji display() wyświetlającej listę podaną jako parametr wraz z przedziałkami między wartościami
def display(x):

    # iteracja po każdym elemencie listy by wszystkie wyświetlić
    for i in range(3):
        for j in range(3):
            print(x[i][j], end = "|")
        print()
        print("------")


# definicja funkcji insert() przyjmującej 2 parametry pól
def insert(a, b):
    
    global turn
    validInput = False
    
    # sprawdzenie czy dane podane do funkcji są poprawne, jeśli nie są one z danego zakresu,
    # pole o tych koordynatach jest już zajęte lub nie są one typu int, pyta użytkownika o nowe parametry
    while validInput == False:
        if a >= 0 and a <= 2 and b >= 0 and b <= 2 and table[a][b] == " ":
            validInput = True
        else:
            try:
                print("invalid input, try again")
                a = int(input("input row: ")) - 1
                b = int(input("input column: ")) - 1
            except ValueError:
                print()

    # uzgodnienie na bazie zmiennej turn czy należy wstawić znak O lub X
    if turn % 2 == 1:
       table[a][b] = "O"
    else:
        table[a][b] = "X"

    turn += 1


# definicja funkcji winCheck() sprawdzającej czy obecnie na planszy jest układ zapewniający wygraną
def winCheck():

    if (table[0][0] == table[0][1] and table[0][0] == table[0][2] and table[0][0] != " " or
    table[1][0] == table[1][1] and table[1][0] == table[1][2] and table[1][0] != " " or
    table[2][0] == table[2][1] and table[2][0] == table[2][2] and table[2][0] != " " or
    table[0][0] == table[1][0] and table[0][0] == table[2][0] and table[0][0] != " " or
    table[0][1] == table[1][1] and table[0][1] == table[2][1] and table[0][1] != " " or
    table[0][2] == table[1][2] and table[0][2] == table[2][2] and table[0][2] != " " or
    table[0][0] == table[1][1] and table[0][0] == table[2][2] and table[0][0] != " " or
    table[0][2] == table[1][1] and table[0][2] == table[2][0] and table[0][2] != " " ):

        # zdecydowanie za pomocą zmiennej turn czy wygrywa gracz O lub gracz X
        if turn % 2 == 0:
            display(table)
            print("player O wins!")
            exit()
        else:
            display(table)
            print("player X wins!")
            exit()


# definicja funkcji fullCheck() sprawdzającej czy plansza jest pełna.
def fullCheck():

   for i in range(3):
        for j in range(3):
            if table[i][j] == " ":
                return False


# definicja funkcji computerPlay() generującej dwie pseudolosowe wartości od 0 do 2 które przesyłane są do funkcji insert(). Jest to forma gry przeciwko komputerowi.
def computerPlay():
    
    # definicja zmiennej w sposób który zagwarantuje chodź jednorazowe wykoanie następującej pętli
    correctPosition = False
    
    # pętla generująca losowe dane do przesłania do funkcji insert() i sprawdzająca ich poprawność
    while correctPosition == False:
        position1 = random.randint(0,2)
        position2 = random.randint(0,2)
        
        if table[position1][position2] == " ":
            correctPosition = True
    
    if correctPosition == True:
        insert(position1, position2)



# pytanie użytkownika o chęć rozpoczęcia gry oraz gry przeciwko komputerowi
ifStartInput = input("start game? (Y/N): ")
ifComputerInput = input("do you want to play against the computer? (Y/N): ")

# sprawdzenie odpowiedzi użytkownika
if ifStartInput.upper() == "Y":
    ifStart = True
else:
    exit()

if ifComputerInput.upper() == "Y":
    ifComputer = True
else:
    ifComputer = False

# stworzenie globalnej listy 2d table[][]
create()

# pętla gry
while ifStart:
    # wyświetlenie stanu planszy
    display(table)
    # definicja zmiennej w sposób który zagwarantuje chodź jednorazowe wykoanie następującej pętli
    validInput = False
    
    # pobranie od użytkownika danych i sprawdzenie ich poprawności
    while validInput == False:
        try:
            input1 = int(input("input row: ")) - 1
            input2 = int(input("input column: ")) - 1
            validInput = True
        except ValueError:
            print("invalid input, try again")

    # użycie danych użytkownika na by postawić adekwatny symbol na planszy
    insert(input1, input2)
    # sprawdzenie czy na planszy jest pozycja wygrywająca
    winCheck()

    # sprawdzenie czy plansza jest pełna, w wypadku braku wolnego miejsca oraz pozycji wygrywających, ogłasza remis
    if fullCheck() != False:
        display(table)
        print("draw")
        exit()
    
    # wykonuje się jedynie gdy użytkownik chce grać z komputerem
    if ifComputer == True:
        # wyświetlenie stanu planszy
        display(table)
        # opóźnienie by reakcja komputera wydawała się bardziej przemyślana
        time.sleep(1.5)
        print("computer's response: ")
        # generacja i wysłanie ruchu komputera do funkcji insert()
        computerPlay()
        # sprawdzenie czy jest pozycja wygrywająca lub remisująca
        winCheck()
        
        if fullCheck() != False:
            display(table)
            print("draw")
            exit()