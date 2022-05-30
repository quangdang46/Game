import pygame
pygame.init()

pygame.display.set_mode((500, 500))
pygame.display.iconify()

sourceGround1 = pygame.image.load('data\\images\\ground1.png')
sourcePlayer = pygame.image.load('data\\images\\player.png')
sourceCloud = pygame.image.load('data\\images\\cloud.png')
sourceCursor = pygame.image.load('data\\images\\cursor.png')
sourceCheckpoint = pygame.image.load(r'data\\images\\checkpoint.png')


player = {'player1': sourcePlayer.subsurface((0, 0, 19, 19)).convert(),
          'player2': sourcePlayer.subsurface((20, 0, 19, 19)).convert(),
          'player3': sourcePlayer.subsurface((40, 0, 19, 19)).convert(),
          'player4': sourcePlayer.subsurface((60, 0, 19, 19)).convert()}

tile1 = {'tile1': sourceGround1.subsurface((0, 0, 20, 20)).convert(),
         'tile2': sourceGround1.subsurface((21, 0, 20, 20)).convert(),
         'tile3': sourceGround1.subsurface((42, 0, 20, 20)).convert(),
         'tile4': sourceGround1.subsurface((0, 21, 20, 20)).convert(),
         'tile5': sourceGround1.subsurface((21, 21, 20, 20)).convert(),
         'tile6': sourceGround1.subsurface((42, 21, 20, 20)).convert(),
         'tile7': sourceGround1.subsurface((0, 42, 20, 20)).convert(),
         'tile8': sourceGround1.subsurface((21, 42, 20, 20)).convert(),
         'tile9': sourceGround1.subsurface((42, 42, 20, 20)).convert()}

cloud = {'cloud1': sourceCloud.subsurface((0, 0, 27, 13)).convert(),
         'cloud2': sourceCloud.subsurface((28, 0, 19, 12)).convert(),
         'cloud3': sourceCloud.subsurface((0, 14, 23, 13)).convert(),
         'cloud4': sourceCloud.subsurface((28, 15, 16, 12)).convert()}

cursor = {'cursor1': sourceCursor.subsurface((0, 0, 12, 11)),
          'cursor2': sourceCursor.subsurface((13, 0, 12, 11)),
          'cursor3': sourceCursor.subsurface((26, 0, 12, 11)),
          'cursor4': sourceCursor.subsurface((39, 0, 12, 11))}

checkpoint = {'checkpoint1': sourceCheckpoint.subsurface((0, 0, 6, 28)),
              'checkpoint2': sourceCheckpoint.subsurface((7, 0, 6, 28))}

for spriteNum in range(1, len(player)+1):
    player['player' + str(spriteNum)].set_colorkey((0, 0, 0))

for spriteNum in range(1, len(cloud)+1):
    cloud['cloud' + str(spriteNum)].set_colorkey((0, 0, 0))

for spriteNum in range(1, len(cursor)):
    cursor['cursor' + str(spriteNum)].set_colorkey((0, 0, 0))

for spriteNum in range(1, len(checkpoint)):
    checkpoint['checkpoint' + str(spriteNum)].set_colorkey((0, 0, 0))


