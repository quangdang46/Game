import pygame
from image import tile1
pygame.init()


class Platform(pygame.sprite.Sprite):
    def __init__(self, x, y, costume):
        super().__init__()
        self.image = tile1[costume]
        self.increSize(3)

        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = y

        self.layer = 3

    def increSize(self, times):
        width = self.image.get_width()
        height = self.image.get_height()

        self.image = pygame.transform.scale(self.image, (width*times, height*times))




