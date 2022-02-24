import random
#Step 1 
word_list = ["aardvark", "baboon", "camel"]
HANGMANPICS = ['''
  +---+
  |   |
      |
      |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
      |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
  |   |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========''']
#TODO-1 - Randomly choose a word from the word_list and assign it to a variable called chosen_word.
#TODO-2 - Ask the user to guess a letter and assign their answer to a variable called guess. Make guess lowercase.
#TODO-3 - Check if the letter the user guessed (guess) is one of the letters in the chosen_word.
print('''
  _                                             
 | |                                            
 | |__   __ _ _ __   __ _ _ __ ___   __ _ _ __  
 | '_ \ / _` | '_ \ / _` | '_ ` _ \ / _` | '_ \ 
 | | | | (_| | | | | (_| | | | | | | (_| | | | |
 |_| |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|
                     __/ |                      
                    |___/                       
''')
chosen_word=random.choice(word_list)
# print(chosen_word)
# print(len(chosen_word))
i=0
str_=list("_"*len(chosen_word))
cnt=0
check=True
while check:
  print("TEST ERROR:","".join(str_))
  guess=input("Guess enter:").lower()
  if guess not in chosen_word:
      print(HANGMANPICS[i])
      i+=1
  else:
      for k in range(len(chosen_word)):
          if chosen_word[k]==guess:
              cnt+=1
              str_[k]=guess
  if "_" not in str_:
      check=False
      print("You win")

  if cnt==len(chosen_word)-1:
      check=False
