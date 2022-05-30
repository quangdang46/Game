import pygame
from image import cursor
pygame.init()


class Cursor(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        self.switchCostume('cursor1')
        self.rect = self.image.get_rect()
        self.layer = 4

    def update(self):
        mx, my = pygame.mouse.get_pos()
        mouse = pygame.mouse.get_pressed()
        pygame.mouse.set_visible(False)
        self.switchCostume('cursor1')
        if mouse[0]:
            self.switchCostume('cursor2')
        if mouse[2]:
            self.switchCostume('cursor3')
        if mouse[0] and mouse[2]:
            self.switchCostume('cursor4')

        self.rect.x = mx
        self.rect.y = my

    def increSize(self, times):
        width = self.image.get_width()
        height = self.image.get_height()

        self.image = pygame.transform.scale(self.image, (width*times, height*times))

    def switchCostume(self, costume):
        self.image = cursor[costume]
        self.increSize(3)

