import pygame, random

from player import Player
from platform2 import Platform
from cloud import *
from text import Text
from spikes import Spikes
from cursor import Cursor
from figure import *
from checkpoint import Checkpoint

from pygame.sprite import collide_rect, collide_mask
from pygame.color import Color

pygame.init()


window = pygame.display.set_mode((0, 0), pygame.FULLSCREEN)
pygame.display.set_caption('Game')

def reset():
    global limitScroll, camerax, cameray, mainTimer, gameOver, resetCount
    # Set all the list into empty
    ground.clear()
    cloud.clear()
    spikes.clear()
    checkpoint.clear()

    for sprite in mainSprite:
        if not sprite in curtain:
            mainSprite.remove(sprite)

    # Reset all the sprite
    player.goto(window.get_width()/2, window.get_height()/2)
    loadMap(ground, cloud, spikes, checkpoint)

    # Reset variables
    limitScroll = {'top': window.get_height() / 2 - 150, 'bottom': window.get_height() - 200,
                   'right': player.rect.right + 20, 'left': player.rect.left - 20}

    camerax = checkpointPosition
    cameray = 0
    mainTimer = 0
    gameOver = False
    resetCount += 1

    # add
    mainSprite.add(player)
    mainSprite.add(cursor)
    for sprite in ground:
        mainSprite.add(sprite)
    for sprite in spikes:
        mainSprite.add(sprite)
    for sprite in cloud:
        mainSprite.add(sprite)
    for sprite in checkpoint:
        mainSprite.add(sprite)

def openMap(level):
    f = open(r'data\\levels\\level' + str(level) + '.txt')
    return f.read()

def loadMap(listTile, listObject, listSpike, listCheckPoint):
    global mapWidth
    gridPos = 60

    mapData = []
    allRowList = openMap(1).split('\n')
    mapWidth = len(allRowList[0])*gridPos - 4223
    for row in allRowList:
        rowList = []
        for character in row:
            rowList.append(character)
        mapData.append(rowList)

    for row in range(len(mapData)):
        for column in range(len(mapData[row])):
            if mapData[row][column] == ' ':
                mapData[row][column] = '0'

    for row in range(len(mapData)):
        for column in range(len(mapData[row])):
            if mapData[row][column] == '1':
                listTile.append(Platform(column * gridPos - gridPos, row * gridPos, 'tile1'))
            if mapData[row][column] == '2':
                listTile.append(Platform(column * gridPos - gridPos, row * gridPos, 'tile2'))
            if mapData[row][column] == '3':
                listTile.append(Platform(column * gridPos - gridPos, row * gridPos, 'tile3'))
            if mapData[row][column] == '4':
                listTile.append(Platform(column * gridPos - gridPos, row * gridPos, 'tile4'))
            if mapData[row][column] == '5':
                listTile.append(Platform(column * gridPos - gridPos, row * gridPos, 'tile5'))
            if mapData[row][column] == '6':
                listTile.append(Platform(column * gridPos - gridPos, row * gridPos, 'tile6'))
            if mapData[row][column] == '7':
                listTile.append(Platform(column * gridPos - gridPos, row * gridPos, 'tile7'))
            if mapData[row][column] == '8':
                listTile.append(Platform(column * gridPos - gridPos, row * gridPos, 'tile8'))
            if mapData[row][column] == '9':
                listTile.append(Platform(column * gridPos - gridPos, row * gridPos, 'tile9'))

            if mapData[row][column] == 's': # Spikes
                listSpike.append(Spikes(column * gridPos - gridPos, row * gridPos+10))

            if mapData[row][column] == 'c':
                listCheckPoint.append(Checkpoint(column * gridPos - gridPos, row * gridPos-5, 'checkpoint1'))
                if resetCount <= 0:
                    checkpointNum.append(False)

    for cloudNum in range(0, 10):
        listObject.append(Cloud(random.randint(0, window.get_width()),
                                random.randint(0, window.get_height()/2), 'cloud' + str(random.randint(1, 4))))

    moveSprites(listTile, -120-(checkpointPosition*player.speed), -900)
    moveSprites(listSpike, -120-(checkpointPosition*player.speed), -900)
    moveSprites(listCheckPoint, -120-(checkpointPosition*player.speed), -900)

def moveSprites(spriteList, x, y):
    for sprite in spriteList:
        try:
            sprite.rect.x += x
            sprite.rect.y += y
        except:
            pass

def updatePlayer():
    global gameOver, checkpointed, checkpointPosition
    # Movement
    player.move()
    player.rect.x += player.speedx
    collide(player, player.speedx, 0)
    player.rect.y += player.speedy
    collide(player, 0, player.speedy)

    # Collision detection
    for sprite in spikes:
        if collide_rect(player, sprite):
            gameOver = True

    for sprite in checkpoint:
        if collide_rect(player, sprite) and checkpointNum[checkpoint.index(sprite)] == False:
            checkpointNum[checkpoint.index(sprite)] = True
            checkpointText.alpha = 500
            done[0] = False

        for x in range(0, len(checkpointNum)):
            if checkpointNum[x] == True:
                checkpoint[x].switchCostume('checkpoint2')
                mainSprite.add(checkpointText)
                if not done[0]:
                    checkpointText.goto(checkpoint[x].rect.centerx, checkpoint[x].rect.top - 20)
                    checkpointPosition = camerax
                    done[0] = True
                checkpointText.rect.y -= 3
                checkpointText.alpha -= 20
                checkpointText.image.set_alpha(checkpointText.alpha)
                if checkpointText.alpha <= 10:
                    mainSprite.remove(checkpointText)

