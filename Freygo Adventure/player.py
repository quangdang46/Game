import pygame, time
from image import *
pygame.init()


timer = 0
canJump = False

done = [True]*9
hide = False
class Player(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        self.index = 0

        self.image = player['player2']
        self.increSize(3)

        self.rect = self.image.get_rect()

        self.speed = 10
        self.speedx = 0
        self.speedy = 0

        self.onGround = False
        self.jumpCount = 0

        self.layer = 4

    def goto(self, x, y):
        self.rect.centerx = x
        self.rect.bottom = y

    def increSize(self, times):
        width = self.image.get_width()
        height = self.image.get_height()

        self.image = pygame.transform.scale(self.image, (width*times, height*times))

    def animate(self, wait):
        pass

    def move(self):
        global timer, canJump, hide
        keys = pygame.key.get_pressed()

        self.speedy += 1
        if self.speedy >= 12:
            self.speedy = 12

        self.speedx = 0
        if not hide:
            self.look('default')
        if keys[pygame.K_RIGHT] or keys[pygame.K_d]:
            self.speedx = self.speed
            self.look('right')
        if keys[pygame.K_LEFT] or keys[pygame.K_a]:
            self.speedx = -self.speed
            self.look('left')

        if (keys[pygame.K_UP] or keys[pygame.K_w]) and canJump and self.jumpCount > 0:
            self.speedy = -18
            self.jumpCount -= 1
            canJump = False

        if not keys[pygame.K_UP] and not keys[pygame.K_w]:
            canJump = True

        if keys[pygame.K_SPACE]:
            if hide == False:
                hide = True
            else:
                hide = False

    def look(self, direction):
        if direction == 'default':
            self.image = player['player2']
            self.increSize(3)
        if direction == 'left':
            self.image = player['player1']
            self.increSize(3)
        if direction == 'right':
            self.image = player['player3']
            self.increSize(3)

    def getRect(self, x, y):
        if done[0] == True:
            self.rect = self.image.get_rect()
            self.rect.x = x
            self.rect.y = y
            done[0] = False

    def switchCostume(self, costume):
        self.image = player[costume]
        self.increSize(3)

