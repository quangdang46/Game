import pygame
from animation import Animation
from image import *
pygame.init()


class Cloud(pygame.sprite.Sprite):
    def __init__(self, x, y, costume):
        super().__init__()
        self.index = 0
        self.costumes = []

        self.image = cloud[costume]
        self.increSize(4)

        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.bottom = y

        self.layer = 1

    def increSize(self, times):
        width = self.image.get_width()
        height = self.image.get_height()

        self.image = pygame.transform.scale(self.image, (width*times, height*times))

    def update(self):
        pass