def updateClouds():
    for sprite in cloud:
        if sprite.rect.right < 0:
            sprite.rect.left = window.get_width()-1
        if sprite.rect.left > window.get_width():
            sprite.rect.right = 1

def displayText(text, x, y):
    font = pygame.font.SysFont('comicsansms', 30)
    t = font.render(text, False, (0, 0, 0))
    window.blit(t, (x, y))

def collide(sprite, speedx, speedy):
    for tile in ground:
        if sprite == player:
            if collide_rect(player, tile):
                if speedy > 0: # move down
                    sprite.rect.bottom = tile.rect.top
                    sprite.speedy = 0
                    sprite.onGround = True
                    sprite.jumpCount = 2
                if speedy < 0: # move up
                    sprite.rect.top = tile.rect.bottom
                    sprite.speedy = 0
                if speedx > 0: # move right
                    sprite.rect.right = tile.rect.left
                if speedx < 0: # move left
                    sprite.rect.left = tile.rect.right

def changeCursor(cursor):
    mx, my = pygame.mouse.get_pos()
    newCursor = pygame.image.load(cursor).convert()
    newCursor.set_colorkey((0, 0, 0))
    window.blit(newCursor, (mx, my))

def setScrolling():
    global camerax, cameray
    if player.rect.right >= limitScroll['right'] and player.speedx > 0 and camerax < mapWidth:
        moveCamera(player.speedx, 0)
        camerax += 1
    if player.rect.left <= limitScroll['left'] and player.speedx < 0 and camerax > 0:
        moveCamera(player.speedx, 0)
        camerax -= 1

def moveCamera(speedx, speedy):
    for sprite in mainSprite:
        if (not sprite in cloud) and not sprite == cursor and not sprite in curtain:
            sprite.rect.x -= speedx
            sprite.rect.y -= speedy

    for sprite in cloud:
        sprite.rect.x -= speedx/3
        sprite.rect.y -= speedy/3

def setAllSpriteLayers():
    for sprite in cloud:
        mainSprite.change_layer(sprite, sprite.layer)
    for sprite in checkpoint:
        mainSprite.change_layer(sprite, 2)
    for sprite in ground:
        mainSprite.change_layer(sprite, sprite.layer)
    mainSprite.change_layer(player, player.layer)
    mainSprite.change_layer(cursor, 5)
    for sprite in curtain:
        mainSprite.change_layer(sprite, 6)

def takeSreenShot():
    if mainTimer >= random.randint(12000, 120000):
        pygame.image.save(window, 'data\\images\\Screenshot.png')

def hideScreen():
    if not collide_rect(curtain[0], curtain[1]):
        curtain[0].rect.y += 15
        curtain[1].rect.y -= 15

def showScreen():
    if curtain[0].rect.bottom >= 0 and curtain[1].rect.top <= window.get_height():
        curtain[0].rect.y -= 15
        curtain[1].rect.y += 15


# ======================================Sprites-----------------------------------
mainSprite = pygame.sprite.LayeredUpdates()
player = Player()
cursor = Cursor()
ground = []
cloud = []
spikes = []
checkpoint = []

curtain = []
curtain.append(Square(0, -window.get_height()/2-50, window.get_width(), window.get_height()/2+50, (0, 0, 0)))
curtain.append(Square(0, window.get_height(), window.get_width(), window.get_height()/2+50, (0, 0, 0)))
for sprite in curtain:
    mainSprite.add(sprite)


# ---------------------------------Variables-------------------------------
mainTimer = 0
limitScroll = {'top': None, 'bottom': None,
               'right': None, 'left': None}
camerax = 0
cameray = 0
mapWidth = 0

gameOver = False

checkpointText = Text('Checkpoint!', Color('dark green'), 'comicsansms', 30, 0, 0)
done = [False]*9

checkpointed = False
checkpointPosition = 0
checkpointNum = []

resetCount = 0


# Main loop
def run():
    global mainTimer, gameOver
    running = True
    done = False

    timer = [0]*9
    while running: #----------------------------------Loop-------------------------------------
        if not gameOver:
            timer[0] = 0
            done = False
            showScreen()
            # Update sprites
            updatePlayer()
            setScrolling()
            updateClouds()
        else:
            timer[0] += 1
            player.switchCostume('player4')
            player.rect.y += player.speedy
            if not done:
                player.speedy = -16
                done = True
            player.speedy += 1
            if timer[0] >= 50:
                hideScreen()
                if timer[0] >= 100:
                    reset()

        # Set all sprite's layer
        setAllSpriteLayers()

        # draw all sprites
        window.fill((47, 240, 250))
        mainSprite.draw(window)
        mainSprite.update()

        # Take a screenshot at random time and save it in data
        takeSreenShot()

        # Timer
        mainTimer += 1

        # Text
        displayText(str(checkpointNum), 0, 0)

        # Events
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

            if event.type == pygame.KEYUP:
                if event.key == pygame.K_r:
                    reset()

        pygame.display.update()
        pygame.time.Clock().tick(100)

    close()

def close():
    pygame.quit()
    quit()


# main
if __name__ == '__main__':
    reset()
    run()

