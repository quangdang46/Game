from unicodedata import name
from art import logo,vs
from game_data import data
from random import choice

def GetData():
    return choice(data)

def CheckData(data_1,data_2):
    x=data_1.values()
    y=data_2.values()
    if data_1["follower_count"]>data_2["follower_count"]:
        return "A"
    else:
        return "B"

score = 0
game_should_continue = True
print(logo)
while game_should_continue:
    data_1=GetData()
    print("Compare A:{0}, {1},from {2}".format(data_1["name"],data_1["description"],data_1["country"]))
    # print(type(data_1))
    print(vs)
    data_2=GetData()
    
    print("Against B:{0}, {1},from {2}".format(data_2["name"],data_2["description"],data_2["country"]))
    
    answer =input("Who has more followers? Type 'A' or 'B':").upper()
    print(logo)
    if answer==CheckData(data_1,data_2):
        score+=1
        print(f"You're right! Current score: {score}.")
    else:
        print(f"Sorry, that's wrong. Final score: {score}")
        game_should_continue=False

