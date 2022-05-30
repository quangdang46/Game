import pygame
pygame.init()


class Text(pygame.sprite.Sprite):
    def __init__(self, text, color, font, size, x, y):
        super().__init__()
        self.fontStyle = pygame.font.SysFont(font, size)
        self.image = self.fontStyle.render(text, False, color)

        self.font = font
        self.size = size
        self.color = color

        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = y

        self.alpha = 500

    def updateText(self, text):
        self.fontStyle = pygame.font.SysFont(self.font, self.size)
        self.image = self.fontStyle.render(text, False, self.color)

    def goto(self, centerx, centery):
        self.rect.centerx = centerx
        self.rect.centery = centery

