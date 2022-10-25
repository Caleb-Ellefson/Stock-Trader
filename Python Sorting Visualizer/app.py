import pygame
import random
pygame.init()

class DrawInformation:
    BLACK = 0, 0, 0,
    WHITE = 255, 255, 255
    GREEN = 0, 255, 0
    RED = 255, 0, 0
    GRAY = 128, 128, 128
    BACKGROUND_COLOR = WHITE

    def __init__(self, width, height, lst):
        self.width = width
        self.height = height

        #create the pygame window
        self.window = pygame.display.set_mode((width, height))