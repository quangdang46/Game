import pygame
pygame.init()


class Spikes(pygame.sprite.Sprite):
    def __init__(self, x, y):
        super().__init__()
        self.image = pygame.image.load(r'data\\images\\spike.png').convert()
        self.image.set_colorkey((0, 0, 0))
        self.increSize(4)

        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = y

    def increSize(self, times):
        width = self.image.get_width()
        height = self.image.get_height()

        self.image = pygame.transform.scale(self.image, (width*times, height*times))

