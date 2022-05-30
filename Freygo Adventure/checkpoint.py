import pygame
from image import checkpoint
pygame.init()


class Checkpoint(pygame.sprite.Sprite):
    def __init__(self, x, y, costume):
        super().__init__()
        self.switchCostume(costume)

        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = y

        self.position = 0

    def increSize(self, times):
        width = self.image.get_width()
        height = self.image.get_height()

        self.image = pygame.transform.scale(self.image, (width*times, height*times))

    def switchCostume(self, costume):
        self.image = checkpoint[costume]
        self.increSize(3)


