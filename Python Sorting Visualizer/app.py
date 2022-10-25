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

    SIDE_PAD = 100
    TOP_PAD = 150

    #Pygame window
    def __init__(self, width, height, lst):
        self.width = width
        self.height = height

        #create the pygame window
        self.window = pygame.display.set_mode((width, height))
        pygame.display.set_caption("Sorting Algroith Visualization")
        self.set_list(lst)

    #Bar attribute
    def set_list(self, lst):
        self.lst = lst
        self.min_val = min(lst)
        self.max_val = max(lst)

        #Find width of each bar
        self.block_width = round((self.width - self.SIDE_PAD) / len(lst))
        #Find the height of each bar
        self.block_height = round((self.height - self.TOP_PAD) / (self.max_val - self.min_val))

        #int divide to get a whole number
        self.start_x = self.SIDE_PAD // 2




