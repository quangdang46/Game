import pygame
pygame.init()


timer = 0
class Animation:
    def __init__(self, image, costumeList):
        self.images = costumeList
        self.index = 0
        self.animating = True
        self.image = self.images[self.index]

    def start(self, wait):
        pass


